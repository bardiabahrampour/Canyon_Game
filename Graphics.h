#pragma once
#include <raylib.h>

#include <exception>
#include <map>
#include <vector>

#include "Sprite.h"
#include "raywin.h"

/*
        How it works:
                This Class Contains a Vector full of Sprites
                and Renders the corresponding Sprite in the Update() Function
*/

/* class GraphicsException : std::runtime_error {

};*/

class Graphics {
    Vector2 cam_cursor {};
    Camera2D cam {};
    //std::map<const char*, Texture2D> textures;
    int fps;
    int resx, resy;
    float delta_time;
    std::vector<Sprite> render_list {};

public:
    Graphics();
    void Init(int p_resx, int p_resy);
    void MoveCamera(float x, float y);
    void Update();
    void addSprite(Sprite& spr);
};
