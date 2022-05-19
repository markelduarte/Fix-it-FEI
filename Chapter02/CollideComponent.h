#pragma once
#include "Component.h"
class CollideComponent :
    public Component
{
public:
    CollideComponent(class Actor* owner, int updateOrder = 100);
    ~CollideComponent();

    virtual bool Collide(Actor* other);
};

