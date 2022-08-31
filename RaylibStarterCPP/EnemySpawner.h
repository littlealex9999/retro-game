#pragma once

class Enemy;
class EnemySpawner
{
public:
	EnemySpawner(float delay, Enemy* enemy);
	~EnemySpawner();
	void Spawn();

	float spawnTimer;

	void Update(const float dt);

protected:
	Enemy* enemyToSpawn;
	float spawnDelay;
};