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

enum class GUITextStyle {
    Title,
    Heading,
    SmallHeading,
    Info,
};

/*
    Gui System:
    vry ugly right now
    but the whole idea is to
    have an internal buffer you can access
    by calling functions and in the update
    fucntion it just equals it to the 
    master(Graphics) gui buffer
*/
class GUI {
    GUIState gui_state = GUIState::NONE;
    GUIState prev_state = gui_state;
    Sprite Background;
    SpriteBuffer buff;
    void Render(Sprite& spr);

public:
    void Init();
    void Update(SpriteBuffer& gui_buff);
    void MainMenu();
    void InGame();
    void Text(std::string text, GUITextStyle text_style);
};
