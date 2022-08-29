#include "GameManager.h"
#include "Player.h"

GameManager::GameManager()
{ 
	characters.push_back(new Player { 50, Vector2{5, 10}, Vector2{ GetScreenWidth() / 2.f, GetScreenHeight() / 2.f }, Vector2{ 0, -1 } });
}

GameManager::~GameManager()
{
	for (int i = 0; i < characters.size(); i++) {
		delete characters[i];
	}
}

void GameManager::Update(const float dt)
{
	for (int i = 0; i < characters.size(); i++) {
		characters[i]->Update(dt);

		if (characters[i]->position.x < 0 || characters[i]->position.x > GetScreenWidth() || characters[i]->position.y < 0 || characters[i]->position.y > GetScreenHeight()) {
			characters[i]->OffScreenAction(characters, characters.begin() + i);
		}
	}
}

void GameManager::Draw()
{ 
	for (GameObject* go : characters) {
		go->Draw();
	}
}
