#include "Projectile.h"
#include "AnimSpriteComponent.h"
#include "Game.h"


Projectile::Projectile(Game* game, bool timeWarp, float speed)
	:Actor(game, timeWarp),
	mSpeed(speed)

{
	//SpriteComponent* sc = new SpriteComponent(this);
	//SDL_Texture* texture = game->GetTexture("Assets/Laser.png");
	//sc->SetTexture(texture);

	//mCollider = new CollideComponent(this);

	//mWidth = sc->GetTexWidth();
	//mHeight = sc->GetTexHeight();
}

void Projectile::UpdateActor(float deltaTime) {
	Actor::UpdateActor(deltaTime);
	Vector2 pos = GetPosition();

	pos.x += mSpeed * deltaTime;

	if ((mSpeed > 0 && pos.x > GetGame()->GetWindowWidth()) || 
		(mSpeed < 0 && pos.x < 0)) {
		SetState(State::EDead);
		if (mSpeed < 0) {
			GetGame()->IncrementScore();
		}
	}

	SetPosition(pos);
}