#pragma once
#include "Enemy.h"

class FastEnemy : public Enemy
{
public:
	FastEnemy(Vector2 pos);
	FastEnemy(const FastEnemy &en);

	Rectangle rec;
	Vector2 drawOffset;

	bool CheckCollision(Vector2 pos) override;

	void Update(const float dt) override;
	void Draw() override;

protected:
	void HandleMove(const float dt);
	bool moveRight = false;
	bool moveDown = false;
};