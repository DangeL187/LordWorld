void defineTile(int it, int jt) {
    if (TileMap[it][jt] == ' ') {
        s_map.setTextureRect(IntRect(0, 0, 64, 64));
    }
    if (TileMap[it][jt] == 's') {
        s_map.setTextureRect(IntRect(64, 0, 64, 64));
    }
    if ((TileMap[it][jt] == '0')) {
        s_map.setTextureRect(IntRect(128, 0, 64, 64));
    }
}
