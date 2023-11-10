#include "Graphics.h"

Graphics::Graphics(int p_resx, int p_resy) : cam{0}, cam_cursor{0} {
  fps = GetMonitorRefreshRate(GetCurrentMonitor());
  this->resx = p_resx;
  this->resy = p_resy;
  
}

void Graphics::MoveCamera(float x, float y) {
  this->cam_cursor.x += x;
  this->cam_cursor.y += y;
}