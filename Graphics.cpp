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
    _log::debug(FUNC_INIT_PENDING(return_func_name()));

    int monitor = GetCurrentMonitor();
    fps = GetMonitorRefreshRate(monitor);
    this->resx = p_resx;
    this->resy = p_resy;

    InitWindow(this->resx, this->resy, "Canyon");
    SetTargetFPS(this->fps);

    this->cam.offset = { this->resx / 2.0f, this->resy / 2.0f };
    this->cam.zoom = 1.0f;
    this->cam.target = this->cam_cursor;

    _log::debug(FUNC_INIT_DONE(return_func_name()));
    _log::info("Monitor:{0}, Fps:{1}", monitor, fps);
    _log::debug(FUNC_FINISHED(return_func_name()));

}

void Graphics::MoveCamera(float x, float y)
{
    this->cam_cursor.x += x;
    this->cam_cursor.y += y;
    _log::debug("Camera Moved x:{0} y:{1}", cam_cursor.x, cam_cursor.y);
}

void Graphics::Update(SpriteBuffer& sprt_buff, SpriteBuffer& gui_buff)
{
    this->cam.target = this->cam_cursor;
    BeginDrawing();
    ClearBackground(DARKBLUE);
    BeginMode2D(this->cam);
    //have to replace this in favor of a layer
    //system aka (vectors of sprites)
    for (auto& t : sprt_buff) {
        DrawTexture(*t.getTexture(), t.getPosx(), t.getPosy(), WHITE);
    }
    sprt_buff.clear();
    EndMode2D();
    //UI goes here (above 2d mode)
    //test ui:
    for (auto& t : gui_buff) {
        DrawTexture(*t.getTexture(), t.getPosx(), t.getPosy(), WHITE);
    }
    gui_buff.clear();
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

/*
TODO:   "The Camera Problem!":
            the camera slows down when zooming out and
            speeds up when zooming in!
FIX:
    temporary but we can cap the zoom amount!
*/

void Graphics::ZoomIn()
{
    _log::debug("{}", cam.zoom);
    if (cam.zoom < 2) {
        this->cam.zoom += 0.0005f;
    }
}

void Graphics::ZoomOut()
{
    _log::debug("{}", cam_mov);
    if (cam.zoom > 0.1) {
        this->cam.zoom -= 0.0005f;
    }
}

void Graphics::RotateRight()
{
    if (deg_indx == 3)
        deg_indx = 0;
    else {
        deg_indx++;
    }
    rotation_x = deg[deg_indx].x;
    rotation_y = deg[deg_indx].y;

    //_log::info(deg_indx);
}

void Graphics::RotateLeft()
{
    if (deg_indx == 0)
        deg_indx = 3;
    else {
        deg_indx--;
    }
    rotation_x = deg[deg_indx].x;
    rotation_y = deg[deg_indx].y;
    _log::info(deg_indx);
}