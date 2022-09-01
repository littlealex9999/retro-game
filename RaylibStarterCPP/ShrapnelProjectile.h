#pragma once
#include "Projectile.h"

class ShrapnelProjectile : public Projectile
{
public:
	ShrapnelProjectile(Vector2 pos, Vector2 fac, Team team);
	ShrapnelProjectile(const ShrapnelProjectile &proj);

	void Draw() override;
};