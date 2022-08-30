#include "GameManager.h"
#include "Player.h"
#include "Enemy.h"
#include "Projectile.h"
#include "EnemySpawner.h"

GameManager::GameManager()
{ 
	characters.push_back(new Player { 100, 50, Vector2{5, 10}, Vector2{ GetScreenWidth() / 2.f, GetScreenHeight() / 2.f }, Vector2{ 0, -1 } });
	characters[0]->SetProjectiles({ new Projectile( 5, 50, 50, 1, { 0, 0 }, { 0, 1 }, GameObject::Team::PLAYER ) });

	spawners.push_back(new EnemySpawner(5.f, new Enemy(50, { 100, 0 }, { 0, 1 })));
}

GameManager::~GameManager()
{
	// deallocate all memory
	for (int i = 0; i < characters.size(); i++) {
		delete characters[i];
	}

	for (int j = 0; j < projectiles.size(); j++) {
		delete projectiles[j];
	}
}

void GameManager::addCharacter(Character* chara)
{
	characters.push_back(chara);
}

void GameManager::addProjectile(Projectile* proj)
{
	projectiles.push_back(proj);
}

void GameManager::Update(const float dt)
{
	// update projectiles first as we have to repeatedly check them later
	for (int j = 0; j < projectiles.size(); j++) {
		projectiles[j]->Update(dt);

		if (projectiles[j]->getCurrentLifeTime() >= projectiles[j]->getMaxLifeTime()) {
			delete projectiles[j];
			projectiles.erase(projectiles.begin() + j);
			j--;
			continue;
		}

		if (projectiles[j]->position.x < 0 || projectiles[j]->position.x > GetScreenWidth() || projectiles[j]->position.y < 0 || projectiles[j]->position.y > GetScreenHeight()) {
			projectiles[j]->OffScreenAction(projectiles, projectiles.begin() + j);
		}
	}


	for (int i = 0; i < characters.size(); i++) {
		characters[i]->Update(dt);

		if (characters[i]->health <= 0) {
			delete characters[i];
			characters.erase(characters.begin() + i);
			i--;
			continue;
		}

		if (characters[i]->position.x < 0 || characters[i]->position.x > GetScreenWidth() || characters[i]->position.y < 0 || characters[i]->position.y > GetScreenHeight()) {
			characters[i]->OffScreenAction(characters, characters.begin() + i);
		}

		for (int j = 0; j < projectiles.size(); j++) {
			if (characters[i]->team != projectiles[j]->team || characters[i]->team == GameObject::Team::NONE) {
				if (characters[i]->CheckCollision(projectiles[j]->position)) {
					characters[i]->TakeDamage(projectiles[j]->getDamage());
					delete projectiles[j];
					projectiles.erase(projectiles.begin() + j);
					j--;
					continue;
				}
			}
		}
	}

	for (EnemySpawner* s : spawners) {
		s->Update(dt);
	}
}

void GameManager::Draw()
{ 
	for (GameObject* go : characters) {
		go->Draw();
	}

	for (GameObject* go : projectiles) {
		go->Draw();
	}
}
