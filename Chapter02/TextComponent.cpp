#define BUFFSIZE 1024

#include "TextComponent.h"
#include "Actor.h"
#include "Game.h"
#include <cstdarg>

TextComponent::TextComponent(class Actor* owner, int updateOrder)
	:SpriteComponent(owner, updateOrder) {}

void TextComponent::SetText(SDL_Renderer* renderer, const char* fmt, ...) {
	char buffer[BUFFSIZE];

	va_list rest;
	va_start(rest, fmt);

	SDL_vsnprintf(buffer, BUFFSIZE, fmt, rest);

	va_end(rest);

	SDL_Color color = {
		255, 255, 255, 255
	};

	SDL_Surface* text = TTF_RenderText_Solid(mOwner->GetGame()->GetFont(), buffer, color);

	SDL_Texture* textureText = SDL_CreateTextureFromSurface(renderer, text);

	SetTexture(textureText);

}
