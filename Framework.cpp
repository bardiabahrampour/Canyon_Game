#include "Framework.h"

#include <Windows.h>

#include <algorithm>

#include "raywin.h"

void Framework::init()
{
    this->grph.Init(1920, 1080);
    while (!WindowShouldClose()) {
        this->update();
    }
}

// this is incredibly inefficient and causes EXTREME slow downs
void Framework::update()
{
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
        camy = -0.05 * speed;
    } else if (IsKeyDown(KEY_S)) {
        camy = 0.05 * speed;
    }
    if (IsKeyDown(KEY_A)) {
        camx = -0.05 * speed;
    } else if (IsKeyDown(KEY_D)) {
        camx = 0.05 * speed;
    }
    if ((camx != 0 || camy != 0) && (((int)camx % 10 == 0) || ((int)camy % 10 == 0))) {
        _log::debug("cam added velocity in cordinates:{0},{1}", camx, camy);

        this->grph.MoveCamera(camx, camy);

        camx = 0;
        camy = 0;
    }
}
