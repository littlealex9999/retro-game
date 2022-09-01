#pragma once
#include "GameObject.h"
#include <vector>

class Character;
class Projectile : public GameObject
{
public:
	Projectile(float life, float spd, float dmg, float cld, Vector2 pos, Vector2 fac, Team team);
	Projectile(float life, float spd, float dmg, float cld, Team team);
	Projectile(const Projectile &proj);
	~Projectile();

	void hitCharacter(Character* chara);
	virtual void OffScreenAction(std::vector<Projectile*> goVector, std::vector<Projectile*>::iterator iteration);

	void setProjectiles(std::vector<Projectile*> proj);

	void Update(const float dt) override;
	virtual void Draw() override;

	float getMaxLifeTime() { return maxLifeTime; }
	float getCurrentLifeTime() { return currentLifeTime; }
	float getCooldown() { return cooldownInduction; }
	float getDamage() { return damage; }

protected:
	float maxLifeTime;
	float currentLifeTime = 0;
	float speed;
	float damage;
	float cooldownInduction;

	std::vector<Projectile*> expirationProjectiles = { };
};