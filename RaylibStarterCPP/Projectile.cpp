#include "Projectile.h"
#include <iostream>
#include "raymath.h"

Projectile::Projectile(float life, float spd, float dmg, float cld, Vector2 pos, Vector2 fac, Team team) : GameObject(pos, fac, team), 
	maxLifeTime { life }, speed { spd }, damage { dmg }, cooldownInduction { cld }
{ }

Projectile::Projectile(const Projectile &proj) : Projectile(proj.maxLifeTime, proj.speed, proj.damage, proj.cooldownInduction, proj.position, proj.facing, proj.team)
{ }

void Projectile::hitCharacter(Character * chara)
{ 
	
}

void Projectile::OffScreenAction(std::vector<Projectile*> goVector, std::vector<Projectile*>::iterator iteration)
{ }

void Projectile::Update(const float dt)
{ 
	currentLifeTime += dt;

	Move(dt, Vector2Scale(facing, speed));
}

void Projectile::Draw()
{ 
	DrawCircle(position.x, position.y, 2, ORANGE);
}