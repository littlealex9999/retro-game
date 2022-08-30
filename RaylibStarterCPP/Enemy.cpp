#include "Enemy.h"

Enemy::Enemy(float hp, Vector2 pos, Vector2 fac) : Character(hp, pos, fac, Team::ENEMY)
{ }

Enemy::Enemy(const Enemy* e) : Enemy(e->health, e->position, e->facing)
{ }

bool Enemy::CheckCollision(Vector2 pos)
{
	return CheckCollisionPointRec(pos, { position.x, position.y, 20, 20 });
}

void Enemy::Update(const float dt)
{ 
	Character::Update(dt);
}

void Enemy::Draw()
{ 
	DrawRectangle(position.x, position.y, 20, 20, RED);
}