#include "Actor.h"
#include "ChildSpriteComponent.h"

ChildSpriteComponent::ChildSpriteComponent(class Actor* owner,
	int drawOrder)
	:SpriteComponent(owner, drawOrder)
{
}

void ChildSpriteComponent::Draw(SDL_Renderer* renderer)
{
	SDL_Rect r;
	r.w = static_cast<int>(mParentSize.x);
	r.h = static_cast<int>(mParentSize.y);

	Vector2 ownerPos = mOwner->GetPosition();

	r.x = static_cast<int>(ownerPos.x - r.w / 2);
	r.y = static_cast<int>(ownerPos.y - r.h / 2);

	SDL_RenderCopy(renderer,
		mTexture,
		nullptr,
		&r);
}
