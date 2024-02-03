#include "Object.h"
//#include "Enemy.h"
#include "EnemyManager.h"
#include "time.h"

EnemyManager::EnemyManager()
{
	for (int i = 0; i < ENEMY_NUM; i++) {
		enemy_[i] = NULL;
	}
	currentTime_ = static_cast<unsigned int>(time(nullptr));
	srand(EnemyManager::currentTime_);
}

EnemyManager::~EnemyManager()
{
	for (int i = 0; i < ENEMY_NUM; i++) {
		delete enemy_[i];
	}
}

void EnemyManager::Init()
{
}

void EnemyManager::Update()
{
	Spawn();
	for (int i = 0; i < ENEMY_NUM; i++) {
		if (enemy_[i] != NULL) {
			enemy_[i]->Update();
			/*if (enemy_[i]->GetFlag() == false) {
			}*/
		}
	}
}

void EnemyManager::Draw()
{
	for (int i = 0; i < ENEMY_NUM; i++) {
		if (enemy_[i] != NULL) {
			enemy_[i]->Draw();
		}
	}
}

void EnemyManager::Spawn()
{
	if ((rand() % 100) <= 50) {
		for (int i = 0; i < ENEMY_NUM; i++) {
			if (enemy_[i] == NULL) {
				enemy_[i] = new Enemy();
				break;
			}
		}
	}

}
