class InterfaceTarget: public InterfaceElement {
private:
    Font font;
    Text text_target;
    Monster* targeted_monster = NULL;
public:
    InterfaceTarget():
    InterfaceElement() {
        font.loadFromFile("../font/font.ttf");
        setText(text_target, font, 24);
        text_target.setColor(Color::White);
        text_target.setStyle(Text::Bold);
    }

    void update(std::shared_ptr<WindowManager>& window_manager) {
        x = window_manager->viewGetCenterX() + 700;
        y = window_manager->viewGetCenterY() - 500;
        text_target.setPosition(x, y);

        if (targeted_monster != NULL) {
            std::string name = targeted_monster->getName();
            std::string lvl = std::to_string(targeted_monster->getLVL());
            std::string hp = std::to_string(targeted_monster->getHP());
            text_target.setString("TARGET: " + name + "\nLVL: " + lvl + "\nHP: " + hp);
        } else {
            text_target.setString("");
        }
    }

    void draw(std::shared_ptr<WindowManager>& window_manager) {
        window_manager->windowDraw(text_target);
    }

    void setTargetedMonster(Monster* new_targeted_monster) {
        targeted_monster = new_targeted_monster;
    }
};
