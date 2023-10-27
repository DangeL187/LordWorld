#include "Weapon.h"

class WoodenSword: public Sword {
public:
    WoodenSword(float x_, float y_):
    Sword(x_, y_, 1, createSprite("Wooden Sword.png")) {
        animation_sprite = createSprite("AnimationWoodenSword.png");
        name = "Wooden Sword";
        damage = 1;
        createDescription("An ordinary homemade sword");
    }
};
