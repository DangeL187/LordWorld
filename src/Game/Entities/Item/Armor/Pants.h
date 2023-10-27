#include "Armor.h"

class IronPants: public Pants {
public:
    IronPants(float x, float y):
    Pants(x, y, 5, createSprite("Iron Pants.png")) {
        armor = 4;
        name = "Iron Pants";
        createDescription("Pants forged from high-quality iron");
    }
};
