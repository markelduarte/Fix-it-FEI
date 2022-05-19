#include "ChildActor.h"

ChildActor::ChildActor(Game* game, float x, float y,
	float w, float h)
	:Actor(game, true)
{
	SetPosition(Vector2(x, y));
	SetWidth(w);
	SetHeight(h);
}

void ChildActor::UpdateActor(float deltaTime)
{

}
