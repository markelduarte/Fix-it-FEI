
#include "Actor.h"
#include "Component.h"
#include "Game.h"
#include "Projectile.h"
#include "ShootComponent.h"

template<class P>
ShootComponent<P>::ShootComponent(class Actor* owner, int updateOrder)
	:Component(owner, updateOrder)
{
	// todo
	//mOwner->GetGame()->AddShot(this);
}

template<class P>
ShootComponent<P>::~ShootComponent()
{

}

template<class P>
void ShootComponent<P>::Shoot()
{
	// Create ship's projectile
	P* p = new P(mOwner->GetGame(), mOwner->IsAffectedByTimeWarp());

	float pWidth = p->GetWidth();
	float oWidth = mOwner->GetWidth();

	Vector2 ship_pos = mOwner->GetPosition();

	p->SetPosition(Vector2(ship_pos.x + pWidth/2.0f + oWidth/2.0f, ship_pos.y));

	//p->SetScale(1.5f);
};
