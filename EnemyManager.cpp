#include "Object.h"
#include "Enemy.h"
#include "EnemyManager.h"


EnemyManager::EnemyManager()
{
	for (int i = 0; i < ENEMY_NUM; i++) {
		enemy[i] = NULL;
	}
}

EnemyManager::~EnemyManager()
{
	for (int i = 0; i < ENEMY_NUM; i++) {
		delete enemy[i];
	}
}

void EnemyManager::Update()
{
	Spawn();
	for (int i = 0; i < ENEMY_NUM; i++) {
		if (enemy[i] != NULL) {
			enemy[i]->Update();
			if (enemy[i]->GetFlag() == false) {
				delete enemy[i];
				enemy[i] = NULL;
			}
		}
	}
}

void EnemyManager::Draw()
{
	for (int i = 0; i < ENEMY_NUM; i++) {
		if (enemy[i] != NULL) {
			enemy[i]->Draw();
		}
	}
}

void EnemyManager::Spawn()
{
	if ((rand() % 100) == 0) {
		for (int i = 0; i < ENEMY_NUM; i++) {
			if (enemy[i] == NULL) {
				enemy[i] = new Enemy();
				break;
			}
		}
	}
}
