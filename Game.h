#pragma once

class CGame:
	public CScene
{
public:
	CGame(CManager* pManager) :CScene(pManager) {};
	~CGame() {};

	void Update();
	void Draw();
};

