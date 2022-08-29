#include "GameObject.h"

GameObject::GameObject() : GameObject(Vector2 { GetScreenWidth() / 2.f, GetScreenHeight() / 2.f }, Vector2 { 1.f, 0.f }, Team::NONE)
{ }

GameObject::GameObject(Vector2 p, Vector2 f, Team t) : position { p }, facing { f }, team { t }
{ }

void GameObject::Update(const float dt)
{ }

void GameObject::Draw()
{ }

void GameObject::Move(const float dt, Vector2 moveAmount)
{ 
	position.x += moveAmount.x * dt;
	position.y += moveAmount.y * dt;
}

void GameObject::OffScreenAction(std::vector<GameObject*> goVector, std::vector<GameObject*>::iterator iteration)
{ }
