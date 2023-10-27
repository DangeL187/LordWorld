class Artifact: public Item {
protected:
    //some unique stats
public:
    Artifact(float x, float y, unsigned int id, Sprite sprite):
    Item(x, y, id, sprite) {
        type = 7;
    }
};
