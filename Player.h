#pragma once
#include "Object.h"

class Bullet;
class Player :
    public Object
{
public:
    Player();
    ~Player();
    void PlayerMove(char* keys);
    void BulletUpdate(char *keys);
    
    void Init()override;
    void Update(char* keys);
    void Draw()override;

    std::vector<Bullet*> GetBullets() { return bullets_; };

private:
    std::vector<Bullet*> bullets_;
};


