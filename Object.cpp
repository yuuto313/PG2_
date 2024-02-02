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

Vector2* Object::GetPos()
{
    return &pos_;
}

float Object::GetRange()
{
    return range_;
}

void Object::HitAction()
{
}

Vector2 Object::VSub(Vector2 vec1, Vector2 vec2)
{
    return Vector2(vec1.x - vec2.x, vec1.y - vec2.y);
}

float Object::VSquareSize(Vector2 vec)
{
    return (vec.x * vec.x) + (vec.y * vec.y);
}

void Object::ChackHitCircle(Object* obj1, Object* obj2)
{
    float distance = VSquareSize(VSub(*obj1->GetPos(), *obj2->GetPos()));
    float range = (obj1->GetRange() + obj2->GetRange()) * (obj1->GetRange() + obj2->GetRange());

    if (distance < range) {
        obj1->HitAction();
        obj2->HitAction();
    }
}

