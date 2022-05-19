#include "BrokenSpriteComponent.h"
#include "GridComponent.h"
#include "Game.h"
#include "Window.h"

Window::Window(Game* game, float x, float y, 
	float w, float h)
	:ChildActor(game, x, y, w, h)
{
	auto bsc = new BrokenSpriteComponent(this, 60);

	//set the screen size for the background to fit in
	bsc->SetParentSize(Vector2(mWidth, mHeight));

	//create a vector
	auto btexs = {
		GetGame()->GetTexture("Assets/Window01.png"),
		GetGame()->GetTexture("Assets/Window02.png"),
		GetGame()->GetTexture("Assets/Window03.png"),
		GetGame()->GetTexture("Assets/Window04.png")
	};

	bsc->SetBrokenTextures(btexs);
}

void Window::UpdateActor(float deltaTime)
{

}
