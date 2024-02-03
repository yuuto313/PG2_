#include "SceneManager.h"
#include "Title.h"
#include "Game.h"

void CTitle::Update()
{
	if (manager_->GetKey()[DIK_RETURN]) {
		manager_->scene = new CGame(manager_);
		delete this;
	}
}

void CTitle::Draw()
{
	Novice::DrawBox(0, 0, 1280, 720, 0.f, WHITE, kFillModeSolid);
}
