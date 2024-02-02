#pragma once
#include "Object.h"

class Bullet;
class Enemy:
	public Object
{
public:
	Enemy();
	~Enemy();

	bool isMove_;

	void EnemyMove();
	void BulletUpdate();

	void Init()override;
	void Update()override;
	void Draw()override;

	bool GetFlag();

	std::vector<Bullet*>GetBullets() { return enemyBullets_; };

public:
	std::vector<Bullet*> enemyBullets_;
};

