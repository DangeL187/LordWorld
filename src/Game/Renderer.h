class Renderer: public WindowManager {
public:
    //TODO: unite in images.png:
    Sprite ColdSnapSprite;
    Sprite ColdSnap2Sprite;
    Sprite AnimationWoodenSwordSprite;
    Sprite AnimationIronShieldSprite;
    //initialized sprites:
    std::vector<Sprite> gui_sprites;
    std::vector<Sprite> item_sprites;
    std::vector<Sprite> NPC_sprites;
    std::vector<Sprite> monster_sprites;
    //current sprites:
    std::vector<Sprite> current_item_sprites;
    std::vector<Sprite> current_other_sprites;
    Sprite GuiIndicatorSprite;
    Sprite GuiInfoSprite;
    Sprite GuiPickedSpellSprite;
    Sprite GuiEquipmentSprites[6];
    Sprite InventoryItemsSprite[27];
    Sprite SpellsInventorySprite[24];
    Sprite SpellsHotbarSprites[9];
    Sprite InventoryItemEmptySprite;
    Sprite AnimationWeaponSprite;
    Sprite AnimationShieldSprite;
    Sprite AnimationDashSprite;
    int item_sprite_counter = 0;
    int other_sprite_counter = 0;
    //text:
    Font font;
    Text text_cd_0;
    Text text_cd_1;
    Text text_cd_2;
    Text text_cd_3;
    Text text_cd_4;
    Text text_cd_5;
    Text text_cd_6;
    Text text_cd_7;
    Text text_cd_8;
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
protected:
    void createMapSprite(auto& map_manager) {
        map_manager.setSprite(createSprite("map.png"));
    }
    void createItemSprites() {
        item_sprites.push_back(createSprite("Wooden Sword.png"));
        item_sprites.push_back(createSprite("Iron Shield.png"));
        item_sprites.push_back(createSprite("Iron Helmet.png"));
        item_sprites.push_back(createSprite("Iron Chestplate.png"));
        item_sprites.push_back(createSprite("Iron Pants.png"));
        item_sprites.push_back(createSprite("Iron Boots.png"));
        item_sprites.push_back(createSprite("Iron Ring.png"));
        item_sprites.push_back(createSprite("Rat Tail.png"));
    }
    void createMonsterSprites() {
        monster_sprites.push_back(createSprite("Rat.png"));
        monster_sprites.push_back(createSprite("Rat2.png"));
    }
    void createNPCSprites() {
        NPC_sprites.push_back(createSprite("hero.png"));
    }
    void createGuiSprites() {
        gui_sprites.push_back(createSprite("GuiBar.png"));
        gui_sprites.push_back(createSprite("GuiInventory.png"));
        gui_sprites.push_back(createSprite("GuiSpellsInventory.png"));
        gui_sprites.push_back(createSprite("GuiSpellsHotbar.png"));
        gui_sprites.push_back(createSprite("GuiStats.png"));
        gui_sprites.push_back(createSprite("NPCTalk.png"));
        GuiIndicatorSprite = createSprite("GuiIndicator.png");
        GuiInfoSprite = createSprite("GuiInfo.png");
        GuiPickedSpellSprite = createSprite("GuiPickedSpell.png");
    }
    void initText(auto& player) {
        font.loadFromFile("../font/OceanSummer.ttf");
        setText(text_cd_0, font, 60);
        setText(text_cd_1, font, 60);
        setText(text_cd_2, font, 60);
        setText(text_cd_3, font, 60);
        setText(text_cd_4, font, 60);
        setText(text_cd_5, font, 60);
        setText(text_cd_6, font, 60);
        setText(text_cd_7, font, 60);
        setText(text_cd_8, font, 60);
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
    }
    void initImages() {
        ColdSnapSprite = createSprite("ColdSnap.png");
        ColdSnap2Sprite = createSprite("ColdSnap2.png");
        AnimationDashSprite = createSprite("AnimationDash.png");
        AnimationWoodenSwordSprite = createSprite("AnimationWoodenSword.png");
        AnimationIronShieldSprite = createSprite("AnimationIronShield.png");

        AnimationWeaponSprite = createSprite("GuiEmptyItem.png");
        AnimationShieldSprite = createSprite("GuiEmptyItem.png");
        InventoryItemEmptySprite = createSprite("GuiEmptyItem.png");
        GuiEquipmentSprites[0] = createSprite("GuiSlotWeapon.png");
        GuiEquipmentSprites[1] = createSprite("GuiSlotShield.png");
        GuiEquipmentSprites[2] = createSprite("GuiSlotHelm.png");
        GuiEquipmentSprites[3] = createSprite("GuiSlotChest.png");
        GuiEquipmentSprites[4] = createSprite("GuiSlotPants.png");
        GuiEquipmentSprites[5] = createSprite("GuiSlotBoots.png");
        for (int i = 0; i < 27; i++) {
            InventoryItemsSprite[i] = createSprite("GuiEmptyItem.png");
            //SpellsInventoryPageImage[i] = createSprite("GuiEmptyItem.png");
        }
    }
    void updateGuiSprites(auto& player) {
        gui_sprites[0].setPosition(view.getCenter().x - 960, view.getCenter().y - 540);
        gui_sprites[1].setPosition(view.getCenter().x - 300, view.getCenter().y - 400);
        gui_sprites[2].setPosition(view.getCenter().x - 300, view.getCenter().y - 496);
        gui_sprites[3].setPosition(view.getCenter().x - 540, view.getCenter().y + 380);
        gui_sprites[4].setPosition(view.getCenter().x - 920, view.getCenter().y - 310);
        gui_sprites[5].setPosition(view.getCenter().x - 540, view.getCenter().y + 80);

        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 4; j++) {
                float condix1 = view.getCenter().x + 261 - 15 + 112 * j;
                float condiy1 = view.getCenter().y - 343 - 15 + 112 * i;
                float condix2 = view.getCenter().x + 231 + 112 * j;
                float condiy2 = view.getCenter().y - 373 + 112 * i;
                InventoryItemsSprite[i * 4 + j].setPosition(condix1, condiy1);
                SpellsInventorySprite[i * 4 + j].setPosition(condix2+5, condiy2);
            }
        }

        for (int i = 0; i < 9; i++) {
            SpellsHotbarSprites[i].setPosition(view.getCenter().x - 536 + 112 * i, view.getCenter().y + 384);
        }
        if (player->aiming && player->spell_slot == 0) {
            GuiPickedSpellSprite.setPosition(view.getCenter().x - 536, view.getCenter().y + 384);
        }
        if (player->aiming && player->spell_slot == 1) {
            GuiPickedSpellSprite.setPosition(view.getCenter().x - 536 + 112, view.getCenter().y + 384);
        }
        if (player->aiming && player->spell_slot == 2) {
            GuiPickedSpellSprite.setPosition(view.getCenter().x - 536 + 112 * 2, view.getCenter().y + 384);
        }
        if (player->aiming && player->spell_slot == 3) {
            GuiPickedSpellSprite.setPosition(view.getCenter().x - 536 + 112 * 3, view.getCenter().y + 384);
        }
        if (player->aiming && player->spell_slot == 4) {
            GuiPickedSpellSprite.setPosition(view.getCenter().x - 536 + 112 * 4, view.getCenter().y + 384);
        }
        if (player->aiming && player->spell_slot == 5) {
            GuiPickedSpellSprite.setPosition(view.getCenter().x - 536 + 112 * 5, view.getCenter().y + 384);
        }
        if (player->aiming && player->spell_slot == 6) {
            GuiPickedSpellSprite.setPosition(view.getCenter().x - 536 + 112 * 6, view.getCenter().y + 384);
        }
        if (player->aiming && player->spell_slot == 7) {
            GuiPickedSpellSprite.setPosition(view.getCenter().x - 536 + 112 * 7, view.getCenter().y + 384);
        }
        if (player->aiming && player->spell_slot == 8) {
            GuiPickedSpellSprite.setPosition(view.getCenter().x - 536 + 112 * 8, view.getCenter().y + 384);
        }

        if (player->inv_items[27] != 0) {
            GuiEquipmentSprites[0].setPosition(view.getCenter().x - 231 - 15, view.getCenter().y - 227 - 15);
        } else {
            GuiEquipmentSprites[0].setPosition(view.getCenter().x - 231 - 29, view.getCenter().y - 227 - 29);
        }
        if (player->inv_items[28] != 0) {
            GuiEquipmentSprites[1].setPosition(view.getCenter().x + 89 - 15, view.getCenter().y - 227 - 15);
        } else {
            GuiEquipmentSprites[1].setPosition(view.getCenter().x + 89 - 29, view.getCenter().y - 227 - 29);
        }
        if (player->inv_items[29] != 0) {
            GuiEquipmentSprites[2].setPosition(view.getCenter().x - 71 - 15, view.getCenter().y - 351 - 15);
        } else {
            GuiEquipmentSprites[2].setPosition(view.getCenter().x - 71 - 29, view.getCenter().y - 351 - 29);
        }
        if (player->inv_items[30] != 0) {
            GuiEquipmentSprites[3].setPosition(view.getCenter().x - 71 - 15, view.getCenter().y - 227 - 15);
        } else {
            GuiEquipmentSprites[3].setPosition(view.getCenter().x - 71 - 29, view.getCenter().y - 227 - 29);
        }
        if (player->inv_items[31] != 0) {
            GuiEquipmentSprites[4].setPosition(view.getCenter().x - 71 - 15, view.getCenter().y - 103 - 15);
        } else {
            GuiEquipmentSprites[4].setPosition(view.getCenter().x - 71 - 29, view.getCenter().y - 103 - 29);
        }
        if (player->inv_items[32] != 0) {
            GuiEquipmentSprites[5].setPosition(view.getCenter().x - 71 - 15, view.getCenter().y + 21 - 15);
        } else {
            GuiEquipmentSprites[5].setPosition(view.getCenter().x - 71 - 29, view.getCenter().y + 21 - 29);
        }
        InventoryItemsSprite[24].setPosition(view.getCenter().x - 203 - 15, view.getCenter().y + 185 - 15);
        InventoryItemsSprite[25].setPosition(view.getCenter().x - 71 - 15, view.getCenter().y + 185 - 15);
        InventoryItemsSprite[26].setPosition(view.getCenter().x + 61 - 15, view.getCenter().y + 185 - 15);

        GuiIndicatorSprite.setPosition(player->getX()+18, player->getY()-34);
    }
    void updateText(auto& player) {
        text_cd_0.setColor(Color::White);
        text_cd_1.setColor(Color::White);
        text_cd_2.setColor(Color::White);
        text_cd_3.setColor(Color::White);
        text_cd_4.setColor(Color::White);
        text_cd_5.setColor(Color::White);
        text_cd_6.setColor(Color::White);
        text_cd_7.setColor(Color::White);
        text_cd_8.setColor(Color::White);
        text_target.setColor(Color::White);
        player_stats_hp.setColor(Color::White);
        player_stats_mp.setColor(Color::White);
        player_stats_lvl.setColor(Color::White);
        text_cd_0.setStyle(Text::Bold);
        text_cd_1.setStyle(Text::Bold);
        text_cd_2.setStyle(Text::Bold);
        text_cd_3.setStyle(Text::Bold);
        text_cd_4.setStyle(Text::Bold);
        text_cd_5.setStyle(Text::Bold);
        text_cd_6.setStyle(Text::Bold);
        text_cd_7.setStyle(Text::Bold);
        text_cd_8.setStyle(Text::Bold);
        text_target.setStyle(Text::Bold);
        player_stats_hp.setStyle(Text::Bold);
        player_stats_mp.setStyle(Text::Bold);
        player_stats_lvl.setStyle(Text::Bold);
        std::string p_lvl = std::to_string(player->lvl);
        std::string p_hp = std::to_string(player->hp);
        std::string p_mp = std::to_string(player->mp);
        std::string p_xp = std::to_string(player->xp);
        std::string p_hr = std::to_string(player->hp_regen);
        std::string p_mr = std::to_string(player->mp_regen);
        player_stats_hp.setString(p_hp + " +" + p_hr[0] + p_hr[1] + p_hr[2]);
        player_stats_mp.setString(p_mp + " +" + p_mr[0] + p_mr[1] + p_mr[2]);
        player_stats_lvl.setString(p_lvl + " (" + p_xp + "/" + p_lvl + "00)");
        if (player->cooldowns[0] != 0) {
            text_cd_0.setString(std::to_string(player->cooldowns[0]/1000));
        } else {
            text_cd_0.setString("");
        }
        if (player->cooldowns[1] != 0) {
            text_cd_1.setString(std::to_string(player->cooldowns[1]/1000));
        } else {
            text_cd_1.setString("");
        }
        if (player->cooldowns[2] != 0) {
            text_cd_2.setString(std::to_string(player->cooldowns[2]/1000));
        } else {
            text_cd_2.setString("");
        }
        if (player->cooldowns[3] != 0) {
            text_cd_3.setString(std::to_string(player->cooldowns[3]/1000));
        } else {
            text_cd_3.setString("");
        }
        if (player->cooldowns[4] != 0) {
            text_cd_4.setString(std::to_string(player->cooldowns[4]/1000));
        } else {
            text_cd_4.setString("");
        }
        if (player->cooldowns[5] != 0) {
            text_cd_5.setString(std::to_string(player->cooldowns[5]/1000));
        } else {
            text_cd_5.setString("");
        }
        if (player->cooldowns[6] != 0) {
            text_cd_6.setString(std::to_string(player->cooldowns[6]/1000));
        } else {
            text_cd_6.setString("");
        }
        if (player->cooldowns[7] != 0) {
            text_cd_7.setString(std::to_string(player->cooldowns[7]/1000));
        } else {
            text_cd_7.setString("");
        }
        if (player->cooldowns[8] != 0) {
            text_cd_8.setString(std::to_string(player->cooldowns[8]/1000));
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
        player_stats_hp.setPosition(view.getCenter().x - 690, view.getCenter().y - 511);
        player_stats_mp.setPosition(view.getCenter().x - 690, view.getCenter().y - 443);
        player_stats_lvl.setPosition(view.getCenter().x - 690, view.getCenter().y - 375);
        text_NPC_talk.setPosition(view.getCenter().x - 495, view.getCenter().y + 85);
        text_target.setPosition(view.getCenter().x + 700, view.getCenter().y - 500);
        text_strength.setPosition(view.getCenter().x - 900, view.getCenter().y - 260);
        text_damage.setPosition(view.getCenter().x - 900, view.getCenter().y - 220);
    	text_armor.setPosition(view.getCenter().x - 900, view.getCenter().y - 180);
    	text_magic.setPosition(view.getCenter().x - 900, view.getCenter().y - 140);
    	text_critical_chance.setPosition(view.getCenter().x - 900, view.getCenter().y - 100);
        text_magic_resistance.setPosition(view.getCenter().x - 900, view.getCenter().y - 60);
        text_physical_resistance.setPosition(view.getCenter().x - 900, view.getCenter().y - 20);
        text_magic_ice.setPosition(view.getCenter().x - 900, view.getCenter().y + 20);
    	text_magic_fire.setPosition(view.getCenter().x - 900, view.getCenter().y + 60);
        text_magic_earth.setPosition(view.getCenter().x - 900, view.getCenter().y + 100);
        text_magic_wind.setPosition(view.getCenter().x - 900, view.getCenter().y + 140);
        text_magic_dark.setPosition(view.getCenter().x - 900, view.getCenter().y + 180);
        text_magic_light.setPosition(view.getCenter().x - 900, view.getCenter().y + 220);
        text_melee_weapon.setPosition(view.getCenter().x - 900, view.getCenter().y + 260);
        text_range_weapon.setPosition(view.getCenter().x - 900, view.getCenter().y + 300);
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
