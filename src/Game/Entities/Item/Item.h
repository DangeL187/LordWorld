class Item {
protected:
    float x, y;
    int id;
    int type;
    int static_sprite;
public:
    Item(float x_, float y_, unsigned int id_, int sprite) {
        x = x_;
        y = y_;
        id = id_;
        static_sprite = sprite;
    }

    void setSprite(int sprite) {
        static_sprite = sprite;
    }
    unsigned int getID() {
        return id;
    }
    int getType() {
        return type;
    }
    int getSprite() {
        return static_sprite;
    }
    float getX() {
        return x;
    }
    float getY() {
        return y;
    }
};
