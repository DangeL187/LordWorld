class InterfaceStats: public InterfaceElement {
private:
    bool is_stats_open = false;
    Font font;
    Text text_strength;
    Text text_agility;
    Text text_intelligence;
    Text text_damage;
    Text text_armor;
    Text text_attack_speed;
    Text text_speed;
    Text text_critical_chance;
    Text text_magic_resistance;
    Sprite StatsSprite;
public:
    InterfaceStats():
    InterfaceElement() {
        font.loadFromFile("../font/font.ttf");
        setText(text_strength, font, 18);
        setText(text_agility, font, 18);
        setText(text_intelligence, font, 18);
        setText(text_damage, font, 18);
        setText(text_armor, font, 18);
        setText(text_attack_speed, font, 18);
        setText(text_speed, font, 18);
        setText(text_critical_chance, font, 18);
        setText(text_magic_resistance, font, 18);
        StatsSprite = createSprite("GuiStats.png");
    }

    void update(std::shared_ptr<WindowManager>& window_manager, std::shared_ptr<Player>& player) {
        float mouse_x = player->getX() - (962 - Mouse::getPosition().x);
        float mouse_y = player->getY() - (544 - Mouse::getPosition().y);
        x = window_manager->viewGetCenterX() - 920;
        y = window_manager->viewGetCenterY() - 310;
        StatsSprite.setPosition(x, y);

        std::vector<std::reference_wrapper<Text>> texts = { text_strength, text_agility, text_intelligence,
            text_damage, text_armor, text_attack_speed, text_speed, text_critical_chance, text_magic_resistance };
        for (int i = 0; i < 9; i++) {
            texts[i].get().setPosition(x + 20, y + 50 * (i+1));
        }

        std::string p_speed = std::to_string(player->basic_speed);
        std::string str_speed = "Speed: ";
        str_speed += p_speed[0]; str_speed += '.'; str_speed += p_speed[2]; str_speed += p_speed[3];
        float bar_x = window_manager->viewGetCenterX() - 940;
        float bar_y = window_manager->viewGetCenterY() - 480;
        if (isInsideRectangle(mouse_x, mouse_y, bar_x, bar_y, 160, 100)) {
			text_strength.setString("Strength: " + std::to_string(player->strength));
            text_agility.setString("Agility: " + std::to_string(player->agility));
            text_intelligence.setString("Intelligence: " + std::to_string(player->intelligence));
			text_damage.setString("Damage: " + std::to_string(player->damage));
			text_armor.setString("Armor: " + std::to_string(player->armor));
            text_attack_speed.setString("Attack Speed: " + std::to_string(player->attack_speed));
            text_speed.setString(str_speed);
			text_critical_chance.setString("Critical Chance: " + std::to_string(static_cast<int>(player->critical_chance)) + "%");
			text_magic_resistance.setString("Magic Resistance: " + std::to_string(static_cast<int>(player->magic_resistance)) + "%");
			is_stats_open = true;
		} else {
			is_stats_open = false;
		}
    }

    void draw(std::shared_ptr<WindowManager>& window_manager) {
        if (is_stats_open) {
            window_manager->windowDraw(StatsSprite);
            window_manager->windowDraw(text_strength);
            window_manager->windowDraw(text_agility);
            window_manager->windowDraw(text_intelligence);
            window_manager->windowDraw(text_damage);
            window_manager->windowDraw(text_armor);
            window_manager->windowDraw(text_attack_speed);
            window_manager->windowDraw(text_speed);
            window_manager->windowDraw(text_critical_chance);
            window_manager->windowDraw(text_magic_resistance);
        }
    }
};
