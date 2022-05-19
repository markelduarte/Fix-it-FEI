#pragma once
#include "ChildActor.h"
#include "CollideComponent.h"
#include "GridComponent.h"
#include "Window.h"

class Floor :
    public ChildActor
{
public:
    Floor(Game* game, float x, float y, float w, float h);

    void UpdateActor(float deltaTime) override;

protected:

    GridComponent<Window>* mGrid;
    CollideComponent* mCollider;

};

