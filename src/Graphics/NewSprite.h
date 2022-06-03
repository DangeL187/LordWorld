class NewSprite {
public:
    Texture texture;
    Sprite sprite;

    NewSprite(std::string name) {
        texture.loadFromFile("../images/" + name);
        sprite.setTexture(texture);
        sprite.setPosition(300, 300);
    }
    Sprite getSprite() {
        return sprite;
    }
};
