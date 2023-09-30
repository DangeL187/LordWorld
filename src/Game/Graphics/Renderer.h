#include "DynamicText.h"
#include "Sprite/SpriteManager.h"

class Renderer {
public:
    //text:
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
    std::shared_ptr<SpriteManager> sprite_manager;
public:
    Renderer(std::shared_ptr<Map>& map) {
        createSpriteManager(map);
        initText();
    }

    void createDynamicText(Font font, int size, int timer, std::string value="None", float x=0, float y=0, bool isRed=false) {
        DynamicText dynamic_text(font, size, timer, value, x, y, isRed);
        v_dynamic_texts.push_back(dynamic_text);
    }

    void createSpriteManager(std::shared_ptr<Map>& map) {
        sprite_manager = std::make_shared<SpriteManager>(map);
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
    void updateText(float time, auto& game) {
        for (auto& i: text_cd) {
            i.setColor(Color::White);
            i.setStyle(Text::Bold);
        }
        text_target.setColor(Color::White);
        player_stats_hp.setColor(Color::White);
        player_stats_mp.setColor(Color::White);
        player_stats_lvl.setColor(Color::White);
        text_target.setStyle(Text::Bold);
        player_stats_hp.setStyle(Text::Bold);
        player_stats_mp.setStyle(Text::Bold);
        player_stats_lvl.setStyle(Text::Bold);

        std::string p_lvl = std::to_string(game.player->lvl);
        std::string p_hp = std::to_string(game.player->hp);
        std::string p_mp = std::to_string(game.player->mp);
        std::string p_xp = std::to_string(game.player->xp);
        std::string p_hr = std::to_string(game.player->hp_regen);
        std::string p_mr = std::to_string(game.player->mp_regen);
        player_stats_hp.setString(p_hp + " +" + p_hr[0] + p_hr[1] + p_hr[2]);
        player_stats_mp.setString(p_mp + " +" + p_mr[0] + p_mr[1] + p_mr[2]);
        player_stats_lvl.setString(p_lvl + " (" + p_xp + "/" + p_lvl + "00)");
        for (int i = 0; i < 9; i++) {
            if (game.player->cooldowns[i] != 0) {
                text_cd[i].setString(std::to_string(game.player->cooldowns[i]/1000));
            } else {
                text_cd[i].setString("");
            }
        }

        auto get_pos_x = game.player->getX()+50;
        auto get_pos_y = game.player->getY()-10;
        auto value = std::to_string(int(game.player->shield_cd/100)/10.0);
        value = value.erase(value.size() - 5);
        text_dynamic_shield_cd->update(time, get_pos_x, get_pos_y, value);

        for (auto& v: v_dynamic_texts) {
            v.update(time);
        }

        float view_x = game.window_manager->viewGetCenterX();
        float view_y = game.window_manager->viewGetCenterY();

        for (int i = 0; i < 9; i++) {
            text_cd[i].setPosition(view_x - 490 + 112 * i, view_y + 404);
        }
        player_stats_hp.setPosition(view_x - 690, view_y - 511);
        player_stats_mp.setPosition(view_x - 690, view_y - 443);
        player_stats_lvl.setPosition(view_x - 690, view_y - 375);
        text_NPC_talk.setPosition(view_x - 495, view_y + 85);
        text_target.setPosition(view_x + 700, view_y - 500);
        text_strength.setPosition(view_x - 900, view_y - 260);
        text_damage.setPosition(view_x - 900, view_y - 220);
        text_armor.setPosition(view_x - 900, view_y - 180);
        text_magic.setPosition(view_x - 900, view_y - 140);
        text_critical_chance.setPosition(view_x - 900, view_y - 100);
        text_magic_resistance.setPosition(view_x - 900, view_y - 60);
        text_physical_resistance.setPosition(view_x - 900, view_y - 20);
        text_magic_ice.setPosition(view_x - 900, view_y + 20);
        text_magic_fire.setPosition(view_x - 900, view_y + 60);
        text_magic_earth.setPosition(view_x - 900, view_y + 100);
        text_magic_wind.setPosition(view_x - 900, view_y + 140);
        text_magic_dark.setPosition(view_x - 900, view_y + 180);
        text_magic_light.setPosition(view_x - 900, view_y + 220);
        text_melee_weapon.setPosition(view_x - 900, view_y + 260);
        text_range_weapon.setPosition(view_x - 900, view_y + 300);
    }
    void setText(auto& text, auto& font, auto size) {
        text.setFont(font);
        text.setString("");
        text.setCharacterSize(size);
    }
    void guiTarget(auto& game) {
        if (game.target_m != NULL) {
            std::stringstream ss;
            std::stringstream ss2;
            std::string t_lvl;
            std::string t_hp;
            std::string t_name;
    	    ss<<game.target_m->getLVL();
    	    ss>>t_lvl;
            ss2<<game.target_m->getHP();
            ss2>>t_hp;
            t_name = game.target_m->getName();
            text_target.setString("TARGET: " + t_name + "\nLVL: " + t_lvl + "\nHP: " + t_hp);
        } else {
            text_target.setString("");
        }
    }
};
