class TextUpdater {
protected:
    void updateText(float time, auto& game) {
        auto& text_manager = game.renderer->text_manager;
        float view_x = game.window_manager->viewGetCenterX();
        float view_y = game.window_manager->viewGetCenterY();
        float get_pos_x = game.player->getX()+50;
        float get_pos_y = game.player->getY()-10;

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
            game.renderer->text_manager->text_target.setString("TARGET: " + t_name + "\nLVL: " + t_lvl + "\nHP: " + t_hp);
        } else {
            game.renderer->text_manager->text_target.setString("");
        }

        for (auto& i: text_manager->text_cd) {
            i.setColor(Color::White);
            i.setStyle(Text::Bold);
        }
        text_manager->text_target.setColor(Color::White);
        text_manager->player_stats_hp.setColor(Color::White);
        text_manager->player_stats_mp.setColor(Color::White);
        text_manager->player_stats_lvl.setColor(Color::White);
        text_manager->text_target.setStyle(Text::Bold);
        text_manager->player_stats_hp.setStyle(Text::Bold);
        text_manager->player_stats_mp.setStyle(Text::Bold);
        text_manager->player_stats_lvl.setStyle(Text::Bold);

        std::string p_lvl = std::to_string(game.player->lvl);
        std::string p_hp = std::to_string(game.player->hp);
        std::string p_mp = std::to_string(game.player->mp);
        std::string p_xp = std::to_string(game.player->xp);
        std::string p_hr = std::to_string(game.player->hp_regen);
        std::string p_mr = std::to_string(game.player->mp_regen);
        text_manager->player_stats_hp.setString(p_hp + " +" + p_hr[0] + p_hr[1] + p_hr[2]);
        text_manager->player_stats_mp.setString(p_mp + " +" + p_mr[0] + p_mr[1] + p_mr[2]);
        text_manager->player_stats_lvl.setString(p_lvl + " (" + p_xp + "/" + p_lvl + "00)");
        for (int i = 0; i < 9; i++) {
            text_manager->text_cd[i].setPosition(view_x - 490 + 112 * i, view_y + 404);
            if (game.player->cooldowns[i] != 0) {
                text_manager->text_cd[i].setString(std::to_string(game.player->cooldowns[i]/1000));
            } else {
                text_manager->text_cd[i].setString("");
            }
        }

        auto value = std::to_string(int(game.player->shield_cd/100)/10.0);
        value = value.erase(value.size() - 5);
        text_manager->text_dynamic_shield_cd->update(time, get_pos_x, get_pos_y, value);

        for (auto& v: text_manager->v_dynamic_texts) {
            v.update(time);
        }

        text_manager->player_stats_hp.setPosition(view_x - 690, view_y - 511);
        text_manager->player_stats_mp.setPosition(view_x - 690, view_y - 443);
        text_manager->player_stats_lvl.setPosition(view_x - 690, view_y - 375);
        text_manager->text_NPC_talk.setPosition(view_x - 495, view_y + 85);
        text_manager->text_target.setPosition(view_x + 700, view_y - 500);
        text_manager->text_strength.setPosition(view_x - 900, view_y - 260);
        text_manager->text_damage.setPosition(view_x - 900, view_y - 220);
        text_manager->text_armor.setPosition(view_x - 900, view_y - 180);
        text_manager->text_magic.setPosition(view_x - 900, view_y - 140);
        text_manager->text_critical_chance.setPosition(view_x - 900, view_y - 100);
        text_manager->text_magic_resistance.setPosition(view_x - 900, view_y - 60);
        text_manager->text_physical_resistance.setPosition(view_x - 900, view_y - 20);
        text_manager->text_magic_ice.setPosition(view_x - 900, view_y + 20);
        text_manager->text_magic_fire.setPosition(view_x - 900, view_y + 60);
        text_manager->text_magic_earth.setPosition(view_x - 900, view_y + 100);
        text_manager->text_magic_wind.setPosition(view_x - 900, view_y + 140);
        text_manager->text_magic_dark.setPosition(view_x - 900, view_y + 180);
        text_manager->text_magic_light.setPosition(view_x - 900, view_y + 220);
        text_manager->text_melee_weapon.setPosition(view_x - 900, view_y + 260);
        text_manager->text_range_weapon.setPosition(view_x - 900, view_y + 300);
    }
};
