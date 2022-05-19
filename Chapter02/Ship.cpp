// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include "Ship.h"
#include "AnimSpriteComponent.h"
#include "Game.h"
#include "Projectile.h"
#include "ShootComponent.h"

Ship::Ship(Game* game)
	:Actor(game, false)
	,mRightSpeed(0.0f)
	,mDownSpeed(0.0f)
{
	// Create an animated sprite component for the Ship using images of the project
	AnimSpriteComponent* asc = new AnimSpriteComponent(this);
	std::vector<SDL_Texture*> anims = {
		game->GetTexture("Assets/Ship01.png"),
		game->GetTexture("Assets/Ship02.png"),
		game->GetTexture("Assets/Ship03.png"),
		game->GetTexture("Assets/Ship04.png"),
	};
	//set the textures to the Ship vector of animated sprites
	asc->SetAnimTextures(anims);

	mWidth = asc->GetTexWidth();
	mHeight = asc->GetTexHeight();

	mShooter = new ShootComponent<Projectile>(this);
	mIsShooting = false;
	mCoolDown = 0;
}

//update the Ship following modifications made by the ProcessKeyboard
void Ship::UpdateActor(float deltaTime)
{
	Actor::UpdateActor(deltaTime);
	
	if (mIsShooting)
	{
		mIsShooting = false;

		if (mCoolDown < 1)
		{
			mCoolDown = 10;

			mShooter->Shoot();
		}
		else mCoolDown -= 1;
	}
	else if (mCoolDown > 0) mCoolDown -= 1;

	// Update position based on speeds and delta time
	Vector2 pos = GetPosition();
	pos.x += mRightSpeed * deltaTime;
	pos.y += mDownSpeed * deltaTime;

	float wWidth = GetGame()->GetWindowWidth();
	float wHeight = GetGame()->GetWindowHeight();

	// Restrict position to left half of screen
	if (pos.x < GetWidth() / 2.0f)
	{
		pos.x = GetWidth() / 2.0f;
	}
	else if (pos.x > wWidth / 2.0f)
	{
		pos.x = wWidth / 2.0f;
	}
	if (pos.y < GetHeight() / 2.0f)
	{
		pos.y = GetHeight() / 2.0f;
	}
	else if (pos.y > wHeight - GetHeight() / 2.0f)
	{
		pos.y = wHeight - GetHeight() / 2.0f;
	}

	SetPosition(pos);
}

//Get inputs by Keyboard
//this method will change the speed of the Ship
//Remember that the speed is given by some amount of pixels drawn in a given delta time
void Ship::ProcessKeyboard(const uint8_t* state)
{
	mRightSpeed = 0.0f;
	mDownSpeed = 0.0f;
	// right/left
	if (state[SDL_SCANCODE_D])
	{
		mRightSpeed += 250.0f;
	}
	if (state[SDL_SCANCODE_A])
	{
		mRightSpeed -= 250.0f;
	}
	// up/down
	if (state[SDL_SCANCODE_S])
	{
		mDownSpeed += 300.0f;
	}
	if (state[SDL_SCANCODE_W])
	{
		mDownSpeed -= 300.0f;
	}

	// shoot
	if (state[SDL_SCANCODE_P])
	{
		mIsShooting = true;
		//mShooter->Shoot();
	}

	//Time Warp
	if (state[SDL_SCANCODE_T])
	{
		GetGame()->SetTimeWarp(true);
	}
}
