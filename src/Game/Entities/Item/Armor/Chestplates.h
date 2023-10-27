#include "Armor.h"

class IronChestplate: public Chestplate {
public:
    IronChestplate(float x, float y):
    Chestplate(x, y, 4, createSprite("Iron Chestplate.png")) {
        armor = 3;
        name = "Iron Chestplate";
        createDescription("Chestplate forged from high-quality iron");
    }
};
