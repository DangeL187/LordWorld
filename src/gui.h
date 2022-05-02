void gui() {
    std::stringstream ss; std::stringstream ss2; std::stringstream ss3;
    std::string p_lvl; std::string p_hp; std::string p_mp;
    ss<<player_lvl;
    ss>>p_lvl;
    ss2<<player_hp;
    ss2>>p_hp;
    ss3<<player_mp;
    ss3>>p_mp;
    std::string phr = std::to_string(hp_regen);
    std::string pmr = std::to_string(mp_regen);
    player_stats_hp.setString(p_hp + " +" + phr[0] + phr[1] + phr[2]);
    player_stats_mp.setString(p_mp + " +" + pmr[0] + pmr[1] + pmr[2]);
    player_stats_lvl.setString(p_lvl);
    player_stats_hp.setPosition(view.getCenter().x - 690, view.getCenter().y - 511);
    player_stats_mp.setPosition(view.getCenter().x - 690, view.getCenter().y - 443);
    player_stats_lvl.setPosition(view.getCenter().x - 690, view.getCenter().y - 375);
    text.setPosition(view.getCenter().x + 700, view.getCenter().y - 500);
    if (cooldowns[0] != 0) {
        text_cd_0.setString(std::to_string(cooldowns[0]/1000));
    } else {
        text_cd_0.setString("");
    }
    if (cooldowns[1] != 0) {
        text_cd_1.setString(std::to_string(cooldowns[1]/1000));
    } else {
        text_cd_1.setString("");
    }
    if (cooldowns[2] != 0) {
        text_cd_2.setString(std::to_string(cooldowns[2]/1000));
    } else {
        text_cd_2.setString("");
    }
    if (cooldowns[3] != 0) {
        text_cd_3.setString(std::to_string(cooldowns[3]/1000));
    } else {
        text_cd_3.setString("");
    }
    if (cooldowns[4] != 0) {
        text_cd_4.setString(std::to_string(cooldowns[4]/1000));
    } else {
        text_cd_4.setString("");
    }
    if (cooldowns[5] != 0) {
        text_cd_5.setString(std::to_string(cooldowns[5]/1000));
    } else {
        text_cd_5.setString("");
    }
    if (cooldowns[6] != 0) {
        text_cd_6.setString(std::to_string(cooldowns[6]/1000));
    } else {
        text_cd_6.setString("");
    }
    if (cooldowns[7] != 0) {
        text_cd_7.setString(std::to_string(cooldowns[7]/1000));
    } else {
        text_cd_7.setString("");
    }
    if (cooldowns[8] != 0) {
        text_cd_8.setString(std::to_string(cooldowns[8]/1000));
    } else {
        text_cd_8.setString("");
    }
    text_cd_0.setPosition(view.getCenter().x - 490, view.getCenter().y + 404);
    text_cd_1.setPosition(view.getCenter().x - 380, view.getCenter().y + 404);
    text_cd_2.setPosition(view.getCenter().x - 265, view.getCenter().y + 404);
    text_cd_3.setPosition(view.getCenter().x - 155, view.getCenter().y + 404);
    text_cd_4.setPosition(view.getCenter().x - 45, view.getCenter().y + 404);
    text_cd_5.setPosition(view.getCenter().x + 70, view.getCenter().y + 404);
    text_cd_6.setPosition(view.getCenter().x + 180, view.getCenter().y + 404);
    text_cd_7.setPosition(view.getCenter().x + 295, view.getCenter().y + 404);
    text_cd_8.setPosition(view.getCenter().x + 405, view.getCenter().y + 404);

    text_strength.setPosition(view.getCenter().x - 900, view.getCenter().y - 300);
    text_damage.setPosition(view.getCenter().x - 900, view.getCenter().y - 260);
	text_armor.setPosition(view.getCenter().x - 900, view.getCenter().y - 220);
	text_magic.setPosition(view.getCenter().x - 900, view.getCenter().y - 180);
	text_critical_chance.setPosition(view.getCenter().x - 900, view.getCenter().y - 140);
	text_magic_resistance.setPosition(view.getCenter().x - 900, view.getCenter().y - 100);
	text_physical_resistance.setPosition(view.getCenter().x - 900, view.getCenter().y - 60);
	text_magic_ice.setPosition(view.getCenter().x - 900, view.getCenter().y - 20);
	text_magic_fire.setPosition(view.getCenter().x - 900, view.getCenter().y + 20);
	text_magic_earth.setPosition(view.getCenter().x - 900, view.getCenter().y + 60);
	text_magic_wind.setPosition(view.getCenter().x - 900, view.getCenter().y + 100);
	text_magic_dark.setPosition(view.getCenter().x - 900, view.getCenter().y + 140);
	text_magic_light.setPosition(view.getCenter().x - 900, view.getCenter().y + 180);
	text_melee_weapon.setPosition(view.getCenter().x - 900, view.getCenter().y + 220);
	text_range_weapon.setPosition(view.getCenter().x - 900, view.getCenter().y + 260);

    GuiBarSprite.setPosition(view.getCenter().x - 960, view.getCenter().y - 540);
    GuiInventorySprite.setPosition(view.getCenter().x - 300, view.getCenter().y - 400);
    GuiSpellsInventorySprite.setPosition(view.getCenter().x - 300, view.getCenter().y - 496);
    GuiSpellsHotbarSprite.setPosition(view.getCenter().x - 540, view.getCenter().y + 380);
    GuiStatsSprite.setPosition(view.getCenter().x - 920, view.getCenter().y - 310);

    if (inv_items[27] != 0) {
        InventoryItemWeaponSprite.setPosition(view.getCenter().x - 231 - 15, view.getCenter().y - 227 - 15);
    } else {
        InventoryItemWeaponSprite.setPosition(view.getCenter().x - 231 - 29, view.getCenter().y - 227 - 29);
    }
    if (inv_items[28] != 0) {
        InventoryItemShieldSprite.setPosition(view.getCenter().x + 89 - 15, view.getCenter().y - 227 - 15);
    } else {
        InventoryItemShieldSprite.setPosition(view.getCenter().x + 89 - 29, view.getCenter().y - 227 - 29);
    }
    if (inv_items[29] != 0) {
        InventoryItemHelmSprite.setPosition(view.getCenter().x - 71 - 15, view.getCenter().y - 351 - 15);
    } else {
        InventoryItemHelmSprite.setPosition(view.getCenter().x - 71 - 29, view.getCenter().y - 351 - 29);
    }
    if (inv_items[30] != 0) {
        InventoryItemChestSprite.setPosition(view.getCenter().x - 71 - 15, view.getCenter().y - 227 - 15);
    } else {
        InventoryItemChestSprite.setPosition(view.getCenter().x - 71 - 29, view.getCenter().y - 227 - 29);
    }
    if (inv_items[31] != 0) {
        InventoryItemPantsSprite.setPosition(view.getCenter().x - 71 - 15, view.getCenter().y - 103 - 15);
    } else {
        InventoryItemPantsSprite.setPosition(view.getCenter().x - 71 - 29, view.getCenter().y - 103 - 29);
    }
    if (inv_items[32] != 0) {
        InventoryItemBootsSprite.setPosition(view.getCenter().x - 71 - 15, view.getCenter().y + 21 - 15);
    } else {
        InventoryItemBootsSprite.setPosition(view.getCenter().x - 71 - 29, view.getCenter().y + 21 - 29);
    }
    InventoryItemsSprite[24].setPosition(view.getCenter().x - 203 - 15, view.getCenter().y + 185 - 15);
    InventoryItemsSprite[25].setPosition(view.getCenter().x - 71 - 15, view.getCenter().y + 185 - 15);
    InventoryItemsSprite[26].setPosition(view.getCenter().x + 61 - 15, view.getCenter().y + 185 - 15);
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            float condix1 = view.getCenter().x + 261 - 15 + 112 * j;
            float condiy1 = view.getCenter().y - 343 - 15 + 112 * i;
            float condix2 = view.getCenter().x + 231 + 112 * j;
            float condiy2 = view.getCenter().y - 373 + 112 * i;
            InventoryItemsSprite[i * 4 + j].setPosition(condix1, condiy1);
            SpellsInventoryPageSprite[i * 4 + j].setPosition(condix2, condiy2);
        }
    }
    for (int i = 0; i < 9; i++) {
        SpellsHotbarSprites[i].setPosition(view.getCenter().x - 536 + 112 * i, view.getCenter().y + 384);
    }
    if (aiming && spell_slot == 0) {
        GuiPickedSpellSprite.setPosition(view.getCenter().x - 536, view.getCenter().y + 384);
    }
    if (aiming && spell_slot == 1) {
        GuiPickedSpellSprite.setPosition(view.getCenter().x - 536 + 112, view.getCenter().y + 384);
    }
    if (aiming && spell_slot == 2) {
        GuiPickedSpellSprite.setPosition(view.getCenter().x - 536 + 112 * 2, view.getCenter().y + 384);
    }
    if (aiming && spell_slot == 3) {
        GuiPickedSpellSprite.setPosition(view.getCenter().x - 536 + 112 * 3, view.getCenter().y + 384);
    }
    if (aiming && spell_slot == 4) {
        GuiPickedSpellSprite.setPosition(view.getCenter().x - 536 + 112 * 4, view.getCenter().y + 384);
    }
    if (aiming && spell_slot == 5) {
        GuiPickedSpellSprite.setPosition(view.getCenter().x - 536 + 112 * 5, view.getCenter().y + 384);
    }
    if (aiming && spell_slot == 6) {
        GuiPickedSpellSprite.setPosition(view.getCenter().x - 536 + 112 * 6, view.getCenter().y + 384);
    }
    if (aiming && spell_slot == 7) {
        GuiPickedSpellSprite.setPosition(view.getCenter().x - 536 + 112 * 7, view.getCenter().y + 384);
    }
    if (aiming && spell_slot == 8) {
        GuiPickedSpellSprite.setPosition(view.getCenter().x - 536 + 112 * 8, view.getCenter().y + 384);
    }

}
