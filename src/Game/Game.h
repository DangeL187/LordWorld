#include "WindowManager.h"
#include "Renderer.h"
#include "Info/Info.h"
#include "Items/Items.h"
#include "Spells/Spells.h"
#include "Player/Player.h"
#include "NPC/NPC.h"
#include "Monster/Monster.h"

class Game: public Renderer {
public:
    float time;
    Clock clock;
    std::shared_ptr<Player> player;
    std::vector<NPC> v_NPC;
    std::vector<Monster> v_monsters;
    Monster *target_m = NULL; //pointer to targeted monster
    std::array<std::vector<int>, 5> items_dropped;
    std::vector<int> damaged_numbers;

    Game() = default;

    void initResources(auto& map_manager, auto& game) {
        initText(game.player);
        initImages();
        initMap(map_manager);
        createMapSprite(map_manager);
        createItemSprites();
        createMonsterSprites();
        createNPCSprites();
        createGuiSprites();
    }
    void initMap(auto& map_manager) {
        std::string line;
        int index = 0;
        std::ifstream file;
        file.open("map.txt");
        if (file.is_open()) {
            while (file) {
                std::getline(file, line);
                std::vector<std::string> smap = split(line, ' ');
                for (int i = 0; i < smap.size()-1; i++) {
                    map_manager.setTileMapID(index, i, std::stoi(smap[i]));
                }
                index++;
            }
        }
        file.close();
    }
    void viewSetCenter() {
        view.setCenter(player->getX(), player->getY());
    }
    void createItem(int id, int x, int y) {
        items_dropped[0].push_back(id);
        items_dropped[1].push_back(x);
        items_dropped[2].push_back(y);
        items_dropped[3].push_back(item_sprite_counter);
        defineItemType(id, current_item_sprites, item_sprites, items_dropped);
        current_item_sprites[item_sprite_counter].setTextureRect(IntRect(0, 0, 56, 56));
        current_item_sprites[item_sprite_counter].setScale(0.75, 0.75);
        current_item_sprites[item_sprite_counter].setPosition(x, y);
        item_sprite_counter++;
    }
    void createPlayer(float x, float y, float w, float h) {
        player = std::make_shared<Player>(x, y, w, h);
    }
    void createMonster(float x, float y, float w, float h, std::string name) {
        Monster m(x, y, w, h, name, monster_sprites, other_sprite_counter, current_other_sprites);
        v_monsters.push_back(m);
    }
    void createNPC(float x, float y, float w, float h, std::string name) {
        NPC m(x, y, w, h, name, NPC_sprites, other_sprite_counter, current_other_sprites);
        v_NPC.push_back(m);
    }
    void drawSprites(auto& map_manager) {
        int index = 0;
        bool a = player->is_inventory_open;
        bool b = player->is_spells_inventory_open;
        bool c = player->is_stats_open;
        bool d = player->is_dialog;
        for (int i = 0; i < map_manager.getMapHeight(); i++) {
            for (int j = 0; j < map_manager.getMapWidth(); j++) {
                map_manager.defineTile(i, j);
                map_manager.setSpritePosition(j * 64, i * 64);
                window->draw(map_manager.getSprite());
            }
        }
        for (auto& i_sprite: current_item_sprites) {
            window->draw(i_sprite);
        }
        for (auto& i_sprite: current_other_sprites) {
            window->draw(i_sprite);
        }
        window->draw(player->getSprite());

        /*window->draw(ShadowSprite1);
        window->draw(ShadowSprite2);
        window->draw(ShadowSprite3);
        window->draw(ShadowSprite4);
        window->draw(LightSprite);
        //window->draw(ConvexShape);
        window->draw(line1, 2, sf::Lines);
        window->draw(line2, 2, sf::Lines);
        window->draw(line3, 2, sf::Lines);
        window->draw(line4, 2, sf::Lines);
        window->draw(line11, 2, sf::Lines);
        window->draw(line22, 2, sf::Lines);
        window->draw(line33, 2, sf::Lines);
        window->draw(line44, 2, sf::Lines);*/

        if (player->attack_animation != 0) {
            window->draw(AnimationWeaponSprite);
        }
        if (player->defence && player->inv_items[28] != 0) {
            window->draw(AnimationShieldSprite);
        }
        if (player->dash_timer > 0) {
            window->draw(AnimationDashSprite);
        }
        if (500 <= player->space_timer && player->space_timer <= 750) {
            window->draw(GuiIndicatorSprite);
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
                window->draw(i_sprite);
            }
            index++;
        }
        if (a && !b) {
            for (auto& i_sprite: InventoryItemsSprite) {
                window->draw(i_sprite);
            }
            for (auto& i_sprite: GuiEquipmentSprites) {
                window->draw(i_sprite);
            }
        }
        if (!a && b) {
            for (auto& i_sprite: SpellsInventorySprite) {
                window->draw(i_sprite);
            }
        }
        for (auto& i_sprite: SpellsHotbarSprites) {
            window->draw(i_sprite);
        }
        if (text_info.getString() != "") {
            window->draw(GuiInfoSprite);
        }
        if (player->aiming) {
            window->draw(GuiPickedSpellSprite);
        }
        for (auto& i: GuiNoManaSprites) {
            window->draw(i);
        }
        window->draw(player_stats_hp);
        window->draw(player_stats_mp);
        window->draw(player_stats_lvl);
        window->draw(text_cd_0);
        window->draw(text_cd_1);
        window->draw(text_cd_2);
        window->draw(text_cd_3);
        window->draw(text_cd_4);
        window->draw(text_cd_5);
        window->draw(text_cd_6);
        window->draw(text_cd_7);
        window->draw(text_cd_8);
        window->draw(text_target);
        window->draw(text_strength);
        window->draw(text_damage);
        window->draw(text_armor);
        window->draw(text_magic);
        window->draw(text_critical_chance);
        window->draw(text_magic_resistance);
        window->draw(text_physical_resistance);
        window->draw(text_magic_ice);
        window->draw(text_magic_fire);
        window->draw(text_magic_earth);
        window->draw(text_magic_wind);
        window->draw(text_magic_dark);
        window->draw(text_magic_light);
        window->draw(text_melee_weapon);
        window->draw(text_range_weapon);
        window->draw(text_info);
        window->draw(text_NPC_talk);
        for (auto& i: v_dynamic_texts) {
            if (i.getTimer() > 0) {
                Text temp_text = i.getText();
                temp_text.setFont(i.getFont());
                window->draw(temp_text);
            }
        }
        if (!player->defence && text_dynamic_shield_cd->getTimer() > 0) {
            Text temp_text = text_dynamic_shield_cd->getText();
            temp_text.setFont(text_dynamic_shield_cd->getFont());
            window->draw(temp_text);
        }
    }
    void updates(auto& map_manager) {
        time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time/800;
        timers(time, *this);
        gainLVL(*this);
        setImages(*this, 27, player->inv_spells, SpellsInventorySprite);
        setImages(*this, 9, player->hotbar_spells, SpellsHotbarSprites);
        updateGuiSprites(player);
        player->update(time, map_manager, *this);
        //v_monsters[2].hitMonster(300, time, player); //stress test
        updateText(time, player);
        monsterDeath(*this);
        guiTarget(*this);
        updateMonsters(time, map_manager, *this, player);
        updateNPCs(time, map_manager, *this);
        viewSetCenter();
    }
    void timers(auto& time, auto& game) {
        if (game.player->space_timer > 0) {
            game.player->space_timer -= time;
            if (500 <= game.player->space_timer && game.player->space_timer <= 750) {
                game.player->space_hit = true;
            } else {
                game.player->space_hit = false;
            }
        } else {
            game.player->space_timer = 0;
        }

        if (game.player->timer_hp_regen > 0) {
            game.player->timer_hp_regen -= time;
        } else {
            game.player->timer_hp_regen = 1000 / game.player->hp_regen;
            if (game.player->hp < game.player->hp_max) {
                game.player->hp += 1;
            }
        }

        if (game.player->timer_mp_regen > 0) {
            game.player->timer_mp_regen -= time;
        } else {
            game.player->timer_mp_regen = 1000 / game.player->mp_regen;
            if (game.player->mp < game.player->mp_max) {
                game.player->mp += 1;
            }
        }

        if (Mouse::isButtonPressed(Mouse::Left)) {
            game.player->hold_attack_timer += time;
            if (game.player->hold_attack_timer >= 1000) {
              game.player->attack_stun = true;
            }
        } else {
            game.player->hold_attack_timer = 0;
            game.player->attack_stun = false;
        }

        if (game.player->animation_timer > 0) {
            game.player->animation_timer -= time;
        } else {
            game.player->animation_timer = 150;
            if (game.player->attack_animation != 0 && game.player->attack_animation < 5) {
                game.player->attack_animation++;
            } else {
                game.player->attack_animation = 0;
            }
        }

        if (game.player->defence_timer > 0 && player->inv_items[28] != 0) {
            game.player->defence_timer -= time;
            game.player->defence = true;
        } else {
            game.player->defence_timer = 0;
            game.player->defence = false;
        }

        if (game.player->attack1_cd > 0) {
            game.player->attack1_cd -= time;
        } else {
            game.player->attack1_cd = 0;
        }

        if (game.player->attack2_cd > 0) {
            game.player->attack2_cd -= time;
        } else {
            game.player->attack2_cd = 0;
        }

        if (game.player->shield_cd > 0) {
            game.player->shield_cd -= time;
        } else {
            game.player->shield_cd = 0;
        }

        if (game.player->dash_cd > 0) {
            game.player->dash_cd -= time;
        } else {
            game.player->dash_cd = 0;
        }

        for (auto& i: game.player->cooldowns) {
            if (i > 0) {
                i -= time;
            } else {
                i = 0;
            }
        }
    }
    void targeting(auto& game) {
        int out = game.player->getX() - (962 - Mouse::getPosition().x);
        int outy = game.player->getY() - (544 - Mouse::getPosition().y);
        for (int v = 0; v < v_monsters.size(); v++) {
            float mx = v_monsters[v].getX();
    		float my = v_monsters[v].getY();
            float condx = mx/1 + 64 - 14;
            float condy = my/1 + 64;
            if (mx/1 <= out && out <= condx && my/1 <= outy && outy <= condy) {
                target_m = &v_monsters[v];
            }
        }
    }
    void gainLVL(auto& game) {
        if (game.player->xp >= game.player->lvl * 100) {
            game.player->xp -= game.player->lvl * 100;
            game.player->lvl++;
        }
    }
    void updateMonsters(auto& time, auto& map_manager, auto& game, auto& player) {
        int index1 = 0;
        for (auto& i: v_monsters) {
            i.update(time, map_manager, game, player);
            i.moveMonster(time, map_manager, game, player);
            int index2 = 0;
            for (auto& i2: v_monsters) {
                float mx1 = i.getX();
                float mx2 = i2.getX();
                float my1 = i.getY();
                float my2 = i2.getY();
                float condx = pow(pow((mx1 - mx2), 2), 0.5);
        		float condy = pow(pow((my1 - my2), 2), 0.5);
                //todo: replace 52 and 64 with unique values for each monster
        		if (condx <= 52 && condy <= 64 && index1 != index2) { //collision with monsters
                    if (i.getDX() > 0) {
                        i.addX(false);
                    }
                    if (i.getDX() < 0) {
                        i.addX(true);
                    }
                    if (i.getDY() > 0) {
                        i.addY(false);
                    }
                    if (i.getDY() < 0) {
                        i.addY(true);
                    }
        		}
                index2++;
            }
            index1++;
        }
    }
    void updateNPCs(auto& time, auto& map_manager, auto& game) {
        //int index1 = 0;
        for (auto& i: v_NPC) {
            i.update(time, map_manager, game);
            /*int index2 = 0;
            for (auto& i2: v_monsters) {
                float mx1 = i.getX();
                float mx2 = i2.getX();
                float my1 = i.getY();
                float my2 = i2.getY();
                float condx = pow(pow((mx1 - mx2), 2), 0.5);
        		float condy = pow(pow((my1 - my2), 2), 0.5);
                //todo: replace 52 and 64 with unique values for each monster
        		if (condx <= 52 && condy <= 64 && index1 != index2) { //collision with monsters
                    if (i.getDX() > 0) {
                        i.addX(false);
                    }
                    if (i.getDX() < 0) {
                        i.addX(true);
                    }
                    if (i.getDY() > 0) {
                        i.addY(false);
                    }
                    if (i.getDY() < 0) {
                        i.addY(true);
                    }
        		}
                index2++;

            index1++;*/
        }
    }
    void monsterDeath(auto& game) {
        for (int i = 0; i < v_monsters.size(); i++) {
            if (v_monsters[i].getHP() <= 0) {
                current_other_sprites.erase(current_other_sprites.begin() + v_monsters[i].getSprite());
                other_sprite_counter--;
                target_m = NULL;
                text_target.setString("");
                for (int j = 0; j < v_monsters.size(); j++) {
                    if (j > i) {
                        v_monsters[j].reduceSprite();
                    }
                }
                game.player->xp += v_monsters[i].getXP();
                v_monsters[i].dropMonster(game);
                v_monsters.erase(v_monsters.begin() + i);
            }
        }
    }
    void spellDamaged(auto& game) { //TODO: different types of damage range
        damaged_numbers.clear();
        int out = game.player->getX() - (962 - Mouse::getPosition().x);
    	int outy = game.player->getY() - (544 - Mouse::getPosition().y);
    	for (int v = 0; v < v_monsters.size(); v++) {
            float mx = v_monsters[v].getX();
    		float my = v_monsters[v].getY();
            float condx = mx/1 + 1*64; //replace with unique number
            float condy = my/1 + 1*64; //replace with unique number
    		if (mx/1 <= out && out <= condx && my/1 <= outy && outy <= condy) { //TODO: fix aoe range?
    			damaged_numbers.push_back(v);
    		}
    	}
    }
};
