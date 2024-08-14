#include "Sprite.h"

Sprite::Sprite(Texture2D t, int x, int y, Color ti, int res)
    : texture { 0 }
    , posX { 0 }
    , posY { 0 }
    , tint { 0 }
{
    this->texture = t;
    this->posX = x;
    this->posY = y;
    this->tint = ti;
}

Texture2D* Sprite::getTexture() { return &texture; }

void Sprite::setPos(float x, float y)
{
    this->posX = x;
    this->posY = y;
}
void Sprite::setPos(Vector2 p_pos)
{
    this->posX = p_pos.x;
    this->posY = p_pos.y;
}

void Sprite::setTexture(Texture2D& text) { this->texture = text; }