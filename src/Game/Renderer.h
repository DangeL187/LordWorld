class Renderer: public DefineTile, public WindowManager {
protected:
    std::vector<Sprite> gui_sprites;
    
    void createSprite(std::string name) {
        NewSprite *new_sprite = new NewSprite(name);
        gui_sprites.push_back(new_sprite->getSprite());
    }
    void createMapSprite(std::string name) {
        NewSprite *new_map_sprite = new NewSprite(name);
        map_sprite = new_map_sprite->getSprite();
    }
};
