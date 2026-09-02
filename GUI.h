#pragma once

#include "Sprite.h"
#include <stdexcept>

class GUIException : public std::runtime_error {
public:
    GUIException(const std::string& what)
        : std::runtime_error("GUI Runtime Error: " + what)
    {
    }
};

enum class GUIState {
    MAIN_MENU,
    IN_GAME,
    PAUSE_MENU,
    NONE,
};

class GUI {
    GUIState gui_state = GUIState::NONE;
    GUIState prev_state = gui_state;
    void MainMenu(SpriteBuffer& gui_buff);
    void InGame(SpriteBuffer& gui_buff);

public:
    void Init();
    void Update(SpriteBuffer& gui_buff);
};
