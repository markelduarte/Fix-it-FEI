#include "Actor.h"
#include "Felix.h"
#include "JumpComponent.h"

JumpComponent::JumpComponent(Felix* owner, 
	float g,
	int updateOrder)
	:Component(owner, updateOrder), 
	mGravity(g),
	mIsJumping(false),
	mIsFalling(false),
	mFelix(owner)
{
	
}

JumpComponent::~JumpComponent()
{
	
}

void JumpComponent::Jump() 
{
	if (!mIsJumping && !mIsFalling)
	{
		Felix* felix = GetFelix();

		felix->SetDownSpeed(-3.5 * felix->GetHeight());

		mIsJumping = true;
	}
}

void JumpComponent::Fall()
{
	if (!mIsJumping && !mIsFalling)
	{
		Felix* felix = GetFelix();
		felix->SetFallWindow();
		//mFallPos = felix->GetPosition();

		felix->SetDownSpeed(0);

		mIsFalling = true;
	}
}

void JumpComponent::Update(float deltaTime) 
{
	Felix* felix = GetFelix();
	//Vector2 currentPos = felix->GetPosition();
	//float height = felix->GetHeight();

	if (mIsJumping || mIsFalling)
	{
		float downSpeed = felix->GetDownSpeed();

		felix->SetDownSpeed(downSpeed + mGravity * deltaTime);
	}

	//if (mIsFalling && currentPos.y > mFallPos.y + height / 3.0f) 
	//{
	//	mIsFalling = false;
	//	mIsJumping = true;
	//}
}
