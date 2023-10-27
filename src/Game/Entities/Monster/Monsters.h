#include "Monster.h"

class Rat: public Monster {
public:
    Rat(float& x_, float& y_, float& w_, float& h_):
    Monster(x_, y_, w_, h_, 1) {
        name = "Rat";
        sprite = createSprite("Rat.png");
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
    Rat2(float& x_, float& y_, float& w_, float& h_):
    Monster(x_, y_, w_, h_, 2) {
        name = "Rat2";
        sprite = createSprite("Rat2.png");
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
