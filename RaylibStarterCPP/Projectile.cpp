#include "Projectile.h"
#include <iostream>
#include "raymath.h"
#include "GameManager.h"
#include "ShrapnelShot.h"

Projectile::Projectile(float life, float spd, float dmg, float cld, Vector2 pos, Vector2 fac, Team team) : GameObject(pos, fac, team), 
	maxLifeTime { life }, speed { spd }, damage { dmg }, cooldownInduction { cld }
{ }

Projectile::Projectile(float life, float spd, float dmg, float cld, Team team) : Projectile(life, spd, dmg, cld, { 0, 0 }, { 0, 1 }, team)
{ }

Projectile::Projectile(const Projectile &proj) : Projectile(proj.maxLifeTime, proj.speed, proj.damage, proj.cooldownInduction, proj.position, proj.facing, proj.team)
{ 
	for (Projectile* expr : proj.expirationProjectiles) {
		expirationProjectiles.push_back(new Projectile(*expr));
	}
}

Projectile::~Projectile()
{ 
	// fire expiration projectiles
	for (Projectile* proj : expirationProjectiles) {
		Projectile* copy = new Projectile(*proj);
		copy->position = position;

		Manager::manager.addProjectile(copy);
		delete proj;
	}
}

void Projectile::hitCharacter(Character * chara)
{ 
	
}

void Projectile::OffScreenAction(std::vector<Projectile*> goVector, std::vector<Projectile*>::iterator iteration)
{ }

void Projectile::setProjectiles(std::vector<Projectile*> proj)
{ 
	expirationProjectiles = proj;
}

void Projectile::Update(const float dt)
{ 
	currentLifeTime += dt;

	Move(dt, Vector2Scale(facing, speed));
}

void Projectile::Draw()
{ 
	DrawCircle(position.x, position.y, 2, ORANGE);
}