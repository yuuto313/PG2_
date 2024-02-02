#include "SceneManager.h"
#include "Game.h"

void CGame::Update()
{
}

void CGame::Draw()
{
	Novice::DrawBox(0, 0, 1280, 720, 0.f, BLACK, kFillModeSolid);
}
