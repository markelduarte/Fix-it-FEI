#include "AnimSpriteComponent.h"
#include "Ralph.h"
#include "Game.h"

Ralph::Ralph(Game* game)
	:Actor(game, false)
	,mRightSpeed(0.0f)
	,mDownSpeed(0.0f)
	,mAnimState(AnimState::Walking)
	,mFallWindow(nullptr)
	,mCurrentWindow(nullptr)
{
	mAsc = new AnimSpriteComponent(this);

	mAnimsWalk = {
		game->GetTexture("Assets/Ralph1.png"),
		game->GetTexture("Assets/Ralph2.png"),
		game->GetTexture("Assets/Ralph3.png"),
	};

	mAnimsJump = {
		game->GetTexture("Assets/Character07.png"),
		game->GetTexture("Assets/Character08.png"),
		game->GetTexture("Assets/Character09.png"),
		game->GetTexture("Assets/Character10.png"),
		game->GetTexture("Assets/Character11.png"),
		game->GetTexture("Assets/Character12.png"),
		game->GetTexture("Assets/Character13.png"),
		game->GetTexture("Assets/Character14.png"),
		game->GetTexture("Assets/Character15.png"),
	};

	mAnimsWreck = {
		game->GetTexture("Assets/Ralph4.png"),
		game->GetTexture("Assets/Ralph5.png"),
		game->GetTexture("Assets/Ralph6.png"),
		game->GetTexture("Assets/Ralph7.png"),
		game->GetTexture("Assets/Ralph8.png"),
		game->GetTexture("Assets/Ralph9.png"),
		game->GetTexture("Assets/Ralph10.png"),
		game->GetTexture("Assets/Ralph11.png"),
		game->GetTexture("Assets/Ralph8.png"),
		game->GetTexture("Assets/Ralph1.png"),
	};

	mAsc->SetAnimTextures(mAnimsWalk);

	mWidth = mAsc->GetTexWidth();
	mHeight = mAsc->GetTexHeight();

	//mJumper = new JumpComponent(this, 5 * mHeight);

	mIsWreck = false;
	mCoolDown = 0;
}

void Ralph::UpdateActor(float deltaTime)
{
	Actor::UpdateActor(deltaTime);

	if (!mJumper->IsJumping() &&
		mAnimState == AnimState::Jumping)
	{
		mAnimState = AnimState::Walking;
	}

	if (mIsWreck)
	{
		mIsWreck = false;

		if (mCoolDown < 1)
		{
			mCoolDown = 10;

			//mFixer->Fix();
		}
		else mCoolDown -= 1;
	}
	else if (mCoolDown > 0) mCoolDown -= 1;

	Vector2 pos = GetPosition();
	pos.x += mRightSpeed * deltaTime;
	pos.y += mDownSpeed * deltaTime;

	float wWidth  = GetGame()->GetWindowWidth();
	float wHeight = GetGame()->GetWindowHeight();

	auto colliders = GetGame()->GetColliders();

	bool collidedAny = false;

	// stop at each floor
	for (CollideComponent* c : colliders)
	{
		if (c != mFallWindow)
		{
			if (c->Collide(this) && mDownSpeed >= 0)
			{
				Vector2 cPos = c->GetOwner()->GetPosition();
				float cHeight = c->GetOwner()->GetHeight();

				float cBottom = cPos.y + cHeight / 2.0f;

				if ((pos.y < cBottom) &&
					(pos.y > cBottom - GetHeight() / 2.0f))
				{
					pos.y = cBottom - GetHeight() / 2.0f;

					collidedAny = true;
					mDownSpeed = 0;

					mJumper->EndFall();
					mJumper->EndJump();

					mCurrentWindow = c;
					mFallWindow = nullptr;
				}
			}
		}

		if (!collidedAny)
		{
			mCurrentWindow = nullptr;
			mJumper->Fall();
		}
	}

	if (pos.x < GetWidth() / 2.0f)
	{
		pos.x = GetWidth() / 2.0f;
	}
	else if (pos.x > wWidth - GetWidth() / 2.0f)
	{
		pos.x = wWidth - GetWidth() / 2.0f;
	}

	/*if (pos.y < GetHeight() / 2.0f)
	{
		pos.y = GetHeight() / 2.0f;
	}
	else */if (pos.y > wHeight - GetHeight() / 2.0f)
	{
		pos.y = wHeight - GetHeight() / 2.0f;

		mJumper->EndFall();
		mJumper->EndJump();
	}

	SetPosition(pos);
}

void Ralph::ProcessKeyboard(const uint8_t* state)
{
	mRightSpeed = 0.0f;
	
	// todo: account for gravity on jumps
	//mDownSpeed = 0.0f;

	// left/ right
	if (state[SDL_SCANCODE_A])
	{
		mRightSpeed -= 250.0f;

		if (!mJumper->IsJumping() && 
			mAnimState != AnimState::Walking)
		{
			mAsc->SetAnimTextures(mAnimsWalk);
			mAnimState = AnimState::Walking;
		}
	}
	if (state[SDL_SCANCODE_D])
	{
		mRightSpeed += 250.0f;

		if (!mJumper->IsJumping() && 
			mAnimState != AnimState::Walking)
		{
			mAsc->SetAnimTextures(mAnimsWalk);
			mAnimState = AnimState::Walking;
		}
	}

	// up/ down
	if (state[SDL_SCANCODE_W])
	{
		mJumper->Jump();

		//mDownSpeed -= 250.0f;
		
		if (mAnimState != AnimState::Jumping)
		{
			//mAsc->SetAnimTextures(mAnimsJump);
			mAnimState = AnimState::Jumping;
		}
	}
	if (state[SDL_SCANCODE_S])
	{
		// todo: fall
		mJumper->Fall();
		// or squat

		//mDownSpeed += 250.0f;

		if (mAnimState != AnimState::Jumping)
		{
			//mAsc->SetAnimTextures(mAnimsJump);
			mAnimState = AnimState::Jumping;
		}
	}

	if (state[SDL_SCANCODE_P])
	{
		//mIsFixing = true;
		//mFixer->Fix();

		if (mAnimState != AnimState::Wreck)
		{
			mAsc->SetAnimTextures(mAnimsWreck);
			mAnimState = AnimState::Wreck;
		}
	}

	// Time warp
	if (state[SDL_SCANCODE_T])
	{
		GetGame()->SetTimeWarp(true);
	}
}
