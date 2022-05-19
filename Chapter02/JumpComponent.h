#pragma once
#include "Component.h"

class JumpComponent :
    public Component
{
public:
    JumpComponent(class Felix* owner, 
        float g, 
        int updateOrder = 100);
    ~JumpComponent();

    void Fall();
    void EndFall() { mIsFalling = false; }
    bool IsFalling() const { return mIsFalling; }

    void Jump();
    void EndJump() { mIsJumping = false; }
    bool IsJumping() const { return mIsJumping; }

    void Update(float deltaTime) override;

    // todo: fix dependency on Felix
    class Felix* GetFelix() const { return mFelix; }

private:
    class Felix* mFelix;

    bool mIsJumping;
    bool mIsFalling;

    float mGravity;

    Vector2 mFallPos;
};
