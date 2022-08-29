#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:
	Player(float spd, Vector2 siz, Vector2 pos, Vector2 fac);

	Vector2 MoveInput();
	void OffScreenAction(std::vector<GameObject*> goVector, std::vector<GameObject*>::iterator iteration) override;

	void Update(const float dt) override;
	void Draw() override;

private:
	float speed;
	Rectangle rec = { };
	Vector2 drawOffset;
};