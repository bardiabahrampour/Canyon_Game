#include "GUI.h"

/*
    GUI System:
        for now each gui is a seperate function
        i have to find a better and more general way
        to desgin layouts
*/

void GUI::Init() {
    gui_state = GUIState::MAIN_MENU;
}

void GUI::Update(SpriteBuffer& gui_buff) {
    switch (gui_state) {
    case (GUIState::MAIN_MENU):
        MainMenu(gui_buff);
        break;
    case (GUIState::IN_GAME):
        InGame(gui_buff);
        break;
    case (GUIState::NONE):
        throw GUIException("gui_state is still GUIState::NONE\n"
        "state is still not assigned after construction");
    default:
        throw GUIException("gui_state switch statement is default");
        break;
    }
    prev_state = gui_state;
}

void GUI::MainMenu(SpriteBuffer& gui_buff) {
    Sprite Background = Sprite("background.jpg");
    gui_buff.push_back(Background);
    while (!IsKeyPressed(KEY_ENTER)) {
        continue;
    }
    gui_state = GUIState::IN_GAME;
}

void GUI::InGame(SpriteBuffer& gui_buff) {
    return;
}