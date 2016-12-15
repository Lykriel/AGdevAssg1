#include "Eyeball.h"
#include "../EntityManager.h"
#include "GraphicsManager.h"
#include "RenderHelper.h"
#include "../PlayerInfo/PlayerInfo.h"

EyeBall::EyeBall()
    :m_state(EYE_STATES::Patrol)
    , m_AttackTarget(Vector3(0, 0, 0))
    , m_Health(10)
    , aim(false)
    , AimTimer(0.f)
    , attackTimer(0.f)
    , targetSelected(false)
{

}

EyeBall::~EyeBall()
{

}

void EyeBall::Update(double dt)
{
    viewVector = (target - position).Normalized();
    //position += viewVector * (float)m_dSpeed * (float)dt * 2;

    //Constrain the position
    Constrain();
    StateUpdate(dt);
    //target = CPlayerInfo::GetInstance()->GetPos();
   /* if (!aim)
    {
        position += viewVector *(float)m_dSpeed * (float)dt;
    }*/
}
float EyeBall::DistBetwVect(Vector3 point1, Vector3 point2)
{
    return sqrt(
        (point1.x - point2.x)*(point1.x - point2.x)
        +
        (point1.y - point2.y)*(point1.y - point2.y)
        +
        (point1.z - point2.z)*(point1.z - point2.z)
        );
}

void EyeBall::Render(void)
{
    MS& modelStack = GraphicsManager::GetInstance()->GetModelStack();
    modelStack.PushMatrix();
    modelStack.Translate(position.x, position.y, position.z);
    modelStack.Scale(scale.x, scale.y, scale.z);
    RenderHelper::RenderMesh(MeshBuilder::GetInstance()->GetMesh("Obj_MobEye"));
    modelStack.PopMatrix();
}

void EyeBall::StateUpdate(double dt)
{
    Vector3 CurrPlayerPos = CPlayerInfo::GetInstance()->GetPos();
    Vector3 DetectRange = position + Vector3(25, 25, 25);
   
    //patrol state
    if (m_state == EYE_STATES::Patrol)
    {
        if (DistBetwVect(position, CPlayerInfo::GetInstance()->GetPos()) < 25)
        {
            m_state = EYE_STATES::Target;
        }
        else
        {
            if (!targetSelected)
            {
                target.x = (float)(((rand()) % 999) + (-499));
                target.z = (float)(((rand()) % 999) + (-499));
                targetSelected = true;                
            }
            position += viewVector *(float)m_dSpeed * (float)dt;
            if (DistBetwVect(position, target) < 5)
            {
                targetSelected = false;
            }
            m_dSpeed = 20.f;
        }
    }
   
    //target state
    if (m_state == EYE_STATES::Target)
    {
        aim = true;
        AimTimer += (float)dt;
        if (AimTimer >= 1)
        {
            target = CPlayerInfo::GetInstance()->GetPos();
            AimTimer = 0.f;
            aim = false;
            m_state = EYE_STATES::Attack;
        }

    }
    //attack state not functional yet
    if (m_state == EYE_STATES::Attack)
    {
        m_dSpeed = 100.f;
        attackTimer += (float)dt;
        position += viewVector *(float)m_dSpeed * (float)dt;
        
        if (DistBetwVect(position, target) < 5)
        {
            if (DistBetwVect(position, CPlayerInfo::GetInstance()->GetPos()) > 25)
            {
                m_dSpeed = 20.f;
                m_state = EYE_STATES::Patrol;
            }
            else
            {
                m_state = EYE_STATES::Target;
            }           
        }       
    }
}