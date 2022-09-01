#include "ShrapnelShot.h"
#include "ShrapnelProjectile.h"
#include "raymath.h"

ShrapnelShot::ShrapnelShot(Team team) : Projectile(5, 30, 20, 2.8f, team)
{ 
	setProjectiles({ new ShrapnelProjectile(position, facing, this->team), 
					 new ShrapnelProjectile(position, Vector2Rotate(facing, 120), this->team), 
					 new ShrapnelProjectile(position, Vector2Rotate(facing, 240), this->team) });
}

ShrapnelShot::ShrapnelShot(const ShrapnelShot & proj) : ShrapnelShot(proj.team)
{ }

void ShrapnelShot::Draw()
{ 
	DrawCircle(position.x, position.y, 3, DARKBROWN);
}