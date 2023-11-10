#pragma once
#include <raylib.h>

#include <map>

#include "raywin.h"

class Graphics {
  Vector2 cam_cursor{};
  Camera2D cam{};
  std::map<const char*, Texture2D> textures;
  int fps;
  int resx, resy;
  float delta_time;
 public:
  Graphics(int p_resx, int p_resy);
  void MoveCamera(float x, float y);
};
