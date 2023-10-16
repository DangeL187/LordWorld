#include "Monster.h"

class Rat: public Monster {
public:
    Rat(float& x_, float& y_, float& w_, float& h_, unsigned int& id_, int& sprite):
    Monster(x_, y_, w_, h_, 1, sprite) {
        name = "Rat";
        damage = 2;
        hp = 10;
        mp = 10;
        lvl = 1;
        attack_speed = 1000;
        xp = 5;
        drop.push_back(8);
        drop_chance.push_back(50);
    }
};

class Rat2: public Monster {
public:
    Rat2(float& x_, float& y_, float& w_, float& h_, unsigned int& id_, int& sprite):
    Monster(x_, y_, w_, h_, 2, sprite) {
        name = "Rat2";
        damage = 4;
        hp = 100;
        mp = 10;
        lvl = 1;
        attack_speed = 1000;
        xp = 5;
        drop.push_back(8);
        drop_chance.push_back(50);
    }
};
