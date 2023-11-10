#include <raylib.h>

#include <string>

#include "Framework.h"
#include "raywin.h"

#include "Common.h"

// annoying windows nag fix!
#undef LoadImage

fsink file_sink =
    std::make_shared<spdlog::sinks::basic_file_sink_mt>("log.txt", true);
msink msvc_sink = std::make_shared<spdlog::sinks::msvc_sink_mt>();

void create_logger() {
  spdlog::logger loge("logger", {msvc_sink, file_sink});
  std::shared_ptr<spdlog::logger> lo = std::make_shared<spdlog::logger>(loge);
  spdlog::set_default_logger(lo);
}


int _stdcall wWinMain(_In_ HINSTANCE hInstance,
                      _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine,
                      _In_ int nShowCmd) {
  create_logger();
  Vector2 Cursor = {800, 600};
  InitWindow(1920, 1080, "Canyon");
  Camera2D camera{};
  camera.offset = {400, 300};
  camera.zoom = 1.0f;
  camera.target = Cursor;
  Image img = LoadImage("res/placeholders/island_full_test_1.png");
  spdlog::critical("as");
  Texture2D text = LoadTextureFromImage(img);
  UnloadImage(img);
  SetTargetFPS(60);
  Framework frm;
  while (!WindowShouldClose()) {
    frm.update();
    if (IsKeyDown(KEY_RIGHT)) {
      Cursor.x += 5.0f;
      // OutputDebugStringA(std::to_string(Cursor.x).c_str());
      // OutputDebugStringA("\n ");
    }
    if (IsKeyDown(KEY_MINUS)) {
      camera.zoom -= 0.005f;
      frm.send(Command::TEST);
    }
    camera.target = Cursor;
    BeginDrawing();
    ClearBackground(BLACK);
    BeginMode2D(camera);
    DrawTexture(text, 300, 400, WHITE);
    EndMode2D();
    DrawText("Canyon Test", 190, 200, 20, YELLOW);
    EndDrawing();
  }
  UnloadTexture(text);
  CloseWindow();
}