#include "Graphics.h"

#include "Common.h"
#include "debug_str.h"

Graphics::Graphics()
    : cam { 0 }
    , cam_cursor { 0 }
{
    _log::debug(FUNC_BEGAN(return_func_name()));
    _log::debug(FUNC_FINISHED(return_func_name()));
}

void Graphics::Init(int p_resx, int p_resy)
{
    _log::info(FUNC_INIT_PENDING(return_func_name()));

    int monitor = GetCurrentMonitor();
    fps = GetMonitorRefreshRate(monitor);
    this->resx = p_resx;
    this->resy = p_resy;

    InitWindow(this->resx, this->resy, "Canyon");
    SetTargetFPS(this->fps);

    this->cam.offset = { this->resx / 2.0f, this->resy / 2.0f };
    this->cam.zoom = 1.0f;
    this->cam.target = this->cam_cursor;

    _log::info(FUNC_INIT_DONE(return_func_name()));
    _log::info("Monitor:{0}, Fps:{1}", monitor, fps);
    _log::debug(FUNC_FINISHED(return_func_name()));

    //test code!
    Image img = LoadImage("res/placeholders/island_full_test_1.png");
    Texture2D text = LoadTextureFromImage(img);
    UnloadImage(img);
    Sprite spr(text);
    this->addSprite(spr);
}

void Graphics::MoveCamera(float x, float y)
{
    this->cam_cursor.x += x;
    this->cam_cursor.y += y;
    _log::debug("Camera Moved x:{0} y:{1}", cam_cursor.x, cam_cursor.y);
}

void Graphics::Update()
{
    this->cam.target = this->cam_cursor;
    BeginDrawing();
    ClearBackground(BLACK);
    BeginMode2D(this->cam);
    for (auto& t : this->render_list) {
        DrawTexture(*t.getTexture(), 0, 0, WHITE);
    }
    EndMode2D();
    EndDrawing();
    if (cam.zoom <= 0.5) {
        cam_mov = 0.45;
    } else if (cam.zoom <= 1) {
        cam_mov = 0.15;
    } else {
        cam_mov = 0.05;
    }
    mcam_mov = -1 * cam_mov;
}

void Graphics::addSprite(Sprite& spr)
{
    _log::debug(FUNC_BEGAN(return_func_name()));
    if (spr.getTexture() == nullptr)
        throw -1;

    this->render_list.push_back(spr);
    _log::debug(FUNC_FINISHED(return_func_name()));
}

/*
TODO:   "The Camera Problem!":
            the camera slows down when zooming out and
            speeds up when zooming in!
FIX:
    temporary but we can cap the zoom amount!
*/

void Graphics::ZoomIn()
{
    _log::info("{}", cam.zoom);
    if (cam.zoom < 2) {
        this->cam.zoom += 0.0005f;
    }
}

void Graphics::ZoomOut()
{
    _log::info("{}", cam_mov);
    if (cam.zoom > 0.1) {
        this->cam.zoom -= 0.0005f;
    }
}