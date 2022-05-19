#include "Enemy.h"
#include "AnimSpriteComponent.h"
#include "Game.h"

Enemy::Enemy(Game* game, bool timeWarp, float speed)
	:Projectile(game, timeWarp, speed)
{
	game->AddDuck(this);
	AnimSpriteComponent* asc = new AnimSpriteComponent(this);
	std::vector<SDL_Texture*> anims = {
		game->GetTexture("Assets/Pato1.png"),
		game->GetTexture("Assets/Pato2.png"),
	};

	asc->SetAnimTextures(anims);
	SetScale(1.5);
	mWidth = asc->GetTexWidth() * mScale;
	mHeight = asc->GetTexHeight() * mScale;
}

void Enemy::UpdateActor(float deltaTime)
{
	Projectile::UpdateActor(deltaTime);
}
