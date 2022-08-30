#pragma once
#include "GameObject.h"
#include <vector>

class Projectile;
class Character : public GameObject
{
public:
	Character(float hp, Vector2 pos, Vector2 fac, Team team);
	~Character();

	float health;

	void TakeDamage(float dmg);
	void Shoot();
	void SetProjectiles(const std::vector<Projectile*> &proj);
	virtual bool CheckCollision(Vector2 pos);

	virtual void OffScreenAction(std::vector<Character*> goVector, std::vector<Character*>::iterator iteration);

	void Update(const float dt) override;

protected:
	std::vector<Projectile*> projectiles;
	int currentProjectileToShoot = 0;
	float shootCooldown = 0;
};