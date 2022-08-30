#include "EnemySpawner.h"
#include "GameManager.h"
#include "Enemy.h"

EnemySpawner::EnemySpawner(float delay, Enemy* enemy) : spawnDelay { delay }, enemyToSpawn { enemy }, spawnTimer { delay }
{ }

EnemySpawner::~EnemySpawner()
{ 
	delete enemyToSpawn;
}

void EnemySpawner::Spawn()
{ 
	Manager::manager.addCharacter(new Enemy(enemyToSpawn));
}

void EnemySpawner::Update(const float dt)
{ 
	spawnTimer -= dt;

	if (spawnTimer <= 0) {
		Spawn();
		spawnTimer = spawnDelay;
	}
}
