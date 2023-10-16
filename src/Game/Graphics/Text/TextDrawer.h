class TextDrawer: virtual public TextInitializer {
public:
    void drawDynamicText(auto& game) {
        for (auto& i: v_dynamic_texts) {
            if (i.getTimer() > 0) {
                Text temp_text = i.getText();
                temp_text.setFont(i.getFont());
                game.window_manager->windowDraw(temp_text);
            }
        }
        if (!game.player->is_defence && text_dynamic_shield_cd->getTimer() > 0) {
            Text temp_text = text_dynamic_shield_cd->getText();
            temp_text.setFont(text_dynamic_shield_cd->getFont());
            game.window_manager->windowDraw(temp_text);
        }
    }
    void drawStatsText(auto& game) {
        for (auto& i: text_cd) {
            game.window_manager->windowDraw(i);
        }
        game.window_manager->windowDraw(player_stats_hp);
        game.window_manager->windowDraw(player_stats_mp);
        game.window_manager->windowDraw(player_stats_lvl);
        game.window_manager->windowDraw(text_target);
        game.window_manager->windowDraw(text_strength);
        game.window_manager->windowDraw(text_damage);
        game.window_manager->windowDraw(text_armor);
        game.window_manager->windowDraw(text_magic);
        game.window_manager->windowDraw(text_critical_chance);
        game.window_manager->windowDraw(text_magic_resistance);
        game.window_manager->windowDraw(text_physical_resistance);
        game.window_manager->windowDraw(text_magic_ice);
        game.window_manager->windowDraw(text_magic_fire);
        game.window_manager->windowDraw(text_magic_earth);
        game.window_manager->windowDraw(text_magic_wind);
        game.window_manager->windowDraw(text_magic_dark);
        game.window_manager->windowDraw(text_magic_light);
        game.window_manager->windowDraw(text_melee_weapon);
        game.window_manager->windowDraw(text_range_weapon);
        game.window_manager->windowDraw(text_info);
    }
    void drawDialogText(auto& game) {
        game.window_manager->windowDraw(text_NPC_talk);
    }
};
