#pragma once

class Shield: public Item {
protected:
    //some unique stats
public:
    Shield(float x, float y, unsigned int id, Sprite sprite):
    Item(x, y, id, sprite) {
        type = 2;
    }
};

class Helmet: public Item {
protected:
    //some unique stats
public:
    Helmet(float x, float y, unsigned int id, Sprite sprite):
    Item(x, y, id, sprite) {
        type = 3;
    }
};

class Chestplate: public Item {
protected:
    //some unique stats
public:
    Chestplate(float x, float y, unsigned int id, Sprite sprite):
    Item(x, y, id, sprite) {
        type = 4;
    }
};

class Pants: public Item {
protected:
    //some unique stats
public:
    Pants(float x, float y, unsigned int id, Sprite sprite):
    Item(x, y, id, sprite) {
        type = 5;
    }
};

class Boots: public Item {
protected:
    //some unique stats
public:
    Boots(float x, float y, unsigned int id, Sprite sprite):
    Item(x, y, id, sprite) {
        type = 6;
    }
};
