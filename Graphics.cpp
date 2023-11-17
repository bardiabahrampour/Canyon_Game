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

  InitWindow(1920, 1080, "Canyon");
  SetTargetFPS(this->fps);

  this->cam.offset = {400, 300};
  this->cam.zoom = 1.0f;
  this->cam.target = this->cam_cursor;

  _log::info("Graphics Initialized -> Done");
  _log::info("Monitor:{1}, Fps:{2}", monitor, fps);
  _log::debug(return_func_name() + " -> Finished");
}

void Graphics::MoveCamera(float x, float y) {
  this->cam_cursor.x += x;
  this->cam_cursor.y += y;
  _log::debug("Camera Moved x:{1} y:{2}", x, y);
}

void Graphics::Update() {
  this->cam.target = this->cam_cursor;
  BeginDrawing();
  ClearBackground(BLACK);
  for (const auto& t : this->render_list) {
    DrawTexture(t.Texture, 0, 0, WHITE);
  }
  BeginMode2D(this->cam);
  EndMode2D();
}