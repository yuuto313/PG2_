#pragma once
#include "Vector2.h"
#include "Novice.h"
#include <vector>
#include <conio.h>

#define WIDTH 1280
#define HEIGHT 720

class Object
{
protected:
	Vector2 pos_;
	Vector2 vel_;
	float radius_;
	bool isAlive_;
	int coolDown_;

	float range_;
public:
	virtual void Init();
	virtual void Update();
	virtual void Draw();

public:
	Vector2* GetPos();
	float GetRange();
	virtual void HitAction();
	Vector2 VSub(Vector2 vec1, Vector2 vec2);
	float VSquareSize(Vector2 vec);
	void ChackHitCircle(Object* obj1, Object* obj2);
};

