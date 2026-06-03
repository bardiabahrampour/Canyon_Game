#pragma once

#include "Sprite.h"
#include <exception>

class GUIException : public std::exception {
    
};

enum class GUIState {
    MAIN_MENU,
    IN_GAME,
    PAUSE_MENU,
    NONE,
};

class GUI {
    GUIState gui_state = GUIState::NONE;

public:
    void Init();
    void Update(SpriteBuffer& gui_buff);
};
