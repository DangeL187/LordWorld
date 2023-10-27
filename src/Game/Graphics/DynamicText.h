class DynamicText {
private:
    Text text_dynamic;
    float dynamic_index = 0;
    float first_x = 0;
    float first_y = 0;
    std::shared_ptr<Timer> timer;
public:
    DynamicText(int size, float duration, std::string value="None", float x=0, float y=0, bool isRed=false) {
        timer = std::make_shared<Timer>();
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
        text_dynamic.setCharacterSize(size);
        timer->run(duration);
    }

    void update(float x=0, float y=0, std::string value="None") {
        if (value != "None") {
            text_dynamic.setString(value);
        } else {
            x = first_x;
            y = first_y;
        }

        if (timer->isRunning()) {
            dynamic_index += 0.1; //TODO: add cofiguring
            text_dynamic.setPosition(x, y - dynamic_index);
        } else {
            dynamic_index = 0;
        }
    }
    float getTime() {
        return timer->getTime();
    }
    Text& getText() {
        return text_dynamic;
    }
};
