#include "EnemySpawner.h"
#include "GameManager.h"
#include "Enemy.h"

EnemySpawner::EnemySpawner(float delay, Enemy enemy) : spawnDelay { delay }, enemyToSpawn { &enemy }
{ }

void EnemySpawner::Spawn()
{ 
	Manager::manager.addCharacter(new Enemy( 50, { 100, 0 }, { 0, 1 }));
}

void EnemySpawner::Update(const float dt)
{ }
