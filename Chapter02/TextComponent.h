#pragma once
#include "SpriteComponent.h"
#include "Actor.h"

class TextComponent :
    public SpriteComponent
{
public:
    TextComponent(class Actor* owner, int updateOrder = 120);

    void SetText(SDL_Renderer* renderer, const char* fmt, ...);
};

