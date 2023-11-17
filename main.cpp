#include <raylib.h>

#include <string>

#include "Common.h"
#include "Framework.h"
#include "raywin.h"

// annoying windows nag fix!
#undef LoadImage

// define logger sinks
fsink file_sink =
    std::make_shared<spdlog::sinks::basic_file_sink_mt>("log.txt", true);
msink msvc_sink = std::make_shared<spdlog::sinks::msvc_sink_mt>();

// create logger function
void create_logger() {
  spdlog::logger loge("logger", {msvc_sink, file_sink});
  std::shared_ptr<spdlog::logger> lo = std::make_shared<spdlog::logger>(loge);
  spdlog::set_default_logger(lo);
}

// return the functions name
std::string return_func_name(bool line, bool file,
                             const std::source_location& location) {
  std::string tmp;

  // get current function name
  tmp += location.function_name();
  tmp += ' ';

  // add line and file name if asked
  if (line) tmp += std::to_string(location.line());
  tmp += ' ';
  if (file) tmp += location.file_name();

  return tmp;
}

// for quick prototyping and testing
void quick_start() {
  Vector2 Cursor = {800, 600};
  InitWindow(1920, 1080, "Canyon");
  Camera2D camera{};
  camera.offset = {400, 300};
  camera.zoom = 1.0f;
  camera.target = Cursor;
  Image img = LoadImage("res/placeholders/island_full_test_1.png");
  _log::critical(return_func_name(true, true));
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

int _stdcall wWinMain(_In_ HINSTANCE hInstance,
                      _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine,
                      _In_ int nShowCmd) {
  create_logger();
  quick_start();
}