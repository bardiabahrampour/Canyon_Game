#include "Tilemap.h"

void Tilemap::set(int x, int y, float posx, float posy)
{
    Sprite t;
    t.setPos(0, 0);
    Image t_img = LoadImage("res/placeholders/grass_test-1.png");
    Texture2D tx = LoadTextureFromImage(t_img);
    t.setTexture(tx);
    UnloadImage(t_img);
    tile_types.push_back(t);
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            this->tiles.emplace(Tilepos::pair(i, j), 0);
        }
    }
    maxx = (x - y) * TILE_WIDTH_DRAW;
    maxy = (x + y) * TILE_HEIGHT_DRAW;
}

void Tilemap::update(int prx, int pry)
{
    if ((prx == rx) && (pry == ry))
        return;
    else {
        //have to implement rotation
        return;
    }
}

void Tilemap::addTiletype(Sprite& a)
{
    tile_types.push_back(a);
}

void Tilemap::setTile(int x, int y, int type)
{
    tiles.at({ x, y }) = type;
}

void Tilemap::draw(int x, int y, float offsetx, float offsety, SpriteBuffer& sprt_buff)
{
    for (auto& tile : tiles) {
        // Isometric projection formula
        int screenX = (tile.first.first - tile.first.second) * TILE_WIDTH_DRAW;
        int screenY = (tile.first.first + tile.first.second) * TILE_HEIGHT_DRAW;

        // Apply rotation (view direction) to screen coordinates
        int rotatedX = (x * screenX) + offsetx;
        int rotatedY = (y * screenY);

        // DrawTexture(*tile_types.at(tile.second).getTexture(),
        //     rotatedX, rotatedY, WHITE);
        sprt_buff.push_back(Sprite(*tile_types.at(tile.second).getTexture(), rotatedX, rotatedY, WHITE));
    }
}

float Tilemap::getMaxx()
{
    return maxx;
}

float Tilemap::getMaxy()
{
    return maxy;
}

void Tilemap::setOffsetx(float offsetx_p)
{
    offsetx = offsetx_p;
}

void Tilemap::setOffsety(float offsety_p)
{
}