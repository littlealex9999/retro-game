#pragma once

class Enemy;
class EnemySpawner
{
public:
	EnemySpawner(float delay, Enemy enemy);
	void Spawn();

	float spawnDelay;
	Enemy* enemyToSpawn;

	void Update(const float dt);
};