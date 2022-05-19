#pragma once

#include "Math.h"
#include "SpriteComponent.h"

class ChildSpriteComponent :
    public SpriteComponent
{
public:
    ChildSpriteComponent(class Actor* owner,
        int drawOrder = 100);

    void Draw(SDL_Renderer* renderer) override;

    void SetParentSize(const Vector2& size) { mParentSize = size; }

private:
    Vector2 mParentSize;

};
