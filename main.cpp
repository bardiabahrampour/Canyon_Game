#include <raylib.h>
#include <string>
#include "raywin.h"

int _stdcall wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR lpCmdLine,
    _In_ int nShowCmd) 
{
  Vector2 Cursor = {800, 600};
  InitWindow(1920, 1080, "Canyon");
  Camera2D camera{};
  camera.offset = {400, 300};
  camera.zoom = 1.0f;
  camera.target = Cursor;
  Image img = LoadImage("res/placeholders/island_full_test_1.png");
  if (img.data == nullptr) {
    throw std::exception("Failed to Load img");
  }
  Texture2D text = LoadTextureFromImage(img);
  UnloadImage(img);
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    if (IsKeyDown(KEY_RIGHT)) {
      Cursor.x += 5.0f;
      OutputDebugStringA(std::to_string(Cursor.x).c_str());
      OutputDebugStringA("\n ");
    }
    if (IsKeyDown(KEY_MINUS)) {
      camera.zoom -= 0.005f;
    }
    camera.target = Cursor;
    BeginDrawing();
    ClearBackground(BLACK);
    BeginMode2D(camera);
    DrawTexture(text, 300, 400,WHITE);
    EndMode2D();
    DrawText("Canyon Test", 190, 200, 20, YELLOW);
    EndDrawing();
  }
  UnloadTexture(text);
  CloseWindow();
}