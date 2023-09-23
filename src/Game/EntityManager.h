class EntityManager {
public:
    std::vector<Item> v_items;

    EntityManager() = default;

    void createItem(float x, float y, unsigned int id, auto& game) {
        int sprite = game.sprite_loader->loadItemSprite(x, y, id, game.renderer);
        switch (id) {
            case 1: {
                WoodenSword m(x, y, id, sprite);
                v_items.push_back(m);
                break;
            }
            case 2: {
                IronShield m(x, y, id, sprite);
                v_items.push_back(m);
                break;
            }
        }
    }
};
