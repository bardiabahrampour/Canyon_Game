#include "Graphics.h"

#include "Common.h"

Graphics::Graphics() : cam{0}, cam_cursor{0} {
  _log::debug(return_func_name() + " -> Finished");
}

void Graphics::Init(int p_resx, int p_resy) {
  _log::info("Graphics Initialized -> Pending");

  int monitor = GetCurrentMonitor();
  fps = GetMonitorRefreshRate(monitor);
  this->resx = p_resx;
  this->resy = p_resy;

  _log::info("Graphics Initialized -> Done");
  _log::info("Monitor:{1}, Fps:{2}", monitor, fps);
  _log::debug(return_func_name() + " -> Finished");
}

void Graphics::MoveCamera(float x, float y) {
  this->cam_cursor.x += x;
  this->cam_cursor.y += y;
  _log::debug("Camera Moved x:{1} y:{2}", x, y);
}

void Graphics::Update() {}