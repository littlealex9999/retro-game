#pragma once
#include "Character.h"

class Player : public Character
{
public:
	Player(float hp, float spd, Vector2 siz, Vector2 pos, Vector2 fac);

	Vector2 MoveInput();
	void ShootInput();
	void OffScreenAction(std::vector<Character*> goVector, std::vector<Character*>::iterator iteration) override;
	bool CheckCollision(Vector2 point) override;

	void Update(const float dt) override;
	void Draw() override;

private:
	Rectangle rec = { };
	Vector2 drawOffset;
};