#pragma once
#include "Projectile.h"

class ShrapnelShot : public Projectile
{
public:
	ShrapnelShot(Team team);
	ShrapnelShot(const ShrapnelShot &proj);

	void Draw() override;
};