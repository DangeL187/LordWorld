void defineTile(int it, int jt) {
    if (TileMap[it][jt] == ' ') {
        map_sprite.setTextureRect(IntRect(0, 0, 64, 64));
    }
    if (TileMap[it][jt] == 's') {
        map_sprite.setTextureRect(IntRect(64, 0, 64, 64));
    }
    if ((TileMap[it][jt] == '0')) {
        map_sprite.setTextureRect(IntRect(128, 0, 64, 64));
    }
}
