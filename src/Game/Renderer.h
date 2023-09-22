class Renderer {
private:
    //TEST, TEMP, SHADOWS
    /*Sprite ShadowSprite1;
    Sprite ShadowSprite2;
    Sprite ShadowSprite3;
    Sprite ShadowSprite4;
    Sprite LightSprite;
    sf::ConvexShape convex;
    sf::Vertex line1[2];
    sf::Vertex line2[2];
    sf::Vertex line3[2];
    sf::Vertex line4[2];
    sf::Vertex line11[2];
    sf::Vertex line22[2];
    sf::Vertex line33[2];
    sf::Vertex line44[2];*/
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
    Sprite GuiNoManaSprites[9];
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
    std::shared_ptr<DynamicText> text_dynamic_shield_cd;
    std::vector<DynamicText> v_dynamic_texts;
public:
    Renderer(Map& map) {
        initText();
        initImages();
        createMapSprite(map);
        createItemSprites();
        createMonsterSprites();
        createNPCSprites();
        createGuiSprites();
    }

    void createDynamicText(Font font, int size, int timer, std::string value="None", float x=0, float y=0, bool isRed=false) {
        DynamicText dynamic_text(font, size, timer, value, x, y, isRed);
        v_dynamic_texts.push_back(dynamic_text);
    }
    /*float* getShadowEdge(float OX, float OY, float OZ, float LX, float LY, float LZ) { //replace with passing objectSprite and lightCords
        std::cout << std::endl;
        float a = abs(LY - OY);
        float b = abs(LX - OX);
        float c = pow(pow(a, 2) + pow(b, 2), 0.5);
        //a = pow(pow(a, 2) + pow(LZ - OZ, 2), 0.5);
        //c = pow(pow(c, 2) + pow(LZ - OZ, 2), 0.5);
        float angle;
        if (OX <= LX && OY > LY) {
            std::cout << "#=Debug=# 90\n";
            angle = acos(a/c) * 180 / PI + 90;
        }
        else if (OX < LX && OY <= LY) {
            std::cout << "#=Debug=# 180\n";
            angle = acos(b/c) * 180 / PI + 180;
        }
        else if (OX >= LX && OY < LY) {
            std::cout << "#=Debug=# 270\n";
            angle = acos(a/c) * 180 / PI + 270;
        }
        else {
            std::cout << "#=Debug=# 0\n";
            angle = acos(b/c) * 180 / PI;
        }
        std::cout << "#=Debug=# A: " << angle << std::endl;

        float ca = cos(angle * PI / 180);
        float sa = sin(angle * PI / 180);
        std::cout << "#=Debug=# COSa and SINa: " << ca << " " << sa << std::endl;

        float d = pow(pow(OX - LX, 2) + pow(OY - LY, 2), 0.5);
        float x = OZ / (LZ - OZ) * d;
        std::cout << "#=Debug=# SHADOW LEN: " << x << std::endl;
        float y = 0;

        float a11 = ca;
        float a12 = sa;
        float a21 = sa;
        float a22 = ca;

        float B[3] = {a11 * x + a12 * y + OX, a21 * x + a22 * y + OY, x};
        std::cout << "#=Debug=# B: " << B[0] << " " << B[1] << " " << B[2] << std::endl;
        float* p = new float[3];
        p[0] = B[0];
        p[1] = B[1];
        p[2] = B[2];
        return p;
}*/

    void createMapSprite(auto& map) {
        map->setSprite(createSprite("map.png"));
    }
    void createItemSprites() {
        item_sprites.push_back(createSprite("Wooden Sword.png")); //TODO: take names from file
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
        for (auto& i: GuiNoManaSprites) {
            i = createSprite("GuiNoMana.png");
        }
    }
    void initText() {
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
        text_dynamic_shield_cd = std::make_shared<DynamicText>(font, 30);
    }
    void initImages() {
        //shadow: LightSprite = createSprite("GuiIndicator.png");

        ColdSnapSprite = createSprite("ColdSnap.png");
        ColdSnap2Sprite = createSprite("ColdSnap2.png");
        AnimationDashSprite = createSprite("AnimationDash.png");
        AnimationWoodenSwordSprite = createSprite("AnimationWoodenSword.png");
        AnimationIronShieldSprite = createSprite("AnimationIronShield.png");

        InventoryItemEmptySprite = createSprite("GuiEmptyItem.png");
        AnimationWeaponSprite = createSprite("GuiEmptyItem.png");
        AnimationShieldSprite = createSprite("GuiEmptyItem.png");
        GuiEquipmentSprites[0] = createSprite("GuiSlotWeapon.png"); //TODO: replace with unique sprite names
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
    void updateGuiSprites(auto& game) {
        //SHADOW:

        /*LightSprite.setPosition(900, 900);

        float px = player->getX();
        float py = player->getY()+player->getHeight();
        std::cout << "#!\n";
        float* G = getShadowEdge(px, py, player->getHeight(), 300+600, 300+600, 200);
        std::cout << "#!\n";
        float shadow_x = G[0];
        float shadow_y = G[1];
        ShadowSprite1.setPosition(shadow_x, shadow_y);
        line1[0] = sf::Vertex(sf::Vector2f(900, 900));
        line1[1] = sf::Vertex(sf::Vector2f(px, py));
        line11[0] = sf::Vertex(sf::Vector2f(px, py));
        line11[1] = sf::Vertex(sf::Vector2f(shadow_x, shadow_y));

        px = player->getX()+player->getWidth();
        py = player->getY()+player->getHeight();
        G = getShadowEdge(px, py, player->getHeight(), 300+600, 300+600, 200);
        shadow_x = G[0];
        shadow_y = G[1];
        ShadowSprite2.setPosition(shadow_x, shadow_y);
        line2[0] = sf::Vertex(sf::Vector2f(900, 900));
        line2[1] = sf::Vertex(sf::Vector2f(px, py));
        line22[0] = sf::Vertex(sf::Vector2f(px, py));
        line22[1] = sf::Vertex(sf::Vector2f(shadow_x, shadow_y));

        px = player->getX();
        py = player->getY();
        G = getShadowEdge(px, py, player->getHeight(), 300+600, 300+600, 200);
        shadow_x = G[0];
        shadow_y = G[1];
        ShadowSprite3.setPosition(shadow_x, shadow_y);
        line3[0] = sf::Vertex(sf::Vector2f(900, 900));
        line3[1] = sf::Vertex(sf::Vector2f(px, py));
        line33[0] = sf::Vertex(sf::Vector2f(px, py));
        line33[1] = sf::Vertex(sf::Vector2f(shadow_x, shadow_y));

        px = player->getX()+player->getWidth();
        py = player->getY();
        G = getShadowEdge(px, py, player->getHeight(), 300+600, 300+600, 200);
        shadow_x = G[0];
        shadow_y = G[1];
        ShadowSprite4.setPosition(shadow_x, shadow_y);
        line4[0] = sf::Vertex(sf::Vector2f(900, 900));
        line4[1] = sf::Vertex(sf::Vector2f(px, py));
        line44[0] = sf::Vertex(sf::Vector2f(px, py));
        line44[1] = sf::Vertex(sf::Vector2f(shadow_x, shadow_y));*/

        float view_x = game.window_manager->viewGetCenterX();
        float view_y = game.window_manager->viewGetCenterY();

        gui_sprites[0].setPosition(view_x - 960, view_y - 540);
        gui_sprites[1].setPosition(view_x - 300, view_y - 400);
        gui_sprites[2].setPosition(view_x - 300, view_y - 496);
        gui_sprites[3].setPosition(view_x - 540, view_y + 380);
        gui_sprites[4].setPosition(view_x - 920, view_y - 310);
        gui_sprites[5].setPosition(view_x - 540, view_y + 80);

        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 4; j++) {
                float condix1 = view_x + 261 - 15 + 112 * j;
                float condiy1 = view_y - 343 - 15 + 112 * i;
                float condix2 = view_x + 231 + 112 * j;
                float condiy2 = view_y - 373 + 112 * i;
                InventoryItemsSprite[i * 4 + j].setPosition(condix1, condiy1);
                SpellsInventorySprite[i * 4 + j].setPosition(condix2+5, condiy2);
            }
        }

        for (int i = 0; i < 9; i++) {
            int damage_from_spell;
            int mana_cost;
            SpellsHotbarSprites[i].setPosition(view_x - 536 + 112 * i, view_y + 384);
            GuiNoManaSprites[i].setPosition(view_x - 536 + 112 * i, view_y + 384);
            defineSpell(game.player, game.player->hotbar_spells[i], damage_from_spell, mana_cost);
            if (game.player->hotbar_spells[i] != 0 && (game.player->cooldowns[i] != 0 || game.player->mp < mana_cost)) {
                GuiNoManaSprites[i].setColor(sf::Color(0, 0, 0, 160));
            } else {
                GuiNoManaSprites[i].setColor(sf::Color(0, 0, 0, 0));
            }
        }
        if (game.player->aiming && game.player->spell_slot == 0) {
            GuiPickedSpellSprite.setPosition(view_x - 536, view_y + 384);
        }
        if (game.player->aiming && game.player->spell_slot == 1) {
            GuiPickedSpellSprite.setPosition(view_x - 536 + 112, view_y + 384);
        }
        if (game.player->aiming && game.player->spell_slot == 2) {
            GuiPickedSpellSprite.setPosition(view_x - 536 + 112 * 2, view_y + 384);
        }
        if (game.player->aiming && game.player->spell_slot == 3) {
            GuiPickedSpellSprite.setPosition(view_x - 536 + 112 * 3, view_y + 384);
        }
        if (game.player->aiming && game.player->spell_slot == 4) {
            GuiPickedSpellSprite.setPosition(view_x - 536 + 112 * 4, view_y + 384);
        }
        if (game.player->aiming && game.player->spell_slot == 5) {
            GuiPickedSpellSprite.setPosition(view_x - 536 + 112 * 5, view_y + 384);
        }
        if (game.player->aiming && game.player->spell_slot == 6) {
            GuiPickedSpellSprite.setPosition(view_x - 536 + 112 * 6, view_y + 384);
        }
        if (game.player->aiming && game.player->spell_slot == 7) {
            GuiPickedSpellSprite.setPosition(view_x - 536 + 112 * 7, view_y + 384);
        }
        if (game.player->aiming && game.player->spell_slot == 8) {
            GuiPickedSpellSprite.setPosition(view_x - 536 + 112 * 8, view_y + 384);
        }

        if (game.player->inv_items[27] != 0) {
            GuiEquipmentSprites[0].setPosition(view_x - 231 - 15, view_y - 227 - 15);
        } else {
            GuiEquipmentSprites[0].setPosition(view_x - 231 - 29, view_y - 227 - 29);
        }
        if (game.player->inv_items[28] != 0) {
            GuiEquipmentSprites[1].setPosition(view_x + 89 - 15, view_y - 227 - 15);
        } else {
            GuiEquipmentSprites[1].setPosition(view_x + 89 - 29, view_y - 227 - 29);
        }
        if (game.player->inv_items[29] != 0) {
            GuiEquipmentSprites[2].setPosition(view_x - 71 - 15, view_y - 351 - 15);
        } else {
            GuiEquipmentSprites[2].setPosition(view_x - 71 - 29, view_y - 351 - 29);
        }
        if (game.player->inv_items[30] != 0) {
            GuiEquipmentSprites[3].setPosition(view_x - 71 - 15, view_y - 227 - 15);
        } else {
            GuiEquipmentSprites[3].setPosition(view_x - 71 - 29, view_y - 227 - 29);
        }
        if (game.player->inv_items[31] != 0) {
            GuiEquipmentSprites[4].setPosition(view_x - 71 - 15, view_y - 103 - 15);
        } else {
            GuiEquipmentSprites[4].setPosition(view_x - 71 - 29, view_y - 103 - 29);
        }
        if (game.player->inv_items[32] != 0) {
            GuiEquipmentSprites[5].setPosition(view_x - 71 - 15, view_y + 21 - 15);
        } else {
            GuiEquipmentSprites[5].setPosition(view_x - 71 - 29, view_y + 21 - 29);
        }
        InventoryItemsSprite[24].setPosition(view_x - 203 - 15, view_y + 185 - 15);
        InventoryItemsSprite[25].setPosition(view_x - 71 - 15, view_y + 185 - 15);
        InventoryItemsSprite[26].setPosition(view_x + 61 - 15, view_y + 185 - 15);

        GuiIndicatorSprite.setPosition(game.player->getX()+18, game.player->getY()-34);
    }
    void updateText(float time, auto& game) {
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

        std::string p_lvl = std::to_string(game.player->lvl);
        std::string p_hp = std::to_string(game.player->hp);
        std::string p_mp = std::to_string(game.player->mp);
        std::string p_xp = std::to_string(game.player->xp);
        std::string p_hr = std::to_string(game.player->hp_regen);
        std::string p_mr = std::to_string(game.player->mp_regen);
        player_stats_hp.setString(p_hp + " +" + p_hr[0] + p_hr[1] + p_hr[2]);
        player_stats_mp.setString(p_mp + " +" + p_mr[0] + p_mr[1] + p_mr[2]);
        player_stats_lvl.setString(p_lvl + " (" + p_xp + "/" + p_lvl + "00)");
        if (game.player->cooldowns[0] != 0) {
            text_cd_0.setString(std::to_string(game.player->cooldowns[0]/1000));
        } else {
            text_cd_0.setString("");
        }
        if (game.player->cooldowns[1] != 0) {
            text_cd_1.setString(std::to_string(game.player->cooldowns[1]/1000));
        } else {
            text_cd_1.setString("");
        }
        if (game.player->cooldowns[2] != 0) {
            text_cd_2.setString(std::to_string(game.player->cooldowns[2]/1000));
        } else {
            text_cd_2.setString("");
        }
        if (game.player->cooldowns[3] != 0) {
            text_cd_3.setString(std::to_string(game.player->cooldowns[3]/1000));
        } else {
            text_cd_3.setString("");
        }
        if (game.player->cooldowns[4] != 0) {
            text_cd_4.setString(std::to_string(game.player->cooldowns[4]/1000));
        } else {
            text_cd_4.setString("");
        }
        if (game.player->cooldowns[5] != 0) {
            text_cd_5.setString(std::to_string(game.player->cooldowns[5]/1000));
        } else {
            text_cd_5.setString("");
        }
        if (game.player->cooldowns[6] != 0) {
            text_cd_6.setString(std::to_string(game.player->cooldowns[6]/1000));
        } else {
            text_cd_6.setString("");
        }
        if (game.player->cooldowns[7] != 0) {
            text_cd_7.setString(std::to_string(game.player->cooldowns[7]/1000));
        } else {
            text_cd_7.setString("");
        }
        if (game.player->cooldowns[8] != 0) {
            text_cd_8.setString(std::to_string(game.player->cooldowns[8]/1000));
        } else {
            text_cd_8.setString("");
        }

        auto get_pos_x = game.player->getX()+50;
        auto get_pos_y = game.player->getY()-10;
        auto value = std::to_string(int(game.player->shield_cd/100)/10.0);
        value = value.erase(value.size() - 5);
        text_dynamic_shield_cd->update(time, get_pos_x, get_pos_y, value);

        for (auto& i: v_dynamic_texts) {
            i.update(time);
        }

        float view_x = game.window_manager->viewGetCenterX();
        float view_y = game.window_manager->viewGetCenterY();

        text_cd_0.setPosition(view_x - 490, view_y + 404);
        text_cd_1.setPosition(view_x - 380, view_y + 404);
        text_cd_2.setPosition(view_x - 265, view_y + 404);
        text_cd_3.setPosition(view_x - 155, view_y + 404);
        text_cd_4.setPosition(view_x - 45, view_y + 404);
        text_cd_5.setPosition(view_x + 70, view_y + 404);
        text_cd_6.setPosition(view_x + 180, view_y + 404);
        text_cd_7.setPosition(view_x + 295, view_y + 404);
        text_cd_8.setPosition(view_x + 405, view_y + 404);
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
