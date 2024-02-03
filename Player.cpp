#include "Player.h"
#include "Bullet.h"

#define ADD_VEL 4
#define MAX_BULLET 500

Player::Player()
{
	Init();
}

Player::~Player()
{
}

void Player::PlayerMove(char* keys)
{
	if (keys[DIK_W]) {
		vel_.y -= ADD_VEL;
	}
	if (keys[DIK_A]) {
		vel_.x -= ADD_VEL;
	}
	if (keys[DIK_S]) {
		vel_.y += ADD_VEL;
	}
	if (keys[DIK_D]) {
		vel_.x += ADD_VEL;
	}
	pos_.x += vel_.x;
	pos_.y += vel_.y;
	vel_.x = 0;
	vel_.y = 0;

	if (pos_.y <= radius_) {
		vel_.y += ADD_VEL;
	}
	if (pos_.x <= radius_) {
		vel_.x += ADD_VEL;
	}
	if (pos_.y >= HEIGHT - radius_) {
		vel_.y -= ADD_VEL;
	}
	if (pos_.x >= WIDTH - radius_) {
		vel_.x -= ADD_VEL;
	}
	
}

void Player::BulletUpdate(char* keys)
{
	if (keys[DIK_SPACE] && coolDown_ == 0) {
		bullets_.push_back(new Bullet(pos_));
		coolDown_ = 18;
		
	}

	if (coolDown_ >= 1) {
		--coolDown_;
	}

	auto itr = bullets_.begin();
	while (itr != bullets_.end()) {
		(*itr)->PlayerBullet();

		if (!(*itr)->isShot_) {
			itr=bullets_.erase(itr);
		}
		else {
			++itr;
		}
	}
}


void Player::Init()
{
	pos_.x = 640;
	pos_.y = 600;
	vel_.x = 0;
	vel_.y = 0;
	radius_ = 13;
	coolDown_ = 0;
}

void Player::Update(char* keys)
{
	PlayerMove(keys);
	BulletUpdate(keys);
}

void Player::Draw()
{
  	for (auto itr = bullets_.begin(); itr != bullets_.end(); ++itr) {
		(*itr)->Draw();
	}
	Novice::DrawEllipse((int)pos_.x, (int)pos_.y, (int)radius_, (int)radius_, 0.f, WHITE, kFillModeSolid);
	
}


