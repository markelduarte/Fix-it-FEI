#pragma once
#include "Projectile.h"
class Enemy :
    public Projectile
{
public:
    Enemy(class Game* game, bool timeWarp = true, float speed = -100.0f);
    void UpdateActor(float deltaTime) override;
    //float GetRightSpeed() const { return mRightSpeed; }
    //float GetDownSpeed() const { return mDownSpeed; }
    
private:
    //float mRightSpeed;
    //float mDownSpeed;
};
