#pragma once
#include "Character.h"

class Projectile;
class Enemy : public Character
{
public:
	Enemy(float hp, float spd, Vector2 pos, Vector2 fac);
	Enemy(const Enemy &e);

	bool CheckCollision(Vector2 pos) override;

	void Update(const float dt) override;
	void Draw() override;
};