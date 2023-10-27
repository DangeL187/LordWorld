class InterfaceIndicator: public InterfaceElement {
private:
    Sprite IndicatorSprite;
public:
    InterfaceIndicator():
    InterfaceElement() {
        IndicatorSprite = createSprite("GuiIndicator.png");
    }

    void update(float player_x, float player_y) {
        IndicatorSprite.setPosition(player_x + 18, player_y - 34);
    }

    void draw(std::shared_ptr<WindowManager>& window_manager, std::shared_ptr<Timer>& critical_timer) {
        if (500 <= critical_timer->getTime() && critical_timer->getTime() <= 750) {
            window_manager->windowDraw(IndicatorSprite);
        }
    }
};
