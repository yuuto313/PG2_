#pragma once
#include "Novice.h"


//シーンの基底クラス
class CManager;
class CScene
{
protected:
	CManager* manager_;

public:
	CScene(CManager* pManager) { manager_ = pManager; };
	virtual~CScene() {};

	virtual void Update();
	virtual void Draw();

};

class CManager
{
	char* key;


public:
	CScene* scene;

	CManager(char* pKey) { key = pKey; };
	~CManager() { delete scene; };

	char* GetKey() { return key; };

	void Update() { scene->Update(); };
	void Draw() { scene->Draw(); };
};

