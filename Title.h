#pragma 
#include "SceneManager.h"

class CTitle :
	public CScene
{
public:
	CTitle(CManager* pManager) :CScene(pManager) {};
	~CTitle() {};

	void Update();
	void Draw();

};

