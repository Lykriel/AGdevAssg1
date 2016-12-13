#ifndef EYEBALL_H
#define EYEBALL_H
#include "Enemy.h"

class EyeBall : public CEnemy
{
public:
    enum EYE_STATES
    {
        CHILD_STATE,
        Patrol,
        Target,
        Attack,
    };

    EyeBall();
    ~EyeBall();

    /*void SoloUpdate(double dt);
    void ChildUpdate(double dt);*/
    void Update(double dt = 0.0333f);
    void Render(void);
private:
    EYE_STATES m_state;
    Vector3 m_AttackTarget;
    int m_Health;
    int m_Speed;


};

#endif