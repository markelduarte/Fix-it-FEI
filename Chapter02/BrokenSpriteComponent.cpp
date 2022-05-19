#include "BrokenSpriteComponent.h"
#include "Actor.h"
#include "Game.h"

BrokenSpriteComponent::BrokenSpriteComponent(Actor* owner,
	int drawOrder)
	:ChildSpriteComponent(owner, drawOrder)
	,mHowBroken(0)
{
	mOwner->GetGame()->AddBrokenWindow(this);
}

BrokenSpriteComponent::~BrokenSpriteComponent()
{
	mOwner->GetGame()->RemoveBrokenWindow(this);
}

void BrokenSpriteComponent::Update(float deltaTime)
{
	SpriteComponent::Update(deltaTime);

	SetTexture(mBrokenTextures[mHowBroken]);
}

void BrokenSpriteComponent::SetBrokenTextures(const std::vector<SDL_Texture*>& textures)
{
	mBrokenTextures = textures;

	// for testing only
	mHowBroken = mBrokenTextures.size() - 1;
	SetTexture(mBrokenTextures[mHowBroken]);
}
