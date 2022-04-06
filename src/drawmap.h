for (int i = 0; i < HEIGHT_MAP; i++) {
    for (int j = 0; j < WIDTH_MAP; j++) {
        if (TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 64, 64));
        if (TileMap[i][j] == 's')  s_map.setTextureRect(IntRect(64, 0, 64, 64));
        if ((TileMap[i][j] == '0')) s_map.setTextureRect(IntRect(128, 0, 64, 64));
        s_map.setPosition(j * 64, i * 64);
        window.draw(s_map);
    }
}
