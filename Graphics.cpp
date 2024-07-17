#include "Graphics.h"

#include "Common.h"
#include "debug_str.h"

Graphics::Graphics() : cam{0}, cam_cursor{0} {
  _log::debug(FUNC_BEGAN(return_func_name()));
}

void Graphics::Init(int p_resx, int p_resy) {
  _log::info(FUNC_INIT_PENDING(return_func_name()));

  int monitor = GetCurrentMonitor();
  fps = GetMonitorRefreshRate(monitor);
  this->resx = p_resx;
  this->resy = p_resy;

  InitWindow(this->resx,this->resy, "Canyon");
  SetTargetFPS(this->fps);

  this->cam.offset = {this->resx / 2.0f,this->resy / 2.0f};
  this->cam.zoom = 1.0f;
  this->cam.target = this->cam_cursor;

  _log::info(FUNC_INIT_DONE(return_func_name()));
  _log::info("Monitor:{0}, Fps:{1}", monitor, fps);
  _log::debug(return_func_name() + " -> Finished");
}

void Graphics::MoveCamera(float x, float y) {
  this->cam_cursor.x += x;
  this->cam_cursor.y += y;
  _log::debug("Camera Moved x:{0} y:{1}", x, y);
}

void Graphics::Update() {
  this->cam.target = this->cam_cursor;
  BeginDrawing();
  ClearBackground(BLACK);
  for (auto &t : this->render_list) {
    DrawTexture(*t.getTexture(), 0, 0, WHITE);
  }
  BeginMode2D(this->cam);
  EndMode2D();
  EndDrawing();
}