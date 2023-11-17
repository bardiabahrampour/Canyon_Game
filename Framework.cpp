#include "Framework.h"

#include <Windows.h>

#include <algorithm>

#include "raywin.h"

void Framework::init() {
    
}

// this is incredibly inefficient and causes EXTREME slow downs
void Framework::update() {
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
}

void Framework::send(const Command& cmd) { this->Command_Buffer.push_back(cmd); }

void Framework::passGraphics(const Graphics& grph) { this->grph = &grph; }