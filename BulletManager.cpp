//#include "BulletManager.h"
//#include "Bullet.h"
//
//BulletManager::BulletManager()
//{
//	for (int i = 0; i < BULLET_NUM; i++) {
//		bullet_[i] = nullptr;
//	}
//}
//
//BulletManager::~BulletManager()
//{
//	for (int i = 0; i < BULLET_NUM; i++) {
//		delete bullet_[i];
//	}
//}
//
//void BulletManager::Shot(Vector2& pos)
//{
//	for (int i = 0; i < BULLET_NUM; i++) {
//		if (bullet_[i] == nullptr) {
//			bullet_[i] = new Bullet(pos);
//		}
//	}
//}
//
//void BulletManager::Update()
//{
//	for (int i = 0; i < BULLET_NUM; i++) {
//		if (bullet_[i] != nullptr) {
//			bullet_[i]->Update();
//		}
//	}
//}
//
//void BulletManager::Draw()
//{
//	for (int i = 0; i < BULLET_NUM; i++) {
//		if (bullet_[i] != nullptr) {
//			bullet_[i]->Draw();
//		}
//	}
//}
