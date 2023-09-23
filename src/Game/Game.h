#include "WindowManager.h"
#include "Renderer.h"
#include "SpriteLoader.h"
#include "Info/Info.h"
#include "Items/Items.h"
#include "EntityManager.h"
#include "Spells/Spells.h"
#include "Player/Player.h"
#include "NPC/NPC.h"
#include "Monster/Monster.h"

class Game {
public:
    float time;
    Clock clock;
    Monster *target_m = NULL; //pointer to targeted monster
    std::shared_ptr<Player> player;
    std::vector<NPC> v_NPC;
    std::vector<Monster> v_monsters;
    std::vector<int> damaged_numbers;
    std::shared_ptr<Map> map;
    std::shared_ptr<WindowManager> window_manager;
    std::shared_ptr<Renderer> renderer;
    std::shared_ptr<EntityManager> entity_manager;
    std::shared_ptr<SpriteLoader> sprite_loader;

    Game() = default;

    void createSpriteLoader() {
        sprite_loader = std::make_shared<SpriteLoader>();
    }
    void createEntityManager() {
        entity_manager = std::make_shared<EntityManager>();
    }
    void createRenderer() {
        renderer = std::make_shared<Renderer>(map);
    }
    void createWindow(std::string name, int w, int h) {
        window_manager = std::make_shared<WindowManager>(name, w, h);
    }
    void createMap() {
        map = std::make_shared<Map>();
    }
    void createPlayer(float x, float y, float w, float h) {
        player = std::make_shared<Player>(x, y, w, h);
    }
    void createMonster(float x, float y, float w, float h, std::string name) {
        Monster m(x, y, w, h, name, renderer->monster_sprites, renderer->other_sprite_counter, renderer->current_other_sprites);
        v_monsters.push_back(m);
    }
    void createNPC(float x, float y, float w, float h, std::string name) {
        NPC m(x, y, w, h, name, renderer->NPC_sprites, renderer->other_sprite_counter, renderer->current_other_sprites);
        v_NPC.push_back(m);
    }
    void drawSprites() {
        int index = 0;
        bool a = player->is_inventory_open;
        bool b = player->is_spells_inventory_open;
        bool c = player->is_stats_open;
        bool d = player->is_dialog;
        for (int i = 0; i < map->getMapHeight(); i++) {
            for (int j = 0; j < map->getMapWidth(); j++) {
                map->defineTile(i, j);
                map->setSpritePosition(j * 64, i * 64);
                window_manager->windowDraw(map->getSprite());
            }
        }
        for (auto& i_sprite: renderer->current_item_sprites) {
            window_manager->windowDraw(i_sprite);
        }
        for (auto& i_sprite: renderer->current_other_sprites) {
            window_manager->windowDraw(i_sprite);
        }
        window_manager->windowDraw(player->getSprite());

        /*window_manager->windowDraw(ShadowSprite1);
        window_manager->windowDraw(ShadowSprite2);
        window_manager->windowDraw(ShadowSprite3);
        window_manager->windowDraw(ShadowSprite4);
        window_manager->windowDraw(LightSprite);
        //window_manager->windowDraw(ConvexShape);
        window_manager->windowDraw(line1, 2, sf::Lines);
        window_manager->windowDraw(line2, 2, sf::Lines);
        window_manager->windowDraw(line3, 2, sf::Lines);
        window_manager->windowDraw(line4, 2, sf::Lines);
        window_manager->windowDraw(line11, 2, sf::Lines);
        window_manager->windowDraw(line22, 2, sf::Lines);
        window_manager->windowDraw(line33, 2, sf::Lines);
        window_manager->windowDraw(line44, 2, sf::Lines);*/

        if (player->attack_animation != 0) {
            window_manager->windowDraw(renderer->AnimationWeaponSprite);
        }
        if (player->defence && player->inv_items[28] != 0) {
            window_manager->windowDraw(renderer->AnimationShieldSprite);
        }
        if (player->dash_timer > 0) {
            window_manager->windowDraw(renderer->AnimationDashSprite);
        }
        if (500 <= player->space_timer && player->space_timer <= 750) {
            window_manager->windowDraw(renderer->GuiIndicatorSprite);
        }
        for (auto& i_sprite: renderer->gui_sprites) { //TODO: replace with unique names so there won't be any "a", "b", "c" etc.
            bool i1 = index != 1;
            bool i2 = index != 2;
            bool i4 = index != 4;
            bool i5 = index != 5;
            bool e = a && i2 && i4 && i5;
            bool f = b && i1 && i4 && i5;
            bool g = c && i1 && i2 && i5;
            bool h = d && i1 && i2 && i4;
            if ((i1 && i2 && i4 && i5) || e || f || g || h) {
                window_manager->windowDraw(i_sprite);
            }
            index++;
        }
        if (a && !b) {
            for (auto& i_sprite: renderer->InventoryItemsSprite) {
                window_manager->windowDraw(i_sprite);
            }
            for (auto& i_sprite: renderer->GuiEquipmentSprites) {
                window_manager->windowDraw(i_sprite);
            }
        }
        if (!a && b) {
            for (auto& i_sprite: renderer->SpellsInventorySprite) {
                window_manager->windowDraw(i_sprite);
            }
        }
        for (auto& i_sprite: renderer->SpellsHotbarSprites) {
            window_manager->windowDraw(i_sprite);
        }
        if (renderer->text_info.getString() != "") {
            window_manager->windowDraw(renderer->GuiInfoSprite);
        }
        if (player->aiming) {
            window_manager->windowDraw(renderer->GuiPickedSpellSprite);
        }
        for (auto& i: renderer->GuiNoManaSprites) {
            window_manager->windowDraw(i);
        }
        window_manager->windowDraw(renderer->player_stats_hp);
        window_manager->windowDraw(renderer->player_stats_mp);
        window_manager->windowDraw(renderer->player_stats_lvl);
        window_manager->windowDraw(renderer->text_cd_0);
        window_manager->windowDraw(renderer->text_cd_1);
        window_manager->windowDraw(renderer->text_cd_2);
        window_manager->windowDraw(renderer->text_cd_3);
        window_manager->windowDraw(renderer->text_cd_4);
        window_manager->windowDraw(renderer->text_cd_5);
        window_manager->windowDraw(renderer->text_cd_6);
        window_manager->windowDraw(renderer->text_cd_7);
        window_manager->windowDraw(renderer->text_cd_8);
        window_manager->windowDraw(renderer->text_target);
        window_manager->windowDraw(renderer->text_strength);
        window_manager->windowDraw(renderer->text_damage);
        window_manager->windowDraw(renderer->text_armor);
        window_manager->windowDraw(renderer->text_magic);
        window_manager->windowDraw(renderer->text_critical_chance);
        window_manager->windowDraw(renderer->text_magic_resistance);
        window_manager->windowDraw(renderer->text_physical_resistance);
        window_manager->windowDraw(renderer->text_magic_ice);
        window_manager->windowDraw(renderer->text_magic_fire);
        window_manager->windowDraw(renderer->text_magic_earth);
        window_manager->windowDraw(renderer->text_magic_wind);
        window_manager->windowDraw(renderer->text_magic_dark);
        window_manager->windowDraw(renderer->text_magic_light);
        window_manager->windowDraw(renderer->text_melee_weapon);
        window_manager->windowDraw(renderer->text_range_weapon);
        window_manager->windowDraw(renderer->text_info);
        window_manager->windowDraw(renderer->text_NPC_talk);
        for (auto& i: renderer->v_dynamic_texts) {
            if (i.getTimer() > 0) {
                Text temp_text = i.getText();
                temp_text.setFont(i.getFont());
                window_manager->windowDraw(temp_text);
            }
        }
        if (!player->defence && renderer->text_dynamic_shield_cd->getTimer() > 0) {
            Text temp_text = renderer->text_dynamic_shield_cd->getText();
            temp_text.setFont(renderer->text_dynamic_shield_cd->getFont());
            window_manager->windowDraw(temp_text);
        }
    }
    void updates() {
        time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time/800;
        timers(time, *this);
        gainLVL(*this);
        setImages(*this, 27, player->inv_spells, renderer->SpellsInventorySprite);
        setImages(*this, 9, player->hotbar_spells, renderer->SpellsHotbarSprites);
        renderer->updateGuiSprites(*this);
        player->update(time, *this);
        //v_monsters[2].hitMonster(300, time, player); //stress test
        renderer->updateText(time, *this);
        monsterDeath(*this);
        renderer->guiTarget(*this);
        updateMonsters(time, *this, player);
        updateNPCs(time, *this);
        window_manager->viewSetCenter(player->getX(), player->getY());
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
    void updateMonsters(auto& time, auto& game, auto& player) {
        int index1 = 0;
        for (auto& i: v_monsters) {
            i.update(time, game, player);
            i.moveMonster(time, game, player);
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
    void updateNPCs(auto& time, auto& game) {
        //int index1 = 0;
        for (auto& i: v_NPC) {
            i.update(time, game);
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
                std::vector<Sprite> cos = renderer->current_other_sprites;
                cos.erase(cos.begin() + v_monsters[i].getSprite());
                renderer->other_sprite_counter--;
                target_m = NULL;
                renderer->text_target.setString("");
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
