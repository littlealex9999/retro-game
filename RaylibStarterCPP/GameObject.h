#pragma once
#include "raylib.h"
#include <vector>

class GameObject
{
public:
	enum Team
	{
		NONE,
		PLAYER,
		ENEMY
	};

	GameObject();
	GameObject(Vector2 p, Vector2 f, Team t);
	
	Vector2 position;
	Vector2 facing;
	Team team;

	virtual void Move(const float dt, Vector2 moveAmount);
	virtual void OffScreenAction(std::vector<GameObject*> goVector, std::vector<GameObject*>::iterator iteration);

	virtual void Update(const float dt);
	virtual void Draw();
};