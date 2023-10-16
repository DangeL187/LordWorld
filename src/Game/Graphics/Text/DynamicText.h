class DynamicText {
private:
    Font text_font;
    Text text_dynamic;
    float dynamic_index = 0;
    float show_timer = 0;
    float first_x = 0;
    float first_y = 0;
public:
    DynamicText(Font font, int size, int timer=0, std::string value="None", float x=0, float y=0, bool isRed=false) {
        text_font = font;
        first_x = x;
        first_y = y;
        if (value != "None") {
            text_dynamic.setString(value);
        } else {
            text_dynamic.setString("");
        }
        if (isRed) {
            text_dynamic.setFillColor(Color::Red);
            text_dynamic.setOutlineColor(Color::Black);
        }
        text_dynamic.setFont(text_font);
        text_dynamic.setCharacterSize(size);
        show_timer = timer;
    }
    void start(int timer) {
        if (show_timer == 0) {
            show_timer = timer;
        }
    }
    void update(float time, float x=0, float y=0, std::string value="None") {
        if (value != "None") {
            text_dynamic.setString(value);
        } else {
            x = first_x;
            y = first_y;
        }

        if (show_timer > 0) {
            show_timer -= time;
            dynamic_index += 0.1; //TODO: add cofiguring
            text_dynamic.setPosition(x, y - dynamic_index);
        } else {
            show_timer = 0;
            dynamic_index = 0;
        }
    }
    float getTimer() {
        return show_timer;
    }
    Text& getText() {
        return text_dynamic;
    }
    Font& getFont() {
        return text_font;
    }
};
