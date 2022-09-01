#include "FastEnemy.h"
#include "Projectile.h"
#include "raymath.h"

FastEnemy::FastEnemy(Vector2 pos) : Enemy(20, 70, 15, pos, { 0, 1 }), rec { pos.x, pos.y, 8, 8 }, drawOffset { rec.width / 2, rec.height / 2 }
{ }

FastEnemy::FastEnemy(const FastEnemy & en) : FastEnemy(en.position)
{ 
	rec = en.rec;
	drawOffset = en.drawOffset;
	projectiles = { };
	for (Projectile* proj : en.projectiles) {
		projectiles.push_back(new Projectile(*proj));
	}
}

bool FastEnemy::CheckCollision(Vector2 pos)
{
	return CheckCollisionPointRec(pos, { position.x - drawOffset.x, position.y - drawOffset.y, rec.width, rec.height });
}

// moves left/right/up/down
void FastEnemy::HandleMove(const float dt)
{ 
	if (position.x < 50) {
		moveRight = true;
	} else if (position.x > GetScreenWidth() - 50) {
		moveRight = false;
	}

	if (position.y < 10) {
		moveDown = true;
	} else if (position.y > GetScreenHeight() / 2) {
		moveDown = false;
	}

	Vector2 moveDir = { };

	if (moveRight) {
		moveDir.x = 1;
	} else {
		moveDir.x = -1;
	}

	if (moveDown) {
		moveDir.y = 1;
	} else {
		moveDir.y = -1;
	}

	Move(dt, Vector2Scale(Vector2Normalize(moveDir), speed));
}

void FastEnemy::Update(const float dt)
{ 
	Enemy::Update(dt);

	HandleMove(dt);
	rec.x = position.x;
	rec.y = position.y;
}

void FastEnemy::Draw()
{ 
	DrawRectanglePro(rec, drawOffset, atan2(facing.y, facing.x), PURPLE);
}
