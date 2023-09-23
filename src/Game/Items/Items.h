#include "Item.h"

class WoodenSword: public Item {
public:
    WoodenSword(float& x_, float& y_, unsigned int& id_, int& sprite):
    Item(x_, y_, 1, sprite) {
        type = 1; //weapon
    }
};

class IronShield: public Item {
public:
    IronShield(float& x_, float& y_, unsigned int& id_, int& sprite):
    Item(x_, y_, 2, sprite) {
        type = 2; //shield
    }
};

class IronHelmet: public Item {
public:
    IronHelmet(float& x_, float& y_, unsigned int& id_, int& sprite):
    Item(x_, y_, 3, sprite) {
        type = 3; //helmet
    }
};

class IronChestplate: public Item {
public:
    IronChestplate(float& x_, float& y_, unsigned int& id_, int& sprite):
    Item(x_, y_, 4, sprite) {
        type = 4; //chestplate
    }
};

class IronPants: public Item {
public:
    IronPants(float& x_, float& y_, unsigned int& id_, int& sprite):
    Item(x_, y_, 5, sprite) {
        type = 5; //pants
    }
};

class IronBoots: public Item {
public:
    IronBoots(float& x_, float& y_, unsigned int& id_, int& sprite):
    Item(x_, y_, 6, sprite) {
        type = 6; //boots
    }
};

class IronRing: public Item {
public:
    IronRing(float& x_, float& y_, unsigned int& id_, int& sprite):
    Item(x_, y_, 7, sprite) {
        type = 7; //ring
    }
};

class RatTail: public Item {
public:
    RatTail(float& x_, float& y_, unsigned int& id_, int& sprite):
    Item(x_, y_, 8, sprite) {
        type = 8; //item
    }
};
