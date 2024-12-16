#include "Framework.h"

#include <Windows.h>

#include <algorithm>

#include "raywin.h"

void Framework::init()
{
    this->grph.Init(1920, 1080);
    while (!WindowShouldClose() && game_is_running) {
        this->update();
    }
}

// this is incredibly inefficient and causes EXTREME slow downs
void Framework::update()
{
    if (IsKeyPressed(KEY_Q))
        this->Command_Buffer.push_back(Command::EXIT_GAME);
    this->CameraInput();
    if (!this->Command_Buffer.empty()) {
        for (auto& cmdbuf : Command_Buffer) {
            auto it = this->Command_Map.find(cmdbuf);
            if (it != Command_Map.end()) {
                it->second();
            } else {
                throw "Undefined CMD";
            }
            this->Command_Buffer.pop_back();
        }
    }
    // this->Command_Buffer.clear();
    this->grph.Update();
}

void Framework::send(const Command& cmd)
{
    this->Command_Buffer.push_back(cmd);
}

void Framework::CameraInput()
{
    if (IsKeyDown(KEY_LEFT_SHIFT))
        speed = 2;
    else
        speed = 1;
    if (IsKeyDown(KEY_W)) {
        camy = this->grph.mcam_mov * speed;
    } else if (IsKeyDown(KEY_S)) {
        camy = this->grph.cam_mov * speed;
    }
    if (IsKeyDown(KEY_A)) {
        camx = this->grph.mcam_mov * speed;
    } else if (IsKeyDown(KEY_D)) {
        camx = this->grph.cam_mov * speed;
    }
    if ((camx != 0 || camy != 0) && (((int)camx % 10 == 0) || ((int)camy % 10 == 0))) {
        _log::info("cam added velocity in cordinates:{0},{1}", camx, camy);

        this->grph.MoveCamera(camx, camy);

        camx = 0;
        camy = 0;
    }

    if (IsKeyDown(KEY_EQUAL))
        this->grph.ZoomIn();
    else if (IsKeyDown(KEY_MINUS))
        this->grph.ZoomOut();
}
