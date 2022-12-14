#include "Enemy.h"
#include "Projectile.h";
#include "GameManager.h"
#include <iostream>

Enemy::Enemy(float hp, float spd, int scr, Vector2 pos, Vector2 fac) : Character(hp, spd, pos, fac, Team::ENEMY), score { scr }
{ }

Enemy::Enemy(const Enemy &e) : Enemy(e.health, e.speed, e.score, e.position, e.facing)
{ 
	projectiles = { };
	for (Projectile* proj : e.projectiles) {
		projectiles.push_back(new Projectile(*proj));
	}
}

bool Enemy::CheckCollision(Vector2 pos)
{
	return CheckCollisionPointRec(pos, { position.x, position.y, 20, 20 });
}

void Enemy::Update(const float dt)
{ 
	Character::Update(dt);

	if (shootCooldown <= 0) {
		Shoot();
	}
}

void Enemy::Draw()
{ 
	DrawRectangle(position.x, position.y, 20, 20, RED);
}