#pragma once
#include <vector>

class GameObject;
class Projectile;
class Character;
class Player;
class EnemySpawner;
class GameManager
{
public:
	GameManager();
	~GameManager();

	void Init();

	void addScore(int add);

	void addCharacter(Character* chara);
	void addProjectile(Projectile* proj);

	void Update(const float dt);
	void Draw();

	Player* getPlayer() { return player; }
	void setPlayer(Player* player) { this->player = player; }

	int getScore() { return score; }

private:
	// only characters should be added to characters vector
	// likewise, projectiles only to the projectiles vector
	std::vector<Character*> characters;
	std::vector<Projectile*> projectiles;

	std::vector<EnemySpawner*> spawners;

	Player* player;
	int score = 0;
};

namespace Manager
{
	extern GameManager manager;
};