#pragma once
#include <raylib.h>

#include <exception>
#include <map>
#include <vector>

#include "Sprite.h"
#include "raywin.h"

constexpr int TILE_WIDTH_DRAW = 635 / 2;
constexpr int TILE_HEIGHT_DRAW = 340 / 2;

/*
        How it works:
                This Class Contains a Vector full of Sprites
                and Renders the corresponding Sprite in the Update() Function
        Camera move's speed use a constant defined as
        "cam_mov"
*/

/* class GraphicsException : std::runtime_error {

};*/

typedef std::pair<int, int> Tilepos;

class Tilemap {
    std::vector<Sprite> tile_types;
    std::map<Tilepos, int> tiles;
    float maxx, maxy;
    int posx, posy;
    float offsets[4] = { 0, -maxx, 0, 0 };
    float offsetx, offsety;

public:
    void set(int x, int y, float posx = 0, float posy = 0);
    void addTiletype(Sprite& a);
    void setTile(int x, int y, int type);
    void draw(int rx, int ry,float offsetx,float offsety);
    float getMaxx();
    float getMaxy();
    void setOffsetx(float offsetx_p);
    void setOffsety(float offsety_p);
};

class Graphics {
    Vector2 cam_cursor {};
    Camera2D cam {};
    //std::map<const char*, Texture2D> textures;
    int fps;
    int resx, resy;
    float delta_time;
    //rotation coefficent for rendereing tilemaps
    //aka independent objects
    int rotation_x = 1;
    int rotation_y = 1;
    Vector2 deg[4] = { (1, 1), (-1, 1), (-1, -1), (1, -1) };
    int deg_indx = 0;
    std::vector<Sprite> render_list {};
    std::vector<Sprite> gui_list {};
    Tilemap tile;

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
    void RotateRight();
    void RotateLeft();
    void Update();
    void addSprite(Sprite& spr);
    void addGui(Sprite& spr);
};
