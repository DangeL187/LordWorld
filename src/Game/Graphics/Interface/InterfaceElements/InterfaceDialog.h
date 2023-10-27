class InterfaceDialog: public InterfaceElement {
private:
    Font font;
    Text text_dialog;
    Sprite DialogSprite;
public:
    InterfaceDialog():
    InterfaceElement() {
        font.loadFromFile("../font/font.ttf");
        setText(text_dialog, font, 24);
        DialogSprite = createSprite("GuiDialog.png");
    }

    void update(std::shared_ptr<WindowManager>& window_manager) {
        x = window_manager->viewGetCenterX() - 540;
        y = window_manager->viewGetCenterY() + 80;
        DialogSprite.setPosition(x, y);
        text_dialog.setPosition(x + 45, y + 25);
    }

    void draw(std::shared_ptr<WindowManager>& window_manager, std::shared_ptr<Player>& player) {
        if (player->is_dialog) {
            window_manager->windowDraw(DialogSprite);
        }
        window_manager->windowDraw(text_dialog);
    }

    Text& getDialog() {
        return text_dialog;
    }
};
