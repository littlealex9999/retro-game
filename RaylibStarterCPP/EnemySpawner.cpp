#include "EnemySpawner.h"
#include "GameManager.h"
#include "Enemy.h"
#include <chrono>

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

	enemyToSpawn->position.x = std::chrono::system_clock::now().time_since_epoch().count() % GetScreenWidth();

	if (spawnTimer <= 0) {
		Spawn();
		spawnTimer = spawnDelay;
	}
}
