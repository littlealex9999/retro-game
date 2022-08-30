#pragma once

class Enemy;
class EnemySpawner
{
public:
	EnemySpawner(float delay, Enemy* enemy);
	~EnemySpawner();
	void Spawn();

	float spawnTimer;
	Enemy* enemyToSpawn;

	void Update(const float dt);

protected:
	float spawnDelay;
};