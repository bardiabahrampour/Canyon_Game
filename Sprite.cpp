#include "Sprite.h"

Sprite::Sprite(Texture2D t, int x, int y, Color ti, int res)
    : texture{0}, posX{0}, posY{0}, tint{0}, ResourceID{0} {
  this->texture = t;
  this->posX = x;
  this->posY = y;
  this->tint = ti;
  this->ResourceID = res;
}

Texture2D* Sprite::getTexture() { return &this->texture; }