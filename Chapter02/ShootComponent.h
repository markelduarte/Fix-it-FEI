#pragma once
#include "Component.h"
#include "Enemy.h"
#include "Projectile.h"

template<class P>
class ShootComponent :
    public Component
{
public:
    ShootComponent(class Actor* owner, int updateOrder = 100);
    ~ShootComponent();

    virtual void Shoot();

protected:
    
};

template class ShootComponent<Projectile>;
template class ShootComponent<Enemy>;
