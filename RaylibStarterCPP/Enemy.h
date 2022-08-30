#pragma once
#include "Character.h"

class Projectile;
class Enemy : public Character
{
public:
	Enemy(float hp, Vector2 pos, Vector2 fac);

	void Update(const float dt) override;
	void Draw() override;
};