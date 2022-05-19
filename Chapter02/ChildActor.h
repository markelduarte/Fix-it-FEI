#pragma once
#include "Actor.h"
class ChildActor :
    public Actor
{
public:
    ChildActor(class Game* game, float x, float y, 
               float w, float h);

    virtual void UpdateActor(float deltaTime) override;

private:

};

