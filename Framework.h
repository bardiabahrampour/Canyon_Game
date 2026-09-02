#pragma once

#include <raylib.h>

#include <exception>
#include <functional>
#include <map>
#include <memory>
#include <vector>

#include "Common.h"
#include "GUI.h"
#include "Graphics.h"
#include "raywin.h"

#define WINNAME "Canyon"

/*
        Receives Messages from Systems and Processes them and dispatches answers
*/

struct CameraProperties {
    double posx;
    double posy;
    float zoom;
};

//Engine Commands (Different from Game Commands)
enum class Command {
    EXIT_GAME,
    TOGGLE_FULLSCREEN,
    TEST
};

// Game Options
struct Options {
    int camspeed = 0;
    int move_intensity = 0;
};

// Game State
enum class GameState {
    MAIN_MENU,
    PAUSE,
    PLAYING,
    NONE,
};

struct GameException : public std::runtime_error {
    explicit GameException(const std::string& message)
        : std::runtime_error("Game Exception: " + message)
    {
    }
};

// Main Application Framework
class Framework {
    std::vector<Command> Command_Buffer {

    };
    // this map is prefilled for prototype purposes
    std::map<Command, std::function<void()>> Command_Map {
        { Command::EXIT_GAME, [=]() {
             game_is_running = false;
         } },
        { Command::TOGGLE_FULLSCREEN, [=]() {
             ToggleFullscreen();
         } }
    };
    GameState game_state = GameState::NONE;
    GUI gui;
    Tilemap tile;
    Graphics grph;
    int speed = 0;
    double camx = 0, camy = 0;
    bool game_is_running = true;
    SpriteBuffer sprite_buffer;
    SpriteBuffer gui_buffer;

public:
    // Framework();
    void init();
    void update();
    void send(const Command& cmd);
    void CameraInput();
    void GameLoop();
    void SetSpriteBuffer(SpriteBuffer& sprt_buff);
    void SetGuiBuffer(SpriteBuffer& gui_buff);
};
