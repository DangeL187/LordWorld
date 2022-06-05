class Game: public Renderer {
public:
    Clock clock;
    float time;
    std::pair<float, float> playerPosition{300.f, 300.f};
    float player_x = 300;
    float player_y = 300;

    Game() = default;

    void viewSetCenter() {
        view.setCenter(player_x, player_y); //temp
    }
    void initResources() {
        createMapSprite("map.png");
    }
    void drawSprites() {
        for (int i = 0; i < HEIGHT_MAP; i++) {
            for (int j = 0; j < WIDTH_MAP; j++) {
                defineTile(i, j);
                map_sprite.setPosition(j * 64, i * 64);
                window->draw(map_sprite);
            }
        }
        for (auto& i_sprite : gui_sprites) {
            window->draw(i_sprite);
        }
    }
};
