class Renderer: public WindowManager {
public:
    std::vector<Sprite> other_sprites; //current sprites
    Sprite InventoryItemsSprite[27];
    Sprite InventoryItemEmptySprite;
    int sprite_counter = 0;
    Font font;
    std::shared_ptr<Text> text_item_info;
protected:
    //initialized sprites:
    std::vector<Sprite> gui_sprites;
    std::vector<Sprite> item_sprites;
    std::vector<Sprite> NPC_sprites;

    Sprite createSprite(std::string name) {
        NewSprite *new_sprite = new NewSprite(name);
        //gui_sprites.push_back(new_sprite->getSprite());
        return new_sprite->getSprite();
    }
    void createMapSprite(std::string name, auto &map_manager) {
        NewSprite *new_map_sprite = new NewSprite(name);
        map_manager.setSprite(new_map_sprite->getSprite());
    }
    void initText() {
        text_item_info = std::make_shared<Text>("", font, 30);
    }
};
