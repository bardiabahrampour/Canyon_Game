#pragma once

#include <raylib.h>

#include <functional>
#include <map>
#include <vector>

#include "Common.h"
#include "Graphics.h"
#include "raywin.h"

#define WINNAME "Canyon"

/*
        Receives Messages from Systems and Processes them and dispatches anwsers
*/

enum class Command { EXIT_GAME, TEST };

class Framework {
  std::vector<Command> Command_Buffer{};
  // this map is prefilled for prototype purposes
  std::map<Command, std::function<void()>> Command_Map = {
      {Command::TEST, []() { spdlog::info("test_command"); }}};

  const Graphics *grph;

 public:
  // Framework();
  void init();
  void update();
  void send(const Command &cmd);
  void passGraphics(const Graphics &grph);
};
