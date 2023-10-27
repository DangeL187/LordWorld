#include "Armor.h"

class IronShield: public Shield {
public:
    IronShield(float x, float y):
    Shield(x, y, 2, createSprite("Iron Shield.png")) {
        animation_sprite = createSprite("AnimationIronShield.png");
        armor = 1;
        name = "Iron Shield";
        createDescription("Shield forged from high-quality iron");
    }
};
