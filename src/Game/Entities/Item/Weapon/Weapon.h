class Sword: public Item {
public:
    Sword(float x, float y, unsigned int id, Sprite sprite):
    Item(x, y, id, sprite) {
        weapon_type = 1;
        type = 1;
    }
};
