class NewSprite {
private:
    Texture texture;
    Sprite sprite;
public:
    NewSprite(std::string name) {
        texture.loadFromFile("../images/" + name);
        sprite.setTexture(texture);
        sprite.setPosition(0, 0);
    }
    Sprite getSprite() {
        return sprite;
    }
};

Sprite createSprite(std::string name) {
    NewSprite *new_sprite = new NewSprite(name);
    return new_sprite->getSprite();
}
