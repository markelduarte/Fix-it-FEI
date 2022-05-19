#include "CollideComponent.h"
#include "Ship.h"
#include "Enemy.h"

#include "Game.h"

CollideComponent::CollideComponent(class Actor* owner, int updateOrder)
	: Component(owner, updateOrder)
{
	//printf("Collider.w = %.2f\n", owner->GetWidth());

	mOwner->GetGame()->AddFloorCollider(this);

}
CollideComponent::~CollideComponent() 
{
	mOwner->GetGame()->RemoveFloorCollider(this);
}

bool CollideComponent::Collide(Actor* other) 
{
	if (other == mOwner) {
		return false;
	}

	Vector2 otherPos = other->GetPosition();
	float otherHeight = other->GetHeight();
	float otherWidth = other->GetWidth();

	Vector2 ownerPos = mOwner->GetPosition();
	float ownerHeight = mOwner->GetHeight();
	float ownerWidth = mOwner->GetWidth();

	return ( (ownerPos.x - ownerWidth / 2.0f < otherPos.x + otherWidth / 2.0f &&
		      otherPos.x - otherWidth / 2.0f < ownerPos.x + ownerWidth / 2.0f) &&
		     (ownerPos.y - ownerHeight/ 2.0f < otherPos.y + otherHeight / 2.0f &&
			  otherPos.y - otherHeight/ 2.0f < ownerPos.y + ownerHeight / 2.0f));

}


