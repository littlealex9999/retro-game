#include "ShrapnelProjectile.h"

ShrapnelProjectile::ShrapnelProjectile(Vector2 pos, Vector2 fac, Team team) : Projectile(0.2f, 150, 5, 0.2f, pos, fac, team)
{ }

ShrapnelProjectile::ShrapnelProjectile(const ShrapnelProjectile & proj) : ShrapnelProjectile(proj.position, proj.facing, proj.team)
{ }

void ShrapnelProjectile::Draw()
{ 
	DrawCircle(position.x, position.y, 1, ORANGE);
}