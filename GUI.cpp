#include "GUI.h"
#include "Common.h"

/*
    GUI System:
        for now each gui is a seperate function
        i have to find a better and more general way
        to desgin layouts
*/

void GUI::Init()
{
    gui_state = GUIState::MAIN_MENU;
}

void GUI::Update(SpriteBuffer& gui_buff)
{
    gui_buff.clear();
    gui_buff = buff;
}

void GUI::MainMenu()
{
    return;
}

void GUI::InGame()
{
    return;
}

void GUI::Render(Sprite& spr)
{
    this->buff.push_back(spr);
}

void GUI::Text(std::string text, GUITextStyle text_style) {
    Image img = ImageText(text.c_str(), 32, WHITE);
    Texture2D tex = LoadTextureFromImage(img);
    UnloadImage(img);
    this->buff.push_back(tex);
}