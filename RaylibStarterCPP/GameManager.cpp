#include "GameManager.h"
#include "Player.h"
#include "Enemy.h"
#include "BasicEnemy.h"
#include "Projectile.h"
#include "EnemySpawner.h"
#include "ShrapnelShot.h"
#include "FastEnemy.h"

GameManager::GameManager()
{ }

GameManager::~GameManager()
{
	// deallocate all memory
	for (int i = 0; i < characters.size(); i++) {
		delete characters[i];
	}

	for (int j = 0; j < projectiles.size(); j++) {
		delete projectiles[j];
	}

	for (int k = 0; k < spawners.size(); k++) {
		delete spawners[k];
	}
}

// should be run once, after the raylib game window has been initialized
void GameManager::Init()
{ 
	player = new Player { 100, 50, Vector2{5, 10}, Vector2{ GetScreenWidth() / 2.f, GetScreenHeight() / 2.f }, Vector2{ 0, -1 } };
	player->SetProjectiles({ new Projectile(5, 100, 20, 0.23f, { 0, 0 }, { 0, 1 }, GameObject::Team::PLAYER) });
	characters.push_back(player);

	BasicEnemy* e = new BasicEnemy({ 0, 30 });
	e->SetProjectiles({ new ShrapnelShot(GameObject::Team::ENEMY) });
	spawners.push_back(new EnemySpawner(5.5f, e));

	FastEnemy* fastE = new FastEnemy({ 0, 15 });
	fastE->SetProjectiles({ new Projectile(3, 35, 10, 1, GameObject::Team::ENEMY) });
	spawners.push_back(new EnemySpawner(4.5f, fastE));
}

void GameManager::addScore(int add)
{ 
	score += add;
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
	// updates all projectiles
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

	// updates and checks collisions on all characters
	for (int i = 0; i < characters.size(); i++) {
		characters[i]->Update(dt);

		// deletes character if their health is below 0
		// checks if deleted character is player to end game
		if (characters[i]->health <= 0) {
			if (dynamic_cast<Enemy*>(characters[i])) {
				addScore(dynamic_cast<Enemy*>(characters[i])->score);
			} else if (dynamic_cast<Player*>(characters[i])) {
				player = nullptr;
			}

			delete characters[i];
			characters.erase(characters.begin() + i);
			i--;
			continue;
		}

		if (characters[i]->position.x < 0 || characters[i]->position.x > GetScreenWidth() || characters[i]->position.y < 0 || characters[i]->position.y > GetScreenHeight()) {
			characters[i]->OffScreenAction(characters, characters.begin() + i);
		}

		// checks for collision with all projectiles
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

	// adds new enemy spawners after passing a point threshold
	if (score > 0 && spawners.size() > 0 && score / 100 / spawners.size() > spawners.size()) {
		BasicEnemy* e = new BasicEnemy({ 0, 30 });
		e->SetProjectiles({ new ShrapnelShot(GameObject::Team::ENEMY) });
		spawners.push_back(new EnemySpawner(5.5f, e));

		FastEnemy* fastE = new FastEnemy({ 0, 15 });
		fastE->SetProjectiles({ new Projectile(3, 35, 10, 1 / ((spawners.size() - 1.f) / 4.f), GameObject::Team::ENEMY) });
		spawners.push_back(new EnemySpawner(4.5f, fastE));
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
