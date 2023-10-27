class InterfaceHotbar: public InterfaceElement {
private:
    Sprite HotbarBackgroundSprite;
    Sprite PickedSpellSprite;
    Sprite HotbarSprites[9];
    Sprite NoManaSprites[9];
    Font font;
    Text text_cd[9];
public:
    InterfaceHotbar():
    InterfaceElement() {
        font.loadFromFile("../font/font.ttf");
        HotbarBackgroundSprite = createSprite("GuiHotbar.png");
        PickedSpellSprite = createSprite("GuiPickedSpell.png");
        for (int i = 0; i < 9; i++) {
            HotbarSprites[i] = Sprite();
            NoManaSprites[i] = createSprite("GuiNoMana.png");
            setText(text_cd[i], font, 40);
            text_cd[i].setColor(Color::White);
            text_cd[i].setStyle(Text::Bold);
        }
    }

    void update(std::shared_ptr<WindowManager>& window_manager, std::shared_ptr<Player>& player) {
        x = window_manager->viewGetCenterX() - 536;
        y = window_manager->viewGetCenterY() + 384;

        HotbarBackgroundSprite.setPosition(x - 4, y - 4);
        for (int i = 0; i < 9; i++) {
            HotbarSprites[i] = player->hotbar_spells[i]->getSprite();
            HotbarSprites[i].setPosition(x + 112 * i, y);
            NoManaSprites[i].setPosition(x + 112 * i, y);
            int mana_cost = player->hotbar_spells[i]->getManacost();
            if (player->hotbar_spells[i]->getID() != 0 && (player->cooldowns[i]->isRunning() || player->mp < mana_cost)) {
                NoManaSprites[i].setColor(sf::Color(0, 0, 0, 160));
            } else {
                NoManaSprites[i].setColor(sf::Color(0, 0, 0, 0));
            }

            if (player->cooldowns[i]->isRunning()) {
                text_cd[i].setString(std::to_string(int(player->cooldowns[i]->getTime())/1000));
            } else {
                text_cd[i].setString("");
            }
            int text_len = text_cd[i].getString().getSize();
            text_cd[i].setPosition(x + (115 - 28 * text_len)/2 + 112 * i, y + 43);
        }

        if (player->is_aiming) {
            int id = player->spell_slot;
            PickedSpellSprite.setPosition(x + 112 * id, y);
        }
    }

    void draw(std::shared_ptr<WindowManager>& window_manager, bool is_aiming) {
        window_manager->windowDraw(HotbarBackgroundSprite);
        for (int i = 0; i < 9; i++) {
            window_manager->windowDraw(HotbarSprites[i]);
            window_manager->windowDraw(NoManaSprites[i]);
            window_manager->windowDraw(text_cd[i]);
        }
        if (is_aiming) {
            window_manager->windowDraw(PickedSpellSprite);
        }
    }
};
