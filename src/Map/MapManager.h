#include "Map.h"

class MapManager: public Map {
public:
    Sprite map_sprite;

    MapManager() = default;

    void setSprite(auto new_sprite) {
        map_sprite = new_sprite;
    }
    void setSpritePosition(int i, int j) {
        map_sprite.setPosition(i, j);
    }
    void setTileMapID(int i, int j, int id) {
        TileMap[i][j] = id;
    }
    int getTileMapID(int i, int j) {
        return TileMap[i][j];
    }
    Sprite getSprite() {
        return map_sprite;
    }

    void defineTile(int it, int jt) {
        auto t = TileMap[it][jt] + 1;
        int ty = ((t - 1) / (map_sprite.getTexture()->getSize().y / 64 + 1) + 1) - 1;
        int tx = t - ty * (map_sprite.getTexture()->getSize().x / 64) - 1;
        map_sprite.setTextureRect(IntRect(tx*64, ty*64, 64, 64));
    }
};
