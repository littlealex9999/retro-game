#pragma once
#include "Character.h"

class Enemy : public Character
{
public:
	Enemy(float hp, float spd, int scr, Vector2 pos, Vector2 fac);
	Enemy(const Enemy &e);

	int score;

	bool CheckCollision(Vector2 pos) override;

	void Update(const float dt) override;
	void Draw() override;
};