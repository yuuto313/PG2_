#pragma once
#include "Vector2.h"
#include "Object.h"

class Bullet:
    public Object
{
public:
    bool isShot_;

public:
    Bullet(Vector2 pos);
    ~Bullet();

    void PlayerBullet();
    void EnemyBullet();

    void Init();
    void Update();
    void Draw();
};

