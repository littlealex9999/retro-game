#pragma once
#include <vector>

class GameObject;
class GameManager
{
public:
	GameManager();
	~GameManager();

	void Update(const float dt);
	void Draw();

private:
	std::vector<GameObject*> characters;
	std::vector<GameObject> projectiles;
};