#include "Character.h"
#include "Projectile.h"
#include "GameManager.h"

Character::Character(float hp, Vector2 pos, Vector2 fac, Team team) : GameObject(pos, fac, Team::PLAYER), health { hp }
{ }

Character::~Character()
{ 
	for (int i = 0; i < projectiles.size(); i++) {
		delete projectiles[i];
	}
}

void Character::TakeDamage(float dmg)
{ 
	health -= dmg;
}

void Character::Shoot()
{ 
	if (currentProjectileToShoot >= projectiles.size()) { 
		if (projectiles.size() == 0) {
			return;
		}
		currentProjectileToShoot = 0;
	}

	Projectile* copy = new Projectile(*projectiles[currentProjectileToShoot]);
	copy->position = position;
	copy->facing = facing;
	Manager::manager.addProjectile(copy);

	shootCooldown = projectiles[currentProjectileToShoot]->getCooldown();

	currentProjectileToShoot++;
}

void Character::SetProjectiles(const std::vector<Projectile*> &proj)
{ 
	for (int i = 0; i < projectiles.size(); i++) {
		delete projectiles[i];
	}

	currentProjectileToShoot = 0;
	projectiles = proj;
}

void Character::OffScreenAction(std::vector<Character*> goVector, std::vector<Character*>::iterator iteration)
{ }

void Character::Update(const float dt)
{ 
	shootCooldown -= dt;
}
