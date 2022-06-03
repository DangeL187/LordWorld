class Renderer: public DefineTile, public WindowManager {
public:
    std::vector<Sprite> gui_sprites;

    Renderer() = default;

    void viewSetCenter() {
        view.setCenter(player_x, player_y); //temp
    }
    void createSprite(std::string name) {
        NewSprite *new_sprite = new NewSprite(name);
        gui_sprites.push_back(new_sprite->getSprite());
    }
    void createMapSprite(std::string name) {
        NewSprite *new_map_sprite = new NewSprite(name);
        map_sprite = new_map_sprite->getSprite();
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
