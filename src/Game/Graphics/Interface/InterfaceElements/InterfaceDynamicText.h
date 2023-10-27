class InterfaceDynamicText: public InterfaceElement {
private:
    Font font;
    std::vector<DynamicText> v_dynamic_texts;
public:
    InterfaceDynamicText():
    InterfaceElement() {
        font.loadFromFile("../font/font.ttf");
    }

    void update() {
        for (auto& v: v_dynamic_texts) {
            v.update();
        }
    }

    void draw(std::shared_ptr<WindowManager>& window_manager) {
        for (auto& v: v_dynamic_texts) {
            if (v.getTime() > 0) {
                Text temp_text = v.getText();
                temp_text.setFont(font);
                window_manager->windowDraw(temp_text);
            }
        }
    }

    void createDynamicText(int size, float duration, std::string value="None", float x=0, float y=0, bool isRed=false) {
        DynamicText dynamic_text(size, duration, value, x, y, isRed);
        v_dynamic_texts.push_back(dynamic_text);
    }
};
