#include "Armor.h"

class IronHelmet: public Helmet {
public:
    IronHelmet(float x, float y):
    Helmet(x, y, 3, createSprite("Iron Helmet.png")) {
        armor = 2;
        name = "Iron Helmet";
        createDescription("Helmet forged from high-quality iron");
    }
};
