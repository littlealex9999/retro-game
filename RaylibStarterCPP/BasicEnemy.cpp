#include "BasicEnemy.h"
#include "Projectile.h"
#include "raymath.h"
#include <iostream>

BasicEnemy::BasicEnemy(Vector2 pos) : Enemy(50, 20, pos, { 0, 1 }), rec { pos.x, pos.y, 20, 10 }, drawOffset { rec.width / 2, rec.height / 2 }
{ }

BasicEnemy::BasicEnemy(const BasicEnemy &e) : BasicEnemy(e.position)
{
	rec = e.rec;
	drawOffset = e.drawOffset;
	projectiles = { };
	for (Projectile* proj : e.projectiles) {
		projectiles.push_back(new Projectile(*proj));
	}
}

bool BasicEnemy::CheckCollision(Vector2 pos)
{
	return CheckCollisionPointRec(pos, { position.x - drawOffset.x, position.y - drawOffset.y, rec.width, rec.height } );
}

void BasicEnemy::HandleMove(const float dt)
{ 
	if (position.x < 50) {
		moveRight = true;
	} else if (position.x > GetScreenWidth() - 50) {
		moveRight = false;
	}

	if (moveRight) {
		Move(dt, Vector2Scale({ 1, 0 }, speed));
	} else {
		Move(dt, Vector2Scale({ -1, 0 }, speed));
	}
}

void BasicEnemy::Update(const float dt)
{ 
	Enemy::Update(dt);

	HandleMove(dt);
	rec.x = position.x;
	rec.y = position.y;
}

void BasicEnemy::Draw()
{ 
	DrawRectanglePro(rec, drawOffset, atan2(facing.y, facing.x), RED);
}