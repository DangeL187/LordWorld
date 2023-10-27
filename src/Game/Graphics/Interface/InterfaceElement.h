class InterfaceElement {
protected:
    float x, y;

    void setText(Text& text, Font& font, int size) {
        text.setFont(font);
        text.setString("");
        text.setCharacterSize(size);
    }
public:
    InterfaceElement() = default;

    float getX() {
        return x;
    }
    float getY() {
        return y;
    }
};
