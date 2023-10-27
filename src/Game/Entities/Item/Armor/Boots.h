#include "Armor.h"

class IronBoots: public Boots {
public:
    IronBoots(float x, float y):
    Boots(x, y, 6, createSprite("Iron Boots.png")) {
        armor = 5;
        name = "Iron Boots";
        createDescription("Boots forged from high-quality iron");
    }
};
