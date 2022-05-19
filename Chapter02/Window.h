#pragma once
#include "ChildActor.h"
#include "BrokenSpriteComponent.h"
class Window :
    public ChildActor
{
public:
    Window(Game* game, float x, float y, float w, float h);

    void UpdateActor(float deltaTime) override;

protected:
    bool isBroken = false;
    BrokenSpriteComponent* mBrokenWindow;

};

