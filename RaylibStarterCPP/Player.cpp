#include "Player.h"
#include "raymath.h"
#include "GameManager.h"

Player::Player(float hp, float spd, Vector2 siz, Vector2 pos, Vector2 fac) : Character(hp, spd, pos, fac, Team::PLAYER), rec { pos.x, pos.y, siz.x, siz.y }
{ 
	drawOffset = { siz.x / 2, siz.y / 2 };
}

// returns normal of input directions
// W, A, S, D  to move
Vector2 Player::MoveInput()
{ 
	Vector2 target = { };

	enum MoveState
	{
		UP		= 1 << 0, // 0001
		DOWN	= 1 << 1, // 0010
		LEFT	= 1 << 2, // 0100
		RIGHT	= 1 << 3  // 1000
	};

	MoveState move = { };

	// find held directions
	if (IsKeyDown(KeyboardKey::KEY_W)) {
		move = MoveState(move | MoveState::UP);
	}
	if (IsKeyDown(KeyboardKey::KEY_S)) {
		move = MoveState(move | MoveState::DOWN);
	}
	if (IsKeyDown(KeyboardKey::KEY_A)) {
		move = MoveState(move | MoveState::LEFT);
	}
	if (IsKeyDown(KeyboardKey::KEY_D)) {
		move = MoveState(move | MoveState::RIGHT);
	}

	// handle movement direction
	if ((move & MoveState::UP) && !(move & MoveState::DOWN)) {
		target.y = -1;
	} else if (!(move & MoveState::UP) && (move & MoveState::DOWN)) {
		target.y = 1;
	}

	if ((move & MoveState::LEFT) && !(move & MoveState::RIGHT)) {
		target.x = -1;
	} else if (!(move & MoveState::LEFT) && (move & MoveState::RIGHT)) {
		target.x = 1;
	}

	if (target.x != 0 && target.y != 0) {
		target = Vector2Normalize(target);
	}

	return target;
}

// SPACE  to shoot
void Player::ShootInput()
{ 
	if (shootCooldown <= 0 && IsKeyDown(KeyboardKey::KEY_SPACE)) {
		Shoot();
	}
}

void Player::OffScreenAction(std::vector<Character*> goVector, std::vector<Character*>::iterator iteration)
{ 
	position.x = Clamp(position.x, 0, GetScreenWidth());
	position.y = Clamp(position.y, 0, GetScreenHeight());
}

bool Player::CheckCollision(Vector2 point)
{
	return CheckCollisionPointRec(point, { position.x - drawOffset.x, position.y - drawOffset.y, rec.width, rec.height });
}

void Player::Update(const float dt)
{ 
	Character::Update(dt);

	Move(dt, Vector2Scale(MoveInput(), speed));
	rec.x = position.x;
	rec.y = position.y;

	ShootInput();
}

void Player::Draw()
{ 
	DrawRectanglePro(rec, drawOffset, 0, BLUE);
}