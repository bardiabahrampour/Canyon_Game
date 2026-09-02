#include "Framework.h"

#include <Windows.h>

#include <algorithm>

#include "raywin.h"

/*
    TODO!!:
        we have to decouple everything
        try to rely on shared data maniupulation
        instead of function calls
        like camera is just a struct and both 
        graphics and framework is reading it
        framework manipulates based on input
        graphics reads it every frame;
        grapihcs and others are inited in main loop
        then in the main loop
        hey are updated one by one with shared data
        passing through like message bus, draw list, gui list
*/

void Framework::init()
{
    this->grph.Init(GetScreenWidth(), GetScreenHeight());
    this->tile.set(50, 30);
    this->gui.Init();
    this->game_state = GameState::PLAYING;
    while (!WindowShouldClose() && game_is_running) {
        this->update();
    }
}

// this is incredibly inefficient and causes EXTREME slow downs
void Framework::update()
{
    if (this->game_state == GameState::NONE)
        throw GameException("GameState is NONE!!");

    // test example!
    if (IsKeyPressed(KEY_ESCAPE))
        this->Command_Buffer.push_back(Command::EXIT_GAME);
    if (IsKeyPressed(KEY_F))
        this->Command_Buffer.push_back(Command::TOGGLE_FULLSCREEN);
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
    switch (this->game_state) {
    case GameState::MAIN_MENU:
        break;
    case GameState::PAUSE:
        break;
    case GameState::PLAYING:
        this->GameLoop();
    default:
        break;
    }

    // this->Command_Buffer.clear();
    this->tile.draw(1, 1, 0, 0, sprite_buffer);
    this->grph.Update(sprite_buffer, gui_buffer);
    //this->gui.Update(gui_buffer);
}

void Framework::GameLoop()
{
    this->CameraInput();
}

void Framework::send(const Command& cmd)
{
    this->Command_Buffer.push_back(cmd);
}

void Framework::CameraInput()
{
    //  TODO: turn to switch case
    if (IsKeyDown(KEY_LEFT_SHIFT))
        speed = 10;
    else if (IsKeyDown(KEY_LEFT_CONTROL))
        speed = 2;
    else if (IsKeyDown(KEY_LEFT_ALT))
        speed = 20;
    else
        speed = 4;
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
    if ((camx != 0 || camy != 0) /* && (((int)camx % 10 == 0) || ((int)camy % 10 == 0))*/) {
        _log::debug("cam added velocity in cordinates:{0},{1}", camx, camy);

        this->grph.MoveCamera(camx, camy);

        camx = 0;
        camy = 0;
    }

    if (IsKeyDown(KEY_EQUAL))
        this->grph.ZoomIn();
    else if (IsKeyDown(KEY_MINUS))
        this->grph.ZoomOut();

    if (IsKeyPressed(KEY_E))
        grph.RotateRight();
    else if (IsKeyPressed(KEY_Q))
        grph.RotateLeft();
}

void Framework::SetSpriteBuffer(SpriteBuffer& sprt_buff)
{
    sprite_buffer = sprt_buff;
}

void Framework::SetGuiBuffer(SpriteBuffer& gui_buff)
{
    gui_buffer = gui_buff;
}