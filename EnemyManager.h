#pragma once
#include "Enemy.h"
#include <array>
//class Enemy;
#define ENEMY_NUM 10
class EnemyManager
{
	
public:
	EnemyManager();
	~EnemyManager();

	unsigned int currentTime_;

	
	void Init();
	void Update();
	void Draw();
	
	std::array<Enemy*,ENEMY_NUM> GetEnemy() const { return enemy_; };
private:
	std::array<Enemy*,ENEMY_NUM> enemy_;
	void Spawn();
};


