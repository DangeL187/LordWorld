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
    Sprite getSprite() {
        return map_sprite;
    }
    void setTileMapID(int i, int j, int id) {
        TileMap[i][j] = id;
    }
    int getTileMapID(int i, int j) {
        return TileMap[i][j];
    }

    void defineTile(int it, int jt) {
        if (TileMap[it][jt] == 0) {
            map_sprite.setTextureRect(IntRect(0, 0, 64, 64));
        }
        if ((TileMap[it][jt] == 1)) {
            map_sprite.setTextureRect(IntRect(128, 0, 64, 64));
        }
        if (TileMap[it][jt] == 2) {
            map_sprite.setTextureRect(IntRect(64, 0, 64, 64));
        }
        if (TileMap[it][jt] == 3) {
            map_sprite.setTextureRect(IntRect(192, 0, 64, 64));
        }
        if (TileMap[it][jt] == 4) {
            map_sprite.setTextureRect(IntRect(256, 0, 64, 64));
        }
        if (TileMap[it][jt] == 5) {
            map_sprite.setTextureRect(IntRect(320, 0, 64, 64));
        }
        if (TileMap[it][jt] == 6) {
            map_sprite.setTextureRect(IntRect(384, 0, 64, 64));
        }
        if (TileMap[it][jt] == 7) {
            map_sprite.setTextureRect(IntRect(448, 0, 64, 64));
        }
        if (TileMap[it][jt] == 8) {
            map_sprite.setTextureRect(IntRect(512, 0, 64, 64));
        }
        if (TileMap[it][jt] == 9) {
            map_sprite.setTextureRect(IntRect(576, 0, 64, 64));
        }
        if (TileMap[it][jt] == 10) {
            map_sprite.setTextureRect(IntRect(640, 0, 64, 64));
        }
        if (TileMap[it][jt] == 11) {
            map_sprite.setTextureRect(IntRect(704, 0, 64, 64));
        }
        if (TileMap[it][jt] == 12) {
            map_sprite.setTextureRect(IntRect(768, 0, 64, 64));
        }
        if (TileMap[it][jt] == 13) {
            map_sprite.setTextureRect(IntRect(832, 0, 64, 64));
        }
        if (TileMap[it][jt] == 14) {
            map_sprite.setTextureRect(IntRect(896, 0, 64, 64));
        }
        if (TileMap[it][jt] == 15) {
            map_sprite.setTextureRect(IntRect(960, 0, 64, 64));
        }
        if (TileMap[it][jt] == 16) {
            map_sprite.setTextureRect(IntRect(1024, 0, 64, 64));
        }
        if (TileMap[it][jt] == 17) {
            map_sprite.setTextureRect(IntRect(1088, 0, 64, 64));
        }
        if (TileMap[it][jt] == 18) {
            map_sprite.setTextureRect(IntRect(1152, 0, 64, 64));
        }
        if (TileMap[it][jt] == 19) {
            map_sprite.setTextureRect(IntRect(1216, 0, 64, 64));
        }
        if (TileMap[it][jt] == 20) {
            map_sprite.setTextureRect(IntRect(1280, 0, 64, 64));
        }
        if (TileMap[it][jt] == 21) {
            map_sprite.setTextureRect(IntRect(1344, 0, 64, 64));
        }
        if (TileMap[it][jt] == 22) {
            map_sprite.setTextureRect(IntRect(1408, 0, 64, 64));
        }
        if (TileMap[it][jt] == 23) {
            map_sprite.setTextureRect(IntRect(1472, 0, 64, 64));
        }
        if (TileMap[it][jt] == 24) {
            map_sprite.setTextureRect(IntRect(1536, 0, 64, 64));
        }
        if (TileMap[it][jt] == 25) {
            map_sprite.setTextureRect(IntRect(1600, 0, 64, 64));
        }
        if (TileMap[it][jt] == 26) {
            map_sprite.setTextureRect(IntRect(1664, 0, 64, 64));
        }
        if (TileMap[it][jt] == 27) {
            map_sprite.setTextureRect(IntRect(1728, 0, 64, 64));
        }
        if (TileMap[it][jt] == 28) {
            map_sprite.setTextureRect(IntRect(1792, 0, 64, 64));
        }
        if (TileMap[it][jt] == 29) {
            map_sprite.setTextureRect(IntRect(1856, 0, 64, 64));
        }
        if (TileMap[it][jt] == 30) {
            map_sprite.setTextureRect(IntRect(1920, 0, 64, 64));
        }
        if (TileMap[it][jt] == 31) {
            map_sprite.setTextureRect(IntRect(1984, 0, 64, 64));
        }
        if (TileMap[it][jt] == 32) {
            map_sprite.setTextureRect(IntRect(0, 0, 64, 64));
        }
    }
};
