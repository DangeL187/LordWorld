class InterfaceBar: public InterfaceElement {
private:
    Font font;
    Text text_hp;
    Text text_mp;
    Text text_lvl;
    Sprite BarSprite;
public:
    InterfaceBar():
    InterfaceElement() {
        font.loadFromFile("../font/font.ttf");
        setText(text_hp, font, 18);
        setText(text_mp, font, 18);
        setText(text_lvl, font, 18);
        text_hp.setColor(Color::White);
        text_mp.setColor(Color::White);
        text_lvl.setColor(Color::White);
        text_hp.setStyle(Text::Bold);
        text_mp.setStyle(Text::Bold);
        text_lvl.setStyle(Text::Bold);
        BarSprite = createSprite("GuiBar.png");
    }

    void update(std::shared_ptr<WindowManager>& window_manager, std::shared_ptr<Player>& player) {
        x = window_manager->viewGetCenterX() - 960;
        y = window_manager->viewGetCenterY() - 540;
        BarSprite.setPosition(x, y);

        text_hp.setPosition(x + 280, y + 41);
        text_mp.setPosition(x + 280, y + 41 + 68);
        text_lvl.setPosition(x + 280, y + 41 + 136);

        std::string p_lvl = std::to_string(player->lvl);
        std::string p_hp = std::to_string(player->hp);
        std::string p_mp = std::to_string(player->mp);
        std::string p_xp = std::to_string(player->xp);
        std::string p_hr = std::to_string(player->hp_regen);
        std::string p_mr = std::to_string(player->mp_regen);
        text_hp.setString(p_hp + " +" + p_hr[0] + p_hr[1] + p_hr[2]);
        text_mp.setString(p_mp + " +" + p_mr[0] + p_mr[1] + p_mr[2]);
        text_lvl.setString(p_lvl + " (" + p_xp + "/" + p_lvl + "00)");
    }

    void draw(std::shared_ptr<WindowManager>& window_manager) {
        window_manager->windowDraw(BarSprite);
        window_manager->windowDraw(text_hp);
        window_manager->windowDraw(text_mp);
        window_manager->windowDraw(text_lvl);
    }
};
