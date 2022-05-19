#pragma once

#include "ChildActor.h"
#include "Floor.h"
#include "GridComponent.h"

class Building :
    public ChildActor
{
public:
    Building(Game* game, float x, float y, float w, float h);

    void UpdateActor(float deltaTime) override;

protected:
    GridComponent<Floor>* mGrid;
};

