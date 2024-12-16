#pragma once

#include <raylib.h>

#include <functional>
#include <map>
#include <memory>
#include <vector>

#include "Common.h"
#include "Graphics.h"
#include "raywin.h"

#define WINNAME "Canyon"

/*
        Receives Messages from Systems and Processes them and dispatches answers
*/

enum class Command {
    EXIT_GAME,
    TEST
};

// Game Options
struct Options {
    int camspeed = 0;
    int move_intensity = 0;
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
    };

    Graphics grph;
    int speed = 0;
    double camx = 0, camy = 0;
    bool game_is_running = true;

public:
    // Framework();
    void init();
    void update();
    void send(const Command& cmd);
    void CameraInput();
};
