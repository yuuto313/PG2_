#pragma once

class Enemy;
#define ENEMY_NUM 3
class EnemyManager
{
	Enemy* enemy[ENEMY_NUM];
public:
	EnemyManager();
	~EnemyManager();

	auto GetEnemy() { return enemy[ENEMY_NUM]; };

	void Update();
	void Draw();
private:
	void Spawn();
};


