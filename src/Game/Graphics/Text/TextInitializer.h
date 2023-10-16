class TextInitializer {
public:
    Font font;
    Text text_cd[9];
    Text player_stats_hp;
    Text player_stats_mp;
    Text player_stats_lvl;
    Text text_NPC_talk;
    Text text_target;
    Text text_info;
    Text text_strength;
    Text text_damage;
    Text text_armor;
    Text text_magic;
    Text text_critical_chance;
    Text text_magic_resistance;
    Text text_physical_resistance;
    Text text_magic_ice;
    Text text_magic_fire;
    Text text_magic_earth;
    Text text_magic_wind;
    Text text_magic_dark;
    Text text_magic_light;
    Text text_melee_weapon;
    Text text_range_weapon;
    std::vector<DynamicText> v_dynamic_texts;
    std::shared_ptr<DynamicText> text_dynamic_shield_cd;

    void setText(auto& text, auto& font, auto size) {
        text.setFont(font);
        text.setString("");
        text.setCharacterSize(size);
    }

    void initText() {
        font.loadFromFile("../font/OceanSummer.ttf");
        for (auto& i: text_cd) {
            setText(i, font, 60);
        }
        setText(player_stats_hp, font, 30);
        setText(player_stats_mp, font, 30);
        setText(player_stats_lvl, font, 30);
        setText(text_NPC_talk, font, 40);
        setText(text_target, font, 40);
        setText(text_info, font, 30);
        setText(text_strength, font, 30);
        setText(text_damage, font, 30);
        setText(text_armor, font, 30);
        setText(text_magic, font, 30);
        setText(text_magic_resistance, font, 30);
        setText(text_physical_resistance, font, 30);
        setText(text_magic_ice, font, 30);
        setText(text_magic_fire, font, 30);
        setText(text_magic_earth, font, 30);
        setText(text_magic_wind, font, 30);
        setText(text_magic_dark, font, 30);
        setText(text_magic_light, font, 30);
        setText(text_melee_weapon, font, 30);
        setText(text_range_weapon, font, 30);
        text_dynamic_shield_cd = std::make_shared<DynamicText>(font, 30);
    }
};
