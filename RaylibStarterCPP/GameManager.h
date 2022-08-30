#pragma once
#include <vector>

class GameObject;
class Projectile;
class Character;
class EnemySpawner;
class GameManager
{
public:
	GameManager();
	~GameManager();

	void addCharacter(Character* chara);
	void addProjectile(Projectile* proj);

	void Update(const float dt);
	void Draw();

private:
	// only characters should be added to characters vector
	// likewise, projectiles only to the projectiles vector
	std::vector<Character*> characters;
	std::vector<Projectile*> projectiles;

	std::vector<EnemySpawner*> spawners;
};

namespace Manager
{
	extern GameManager manager;
};