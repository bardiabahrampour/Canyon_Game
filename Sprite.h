#pragma once

#include "Resource.h"
#include <raylib.h>

/*
        2D Sprite:
                is Rendered by Graphics Class
                ResourceID is not implemented yet!!!
                it is used to get the Image from the Resource Manager!!!
*/

class Sprite : Resource {
  Color tint{};
  int posX{}, posY{};
  Texture2D texture{};

public:
  Sprite(Texture2D t = (Texture2D)(0), int x = 0, int y = 0,
         Color ti = (Color)(0), int res = 0);
  Texture2D *getTexture();
  void setPos(float x, float y);
  void setPos(Vector2 p_pos);
  void setTexture(Texture2D *text);
};
