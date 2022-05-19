// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#pragma once
#include "SDL/SDL.h"
#include <queue>
#include <unordered_map>
#include <string>
#include <vector>
#include <cstdarg>

#include "Enemy.h"
#include "Felix.h"
#include "ShootComponent.h"

#include "CollideComponent.h"
#include "SDL/SDL_ttf.h"
#include "TextComponent.h"

class Game
{
public:
	Game();
	bool Initialize();
	void RunLoop();
	void Shutdown();

	std::vector<class Actor*> GetActors() { return mActors; }

	void AddActor(class Actor* actor);
	void RemoveActor(class Actor* actor);

	void AddFloorCollider(class CollideComponent* collider);
	void RemoveFloorCollider(class CollideComponent* collider);

	void AddBrokenWindow(class BrokenSpriteComponent* brokenWindow);
	void RemoveBrokenWindow(class BrokenSpriteComponent* brokenWindow);

	void AddDuck(class Enemy* duck);
	void RemoveDuck(class Enemy* duck);
	

	std::vector<CollideComponent*> GetColliders() const { return mColliders; }

	std::vector<BrokenSpriteComponent*> GetBrokenWindows() const { return mBrokenWindows; }

	std::vector<Enemy*> GetDucks() const { return mDucks;  };

	void AddSprite(class SpriteComponent* sprite);
	void RemoveSprite(class SpriteComponent* sprite);

	float GetWindowWidth() const { return mWindowWidth; }

	float GetWindowHeight() const { return mWindowHeight; }
	
	SDL_Texture* GetTexture(const std::string& fileName);

	void SetTimeWarp(bool tFlag) { mIsInTimeWarp = tFlag; };

	bool GetTimeWarp() { return mIsInTimeWarp; };

	bool GetDead() { return mFlagDead; };

	void SetDead() { mFlagDead = true; };

	void DrawText(const char* fmt, ...);

	void IncrementScore() { mScore++; };

	TTF_Font*  GetFont() { return mFont; }

private:
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();
	void LoadData();
	void UnloadData();

	float mWindowWidth;
	float mWindowHeight;
	
	// Map of textures loaded
	std::unordered_map<std::string, SDL_Texture*> mTextures;

	// All the actors in the game
	std::vector<class Actor*> mActors;
	// Any pending actors
	std::vector<class Actor*> mPendingActors;

	// All the sprite components drawn
	std::vector<class SpriteComponent*> mSprites;

	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;
	Uint32 mTicksCount;
	bool mIsRunning;
	// Track if we're updating actors right now
	bool mUpdatingActors;

	// Game-specific
	// Player
	class Felix* mFelix; 

	std::vector<CollideComponent*> mColliders;
	std::vector<BrokenSpriteComponent*> mBrokenWindows;
	std::vector<Enemy*> mDucks;
	std::queue<ShootComponent<Enemy>*> mSpawners;
	bool mIsSpawning;
	int mCoolDown;
	bool mFlagDead;

	bool mIsInTimeWarp;

	TTF_Font* mFont;
	int mScore;
	int count = 0;
	TextComponent* mText;
};
