void draw_sprites(RenderWindow& window) {
    for (int i = 0; i < HEIGHT_MAP; i++) {
        for (int j = 0; j < WIDTH_MAP; j++) {
            defineTile(i, j);
            map_sprite.setPosition((float)j * 64, (float)i * 64);
            window.draw(map_sprite);
        }
    }
    for (auto& sprite : other_sprites)
    {
        window.draw(sprite);
    }
    window.draw(herosprite);
    if (attack_animation != 0) {
        window.draw(AnimationWoodenSwordSprite);
    }
    if (defence && inv_items[28] != 0) {
        window.draw(EquipedShieldSprite);
    }
    window.draw(GuiSpellsHotbarSprite);
    for (auto& sprite : SpellsHotbarSprites)
    {
        window.draw(sprite);
    }
    if (is_dialog) {
        window.draw(NPCTalkSprite);
    }
    if (aiming) {
        window.draw(GuiPickedSpellSprite);
    }
    if (is_inventory_open) {
        window.draw(GuiInventorySprite);
        window.draw(InventoryItemWeaponSprite);
        window.draw(InventoryItemShieldSprite);
        window.draw(InventoryItemChestSprite);
        window.draw(InventoryItemHelmSprite);
        window.draw(InventoryItemPantsSprite);
        window.draw(InventoryItemBootsSprite);

        for (auto& sprite : InventoryItemsSprite)
        {
            window.draw(sprite);
        }
    }
    if (is_spells_inventory_open)
    {
        window.draw(GuiSpellsInventorySprite);
        for (auto& sprite : SpellsInventoryPageSprite)
        {
            window.draw(sprite);
        }
    }
    window.draw(GuiBarSprite);
    if (is_stats_open) { window.draw(GuiStatsSprite); }
    if (text_item_info.getString() != "") { window.draw(GuiInfoSprite); }

    window.draw(text_cd_0);
    window.draw(text_cd_1);
    window.draw(text_cd_2);
    window.draw(text_cd_3);
    window.draw(text_cd_4);
    window.draw(text_cd_5);
    window.draw(text_cd_6);
    window.draw(text_cd_7);
    window.draw(text_cd_8);
    window.draw(text_strength);
    window.draw(text_damage);
    window.draw(text_armor);
    window.draw(text_magic);
    window.draw(text_critical_chance);
    window.draw(text_magic_resistance);
    window.draw(text_physical_resistance);
    window.draw(text_magic_ice);
    window.draw(text_magic_fire);
    window.draw(text_magic_earth);
    window.draw(text_magic_wind);
    window.draw(text_magic_dark);
    window.draw(text_magic_light);
    window.draw(text_melee_weapon);
    window.draw(text_range_weapon);
    window.draw(text_item_info);
    window.draw(text);
    window.draw(player_stats_hp);
    window.draw(player_stats_mp);
    window.draw(player_stats_lvl);
    window.display();
}
