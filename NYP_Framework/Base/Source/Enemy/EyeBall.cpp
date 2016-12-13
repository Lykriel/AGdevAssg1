#include "Eyeball.h"
#include "../EntityManager.h"
#include "GraphicsManager.h"
#include "RenderHelper.h"

EyeBall::EyeBall()
    :m_state(EYE_STATES::Patrol)
    , m_AttackTarget(Vector3(0,0,0))
    , m_Health(10)
    , m_Speed(10)
{

}

EyeBall::~EyeBall()
{

}

void EyeBall::Update(double dt)
{
    Vector3 viewVector = (target - position).Normalized();
    position += viewVector * (float)m_dSpeed * (float)dt;

    //Constrain the position
    Constrain();

    //Update the target
    if (position.z > 400.0f)
    	target.z = position.z* - m_Speed;
    else if (position.z < -400.0f)
    	target.z = position.z * - m_Speed;
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