#pragma once
#include "Actor.h"
#include "CollideComponent.h"
class Projectile :
    public Actor
{
public:
    Projectile(class Game* game, bool timeWarp = true, float speed = 10.0f);
    void UpdateActor(float deltaTime) override;
    float GetSpeed() const { return mSpeed; }

private:
    float mSpeed;
    CollideComponent* mCollider;
};

