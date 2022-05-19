#include "Floor.h"
#include "Window.h"
#include "GridComponent.h"


Floor::Floor(Game* game, float x, float y, float w, float h)
	:ChildActor(game, x, y, w, h)
{
	//printf("Floor.w = %.2f\n", mWidth);

	mGrid = new GridComponent<Window>(this, 5, 0.0, 0.01, 0.05, true, 70);

	mCollider = new CollideComponent(this);
}

void Floor::UpdateActor(float deltaTime)
{

}
