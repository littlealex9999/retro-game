#include "Enemy.h"

Enemy::Enemy(float hp, Vector2 pos, Vector2 fac) : Character(hp, pos, fac, Team::ENEMY)
{ }

void Enemy::Update(const float dt)
{ }

void Enemy::Draw()
{ }
