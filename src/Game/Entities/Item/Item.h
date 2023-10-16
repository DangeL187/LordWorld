class Item {
protected:
    float x, y;
    int id;
    int type;
    int static_sprite;
public:
    Item(float x_=0, float y_=0, unsigned int id_=0, int sprite=0) {
        x = x_;
        y = y_;
        id = id_;
        static_sprite = sprite;
    }

    void reduceSprite() {
		static_sprite--;
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
