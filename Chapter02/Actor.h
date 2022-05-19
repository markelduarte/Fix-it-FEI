// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#pragma once
#include <vector>
#include "Math.h"
class Actor//classe base de ator
{
public:
	enum State//possiveis estados do ator
	{
		EActive,
		EPaused,
		EDead
	};

	Actor(class Game* game, bool timeWarp=true);//construtor e destrutor
	virtual ~Actor();

	// função de atualização, não sobrescreva
	void Update(float deltaTime);
	// função para atualizar os componentes, não sobreescreva
	void UpdateComponents(float deltaTime);
	// atualização específica do ator, deve ser sobreescrita
	virtual void UpdateActor(float deltaTime);

	// Getters/setters
	const Vector2& GetPosition() const { return mPosition; }
	void SetPosition(const Vector2& pos) { mPosition = pos; }
	float GetScale() const { return mScale; }
	void SetScale(float scale) { mScale = scale; }
	float GetRotation() const { return mRotation; }
	void SetRotation(float rotation) { mRotation = rotation; }

	State GetState() const { return mState; }
	void SetState(State state) { mState = state; }

	class Game* GetGame() { return mGame; }

	float GetWidth() const { return mWidth; }
	void SetWidth(float w) { mWidth = w; }

	float GetHeight() const { return mHeight; }
	void SetHeight(float h) { mHeight = h; }

	// insere e remove componentes
	void AddComponent(class Component* component);
	void RemoveComponent(class Component* component);

	bool IsAffectedByTimeWarp() { return mAffectedByTimeWarp; };

//variáveis do ator
protected:
	// estado
	State mState;

	// coordenadas do ator, assim como sua escala e parâmetro para rotação
	Vector2 mPosition;
	float mScale;
	float mRotation;

	//vetor de componentes
	std::vector<class Component*> mComponents;
	class Game* mGame;

	float mWidth;
	float mHeight;

	bool mAffectedByTimeWarp;
};
