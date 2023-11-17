#pragma once

#include <raylib.h>

/*
        2D Sprite:
                is Rendered by Graphics Class
                ResourceID is not implemented yet!!!
                it is used to get the Image from the Resource Manager!!!
*/

class Sprite {
 public:
  Color Tint{};
  int posX{}, PosY{};
  Texture2D Texture{};
  int ResourceID{};
  Sprite(Texture2D t = (Texture2D)(0), int x = 0, int y = 0,
         Color ti = (Color)(0), int res = 0);
};
