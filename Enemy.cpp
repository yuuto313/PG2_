#include "Enemy.h"
#include "Bullet.h"
Enemy::Enemy()
{
	Init();
}

Enemy::~Enemy()
{
}

void Enemy::EnemyMove()
{
	pos_.x += vel_.x;
	if (pos_.x <= radius_ || pos_.x >= WIDTH - radius_) {
		vel_.x *= -1;
	}
}

void Enemy::BulletUpdate()
{
	if (isAlive_ && coolDown_ == 0) {
		enemyBullets_.push_back(new Bullet(pos_));
		coolDown_ = 30;
	}

	if (coolDown_ >= 1) {
		--coolDown_;
	}

	auto itr = enemyBullets_.begin();
	while (itr != enemyBullets_.end()) {
		(*itr)->EnemyBullet();

		if (!(*itr)->isShot_) {
			itr = enemyBullets_.erase(itr);
		}
		else {
			++itr;
		}
	}
}

void Enemy::Init()
{
	pos_ = { 600,200 };
	vel_ = { 8,0 };
	radius_ = 10;
	isAlive_ = true;
	coolDown_ = 0;
}

void Enemy::Update()
{
	EnemyMove();
	BulletUpdate();
}

void Enemy::Draw()
{

	for (auto itr = enemyBullets_.begin(); itr != enemyBullets_.end(); ++itr) {
		(*itr)->Draw();
	}

	if (isAlive_) {
		Novice::DrawEllipse((int)pos_.x,(int)pos_.y,(int)radius_,(int)radius_,0.f,BLUE,kFillModeSolid);
	}
}

bool Enemy::GetFlag()
{
	return isAlive_;
}
