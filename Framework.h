#pragma once

#include <vector>
#include <functional>
#include <map>
#include <raylib.h>

/*
        Receives Messages from Systems and Processes them and dispatches anwsers
*/

enum class Command {
    MOVE_CAMERA_LEFT,
    MOVE_CAMERA_RIGHT,
    MOVE_CAMERA_UP,
    MOVE_CAMERA_DOWN,
    EXIT_GAME,
};


class Framework {
  std::vector<Command> Command_Buffer{};
  //this map is prefilled for prototype purposes
  std::map<Command, std::function<void()>> Command_Map = {
      {Command::EXIT_GAME, []() { CloseWindow(); }} 
  };
 public:
  void update();
};
