class SpriteDrawer: virtual public SpriteInitializer, virtual public SpriteLoader {
public:
    void drawSprites(auto& game) {
        int index = 0;
        bool a = game.player->is_inventory_open;
        bool b = game.player->is_spells_inventory_open;
        bool c = game.player->is_stats_open;
        bool d = game.player->is_dialog;
        for (int i = 0; i < game.map->getMapHeight(); i++) {
            for (int j = 0; j < game.map->getMapWidth(); j++) {
                game.map->defineTile(i, j);
                game.map->setSpritePosition(j * 64, i * 64);
                game.window_manager->windowDraw(game.map->getSprite());
            }
        }
        for (auto& i_sprite: current_item_sprites) {
            game.window_manager->windowDraw(i_sprite);
        }
        for (auto& i_sprite: current_other_sprites) {
            game.window_manager->windowDraw(i_sprite);
        }
        game.window_manager->windowDraw(game.player->getSprite());

        if (game.player->attack_animation != 0) {
            game.window_manager->windowDraw(AnimationWeaponSprite);
        }
        if (game.player->defence && game.player->inv_items[28] != 0) {
            game.window_manager->windowDraw(AnimationShieldSprite);
        }
        if (game.player->dash_timer > 0) {
            game.window_manager->windowDraw(AnimationDashSprite);
        }
        if (500 <= game.player->space_timer && game.player->space_timer <= 750) {
            game.window_manager->windowDraw(GuiIndicatorSprite);
        }
        for (auto& i_sprite: gui_sprites) { //TODO: replace with unique names so there won't be any "a", "b", "c" etc.
            bool i1 = index != 1;
            bool i2 = index != 2;
            bool i4 = index != 4;
            bool i5 = index != 5;
            bool e = a && i2 && i4 && i5;
            bool f = b && i1 && i4 && i5;
            bool g = c && i1 && i2 && i5;
            bool h = d && i1 && i2 && i4;
            if ((i1 && i2 && i4 && i5) || e || f || g || h) {
                game.window_manager->windowDraw(i_sprite);
            }
            index++;
        }
        if (a && !b) {
            for (auto& i_sprite: InventoryItemsSprite) {
                game.window_manager->windowDraw(i_sprite);
            }
            for (auto& i_sprite: GuiEquipmentSprites) {
                game.window_manager->windowDraw(i_sprite);
            }
        }
        if (!a && b) {
            for (auto& i_sprite: SpellsInventorySprite) {
                game.window_manager->windowDraw(i_sprite);
            }
        }
        for (auto& i_sprite: SpellsHotbarSprites) {
            game.window_manager->windowDraw(i_sprite);
        }
        if (game.renderer->text_info.getString() != "") {
            game.window_manager->windowDraw(GuiInfoSprite);
        }
        if (game.player->aiming) {
            game.window_manager->windowDraw(GuiPickedSpellSprite);
        }
        for (auto& i: GuiNoManaSprites) {
            game.window_manager->windowDraw(i);
        }
        for (auto& i: game.renderer->text_cd) {
            game.window_manager->windowDraw(i);
        }
        game.window_manager->windowDraw(game.renderer->player_stats_hp);
        game.window_manager->windowDraw(game.renderer->player_stats_mp);
        game.window_manager->windowDraw(game.renderer->player_stats_lvl);
        game.window_manager->windowDraw(game.renderer->text_target);
        game.window_manager->windowDraw(game.renderer->text_strength);
        game.window_manager->windowDraw(game.renderer->text_damage);
        game.window_manager->windowDraw(game.renderer->text_armor);
        game.window_manager->windowDraw(game.renderer->text_magic);
        game.window_manager->windowDraw(game.renderer->text_critical_chance);
        game.window_manager->windowDraw(game.renderer->text_magic_resistance);
        game.window_manager->windowDraw(game.renderer->text_physical_resistance);
        game.window_manager->windowDraw(game.renderer->text_magic_ice);
        game.window_manager->windowDraw(game.renderer->text_magic_fire);
        game.window_manager->windowDraw(game.renderer->text_magic_earth);
        game.window_manager->windowDraw(game.renderer->text_magic_wind);
        game.window_manager->windowDraw(game.renderer->text_magic_dark);
        game.window_manager->windowDraw(game.renderer->text_magic_light);
        game.window_manager->windowDraw(game.renderer->text_melee_weapon);
        game.window_manager->windowDraw(game.renderer->text_range_weapon);
        game.window_manager->windowDraw(game.renderer->text_info);
        game.window_manager->windowDraw(game.renderer->text_NPC_talk);
        for (auto& i: game.renderer->v_dynamic_texts) {
            if (i.getTimer() > 0) {
                Text temp_text = i.getText();
                temp_text.setFont(i.getFont());
                game.window_manager->windowDraw(temp_text);
            }
        }
        if (!game.player->defence && game.renderer->text_dynamic_shield_cd->getTimer() > 0) {
            Text temp_text = game.renderer->text_dynamic_shield_cd->getText();
            temp_text.setFont(game.renderer->text_dynamic_shield_cd->getFont());
            game.window_manager->windowDraw(temp_text);
        }
    }
};
