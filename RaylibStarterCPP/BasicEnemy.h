#pragma once
#include "Enemy.h"

class BasicEnemy : public Enemy
{
public:
	BasicEnemy(Vector2 pos);
	BasicEnemy(const BasicEnemy &en);

	Rectangle rec;
	Vector2 drawOffset;

	bool CheckCollision(Vector2 pos) override;

	void Update(const float dt) override;
	void Draw() override;

protected:
	void HandleMove(const float dt);
	bool moveRight = false;
};