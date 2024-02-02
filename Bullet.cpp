#include "Bullet.h"
#include "Novice.h"
Bullet::Bullet(Vector2 pos)
{
	pos_ = pos;
	vel_ = { 0,6 };
	radius_ = 5;
	isShot_ = true;
}

Bullet::~Bullet()
{
}

void Bullet::PlayerBullet()
{
	pos_.y -= vel_.y;

	if (pos_.y <= 0) {
		isShot_ = false;
	}
}

void Bullet::EnemyBullet()
{
	pos_.y += vel_.y;

	if (pos_.y >= 720) {
		isShot_ = false;
	}
}

void Bullet::Init()
{
}

void Bullet::Update()
{	
}

void Bullet::Draw()
{
	
	Novice::DrawEllipse((int)pos_.x, (int)pos_.y, (int)radius_, (int)radius_, 0.f, RED, kFillModeSolid);
	
}
