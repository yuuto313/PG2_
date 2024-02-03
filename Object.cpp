#include "Object.h"

void Object::Init()
{
}

void Object::Update()
{
}

void Object::Draw()
{
}



Vector2 Object::GetPos() const
{
    return pos_;
}

float Object::GetRadius() const
{
    return radius_;
}

float Object::GetRange() const
{
    return range_;
}

bool Object::GetIsAlive() const
{
    return isAlive_;
}

bool Object::ChackHitCircle()
{
    return isAlive_ = false;
}


