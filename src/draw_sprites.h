void draw_sprites(auto& get_window) {
    for (int i = 0; i < HEIGHT_MAP; i++) {
        for (int j = 0; j < WIDTH_MAP; j++) {
            defineTile(i, j);
            map_sprite.setPosition(j * 64, i * 64);
            get_window.draw(map_sprite);
        }
    }
    for (int lol = 0; lol < other_sprites.size(); lol++) {
        get_window.draw(other_sprites[lol]);
    }
    get_window.draw(herosprite);
    if (attack_animation != 0) {
        get_window.draw(AnimationWoodenSwordSprite);
    }
    if (defence && inv_items[28] != 0) {
        get_window.draw(EquipedShieldSprite);
    }
    get_window.draw(GuiSpellsHotbarSprite);
    for (int i = 0; i < 9; i++) {
        get_window.draw(SpellsHotbarSprites[i]);
    }
    if (is_dialog) {
        get_window.draw(NPCTalkSprite);
    }
    if (aiming) {
        get_window.draw(GuiPickedSpellSprite);
    }
    if (is_inventory_open) {
        get_window.draw(GuiInventorySprite);
        get_window.draw(InventoryItemWeaponSprite);
        get_window.draw(InventoryItemShieldSprite);
        get_window.draw(InventoryItemChestSprite);
        get_window.draw(InventoryItemHelmSprite);
        get_window.draw(InventoryItemPantsSprite);
        get_window.draw(InventoryItemBootsSprite);
        for (int i = 0; i < 27; i++) {
            get_window.draw(InventoryItemsSprite[i]);
        }
    }
    if (is_spells_inventory_open) {
        get_window.draw(GuiSpellsInventorySprite);
        for (int i = 0; i < 27; i++) {
            get_window.draw(SpellsInventoryPageSprite[i]);
        }
    }
    get_window.draw(GuiBarSprite);
    if (is_stats_open) {
        get_window.draw(GuiStatsSprite);
    }
    if (text_item_info.getString() != "") {
        get_window.draw(GuiInfoSprite);
    }
    get_window.draw(text_cd_0);
    get_window.draw(text_cd_1);
    get_window.draw(text_cd_2);
    get_window.draw(text_cd_3);
    get_window.draw(text_cd_4);
    get_window.draw(text_cd_5);
    get_window.draw(text_cd_6);
    get_window.draw(text_cd_7);
    get_window.draw(text_cd_8);
    get_window.draw(text_strength);
    get_window.draw(text_damage);
    get_window.draw(text_armor);
    get_window.draw(text_magic);
    get_window.draw(text_critical_chance);
    get_window.draw(text_magic_resistance);
    get_window.draw(text_physical_resistance);
    get_window.draw(text_magic_ice);
    get_window.draw(text_magic_fire);
    get_window.draw(text_magic_earth);
    get_window.draw(text_magic_wind);
    get_window.draw(text_magic_dark);
    get_window.draw(text_magic_light);
    get_window.draw(text_melee_weapon);
    get_window.draw(text_range_weapon);
    get_window.draw(text_item_info);
    get_window.draw(text);
    get_window.draw(player_stats_hp);
    get_window.draw(player_stats_mp);
    get_window.draw(player_stats_lvl);
    get_window.display();
}
