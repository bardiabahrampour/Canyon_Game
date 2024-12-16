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
        Camera move's speed use a constant defined as
        "cam_mov"
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
    double cam_mov = 0.05;
    double mcam_mov = 0.0;
    Graphics();
    void Init(int p_resx, int p_resy);
    void MoveCamera(float x, float y);
    /*
        These Zoom functions should be
        implemented as a event message 
        for more efficent gui use as
        they fire as a one click event
        with some wait time! but they
        can be implemented in "CameraInput"
        for keyboard and scroll wheel ONLY!!
    */
    void ZoomOut();
    void ZoomIn();
    void Update();
    void addSprite(Sprite& spr);
};
