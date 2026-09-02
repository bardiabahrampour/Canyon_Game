#pragma once
#include "Sprite.h"
#include <map>

constexpr int TILE_WIDTH_DRAW = 635 / 2;
constexpr int TILE_HEIGHT_DRAW = 340 / 2;

typedef std::pair<int, int> Tilepos;

class Tilemap {
    std::vector<Sprite> tile_types;
    std::map<Tilepos, int> tiles;
    float maxx, maxy;
    int posx, posy;
    float offsets[4] = { 0, -maxx, 0, 0 };
    float offsetx, offsety;
    int rx = 0, ry = 0;

public:
    void set(int x, int y, float posx = 0, float posy = 0);
    void update(int prx, int pry);
    void addTiletype(Sprite& a);
    void setTile(int x, int y, int type);
    void draw(int x, int y, float offsetx, float offsety, SpriteBuffer& sprt_buff);
    float getMaxx();
    float getMaxy();
    void setOffsetx(float offsetx_p);
    void setOffsety(float offsety_p);
};