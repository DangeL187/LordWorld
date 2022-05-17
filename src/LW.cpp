#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstdlib>
#include <string>
#include <sstream>
#include <cmath>
#include "map.h"
#include "view.h"
#include "split.h"

using namespace sf;

Image GuiBarImage, GuiInventoryImage, GuiSpellsHotbarImage;
Image GuiInfoImage, GuiStatsImage, GuiPickedSpellImage;
Image GuiSpellsInventoryImage;
Texture GuiBarTexture, GuiInventoryTexture, GuiSpellsHotbarTexture;
Texture GuiInfoTexture, GuiStatsTexture, GuiPickedSpellTexture;
Texture GuiSpellsInventoryTexture;
Sprite GuiBarSprite, GuiInventorySprite, GuiSpellsHotbarSprite;
Sprite GuiInfoSprite, GuiStatsSprite, GuiPickedSpellSprite;
Sprite GuiSpellsInventorySprite;

Image SpellsInventoryPageImage[27];
Image InventoryItemsImage[27];
Image InventoryItemEmptyImage;
Image InventoryItemHelmImage;
Image InventoryItemChestImage;
Image InventoryItemPantsImage;
Image InventoryItemBootsImage;
Image InventoryItemWeaponImage;
Image InventoryItemShieldImage;
Texture SpellsInventoryPageTexture[27];
Texture InventoryItemsTexture[27];
Texture InventoryItemEmptyTexture;
Texture InventoryItemHelmTexture;
Texture InventoryItemChestTexture;
Texture InventoryItemPantsTexture;
Texture InventoryItemBootsTexture;
Texture InventoryItemWeaponTexture;
Texture InventoryItemShieldTexture;
Sprite SpellsInventoryPageSprite[27];
Sprite InventoryItemsSprite[27];
Sprite InventoryItemEmptySprite;
Sprite InventoryItemHelmSprite;
Sprite InventoryItemChestSprite;
Sprite InventoryItemPantsSprite;
Sprite InventoryItemBootsSprite;
Sprite InventoryItemWeaponSprite;
Sprite InventoryItemShieldSprite;

Image SpellsHotbarImages[9];
Texture SpellsHotbarTextures[9];
Sprite SpellsHotbarSprites[9];

Image EquipedShieldImage;
Texture EquipedShieldTexture;
Sprite EquipedShieldSprite;

Image map_image;
Texture map_texture;
Sprite map_sprite;
Sprite herosprite;
std::vector<Sprite> other_sprites;

Font font; //шрифт
Text text_cd_0("", font, 60);
Text text_cd_1("", font, 60);
Text text_cd_2("", font, 60);
Text text_cd_3("", font, 60);
Text text_cd_4("", font, 60);
Text text_cd_5("", font, 60);
Text text_cd_6("", font, 60);
Text text_cd_7("", font, 60);
Text text_cd_8("", font, 60);
Text text_strength("", font, 40);
Text text_damage("", font, 40);
Text text_armor("", font, 40);
Text text_magic("", font, 40);
Text text_critical_chance("", font, 40); //%
Text text_magic_resistance("", font, 40); //%
Text text_physical_resistance("", font, 40); //%
Text text_magic_ice("", font, 40);
Text text_magic_fire("", font, 40);
Text text_magic_earth("", font, 40);
Text text_magic_wind("", font, 40);
Text text_magic_dark("", font, 40);
Text text_magic_light("", font, 40);
Text text_melee_weapon("", font, 40);
Text text_range_weapon("", font, 40);
Text text_item_info("", font, 30);
Text text("", font, 40);
Text player_stats_hp("", font, 30);
Text player_stats_mp("", font, 30);
Text player_stats_lvl("", font, 30);

//stats:
int strength = 1;
int armor = 0;
int magic = 1;
float critical_chance = 1; //%
//resists:
float magic_resistance = 1; //%
float physical_resistance = 1; //%
//magic:
int magic_ice = 1;
int magic_fire = 1;
int magic_earth = 1;
int magic_wind = 1;
int magic_dark = 1;
int magic_light = 1;
//skills:
int melee_weapon = 1;
int range_weapon = 1;

int player_x = 0, player_y = 0;
int player_dir = 0;
int attack = 0;
int attack_animation = 0;
int range = 1; //*64
int armor_shield = 0;
int armor_helmet = 0;
int armor_chestplate = 0;
int armor_pants = 0;
int armor_boots = 0;
int sprite_counter = 0;
int attack1_cd = 0;
int attack2_cd = 0;
int spell_slot = 0;
int timer_ColdSnap;
int timer_ColdSnap_tick;
int timer_hp_regen = 10000, timer_mp_regen = 10000; //10000 is 0.1 per second
int player_hp = 10, player_mp = 10, player_lvl = 1;
int player_hp_max = 10, player_mp_max = 10;
int player_damage = 1;
int defence_counter = 0;
int attack_speed = 1000; //1 second
int weapon_type = 1; //1-circle attack; 2-straight; 3-conus; 4-front-back line;
int spell_name = 0;
int target_number = -1;
int inv_items[33]; //items inventory //from [24] to [26] - other
//[27] - weapon, [28] - shield, [29] - helmet, [30] - chestplate, [31] - pants, [32] - boots
int inv_types[24]; //item types invenory
int inv_spells[300]; //spells inventory
int hotbar_spells[9]; //spells hotbar
int cooldowns[9] {0, 0, 0, 0, 0, 0, 0, 0, 0}; //cooldowns
float attack1_cd_timer = 0;
float attack2_cd_timer = 0;
float animation_timer = 0;
float move_monster_timer = 0;
float space_timer = 0;
float current_frame = 0;
float hp_regen = 0.1, mp_regen = 0.1;
bool defence = false;
bool space_hit = false;
bool aiming = false;
bool aiming_kid1 = false;
bool aiming_kid2 = false;
bool aiming_kid3 = false;
bool aiming_kid4 = false;
bool aiming_kid5 = false;
bool aiming_kid6 = false;
bool aiming_kid7 = false;
bool aiming_kid8 = false;
bool aiming_kid9 = false;
bool is_inventory_open = false;
bool is_spells_inventory_open = false;
bool is_stats_open = false;
std::string weapon = ""; //todo: delete

#include "init_images.h"
#include "equipment.h"
#include "classes.h"
#include "drawmap.h"
#include "weapon_types.h"
#include "gui.h"
#include "info.h"

std::vector<Monster> v_monsters; //whole monsters
std::vector<Monster> target_m; //targeted monster
std::vector<int> damaged_numbers; //monsters under attack
std::vector<int> items_dropped_id;
std::vector<int> items_dropped_x;
std::vector<int> items_dropped_y;
std::vector<int> items_dropped_sprites; //rename to sprite
std::vector<int> items_dropped_type; //0 - nothing, 1 - weapon, 2 - shield
//3 - helmet, 4 - chestplate, 5 - pants, 6 - boots, 7 - ring, 8.. - item

void targeting() {
    int out = player_x - (962 - Mouse::getPosition().x); //960
	int outy = player_y - (544 - Mouse::getPosition().y); //570
	for (int v = 0; v < v_monsters.size(); v++) {
		float mx = v_monsters[v].getMonsterCoordinateX();
		float my = v_monsters[v].getMonsterCoordinateY();
        float condx = mx/1 + range*64 - 14;
        float condy = my/1 + range*64;
		if (mx/1 <= out && out <= condx && my/1 <= outy && outy <= condy) {
			if (target_m.size() == 0) {
                target_m.push_back(v_monsters[v]);
                target_number = v;
            }
			else {
                target_m[0] = v_monsters[v];
                target_number = v;
            }
		}
	}
}

void spellDamaged() { //TODO: different types of damage range, unite it with monsters_damaged?
    damaged_numbers.clear();
    int out = player_x - (962 - Mouse::getPosition().x);
	int outy = player_y - (544 - Mouse::getPosition().y);
	for (int v = 0; v < v_monsters.size(); v++) {
        float mx = v_monsters[v].getMonsterCoordinateX();
		float my = v_monsters[v].getMonsterCoordinateY();
        float condx = mx/1 + range*64;
        float condy = my/1 + range*64;
		if (mx/1 <= out && out <= condx && my/1 <= outy && outy <= condy) { //TODO: fix aoe range?
			damaged_numbers.push_back(v);
		}
	}
}

void moveCurrentFrame(float get_time) {
	current_frame += 0.005 * get_time;
	if (current_frame > 3) {
        current_frame -= 3;
    }
}

int createItem(int ID, int get_x, int get_y) {
    items_dropped_id.push_back(ID);
    items_dropped_x.push_back(get_x);
    items_dropped_y.push_back(get_y);
    items_dropped_sprites.push_back(sprite_counter);
    #include "item_types.h"

    other_sprites[sprite_counter].setTextureRect(IntRect(0, 0, 56, 56));
    other_sprites[sprite_counter].setScale(0.75, 0.75);
    other_sprites[sprite_counter].setPosition(get_x, get_y);
    sprite_counter++;
}

void createMonster(float x, float y, float w, float h, std::string name) {
    Monster m(x, y, w, h, name);
    v_monsters.push_back(m);
}

#include "spells.h"

int main() {
    #include "images.h" //load images

    inv_spells[0] = 1;
    inv_spells[1] = 2;
    hotbar_spells[0] = 1; //temp

    font.loadFromFile("../font/OceanSummer.ttf");
    text_cd_0.setColor(Color::White);
    text_cd_1.setColor(Color::White);
    text_cd_2.setColor(Color::White);
    text_cd_3.setColor(Color::White);
    text_cd_4.setColor(Color::White);
    text_cd_5.setColor(Color::White);
    text_cd_6.setColor(Color::White);
    text_cd_7.setColor(Color::White);
    text_cd_8.setColor(Color::White);
    text.setColor(Color::White);
    player_stats_hp.setColor(Color::White);
    player_stats_hp.setStyle(sf::Text::Bold);
    player_stats_mp.setColor(Color::White);
    player_stats_mp.setStyle(sf::Text::Bold);
    player_stats_lvl.setColor(Color::White);
    player_stats_lvl.setStyle(sf::Text::Bold);

    for (int i = 0; i <= 33; i++) { //add zero items in inventory
        inv_items[i] = 0;
    }

    std::cout << "I tink its k\n";

    RenderWindow window(VideoMode(1920, 1080), "Lord World", sf::Style::Fullscreen);
    view.reset(FloatRect(0, 0, 1920, 1080));

    Player player(500, 500, 50.0, 62.0);

    createMonster(300, 300, 50.0, 62.0, "Rat");
    createMonster(400, 400, 50.0, 62.0, "Rat");

    createItem(1, 600, 600);
    createItem(2, 700, 700);
    createItem(3, 800, 700);
    createItem(4, 900, 700);
    createItem(5, 1000, 700);
    createItem(6, 1100, 700);
    createItem(7, 1200, 700);
    createItem(7, 1300, 700);
    createItem(7, 1400, 700);
    createItem(1, 1500, 700);
    createItem(1, 1600, 700);
    createItem(1, 1700, 700);
    createItem(1, 1800, 700);
    createItem(1, 1900, 700);

    Clock clock;

    while (window.isOpen()) {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time/800;

        for (int v0 = 0; v0 < v_monsters.size(); v0++) {
            v_monsters[v0].update(time);
            v_monsters[v0].moveMonster(time);
            for (int v1 = 0; v1 < v_monsters.size(); v1++) {
                float mx1 = v_monsters[v0].getMonsterCoordinateX();
                float mx2 = v_monsters[v1].getMonsterCoordinateX();
                float my1 = v_monsters[v0].getMonsterCoordinateY();
                float my2 = v_monsters[v1].getMonsterCoordinateY();
                float condx = pow(pow((mx1 - mx2), 2), 0.5);
        		float condy = pow(pow((my1 - my2), 2), 0.5);
                //todo: replace 52 and 64 with unique values for each monster
        		if (condx <= 52 && condy <= 64 && v0 != v1) { //collision with monsters
                    if (v_monsters[v0].getMonsterDX() > 0) {
                        v_monsters[v0].addMonsterX(false);
                    }
                    if (v_monsters[v0].getMonsterDX() < 0) {
                        v_monsters[v0].addMonsterX(true);
                    }
                    if (v_monsters[v0].getMonsterDY() > 0) {
                        v_monsters[v0].addMonsterY(false);
                    }
                    if (v_monsters[v0].getMonsterDY() < 0) {
                        v_monsters[v0].addMonsterY(true);
                    }
        		}
            }
		}

        if (space_timer > 0) {
            space_timer -= time;
            if (750 >= space_timer && space_timer >= 500) {
                space_hit = true;
            } else {
                space_hit = false;
            }
        } else {
            space_timer = 0;
        }
        if (timer_hp_regen > 0) {
            timer_hp_regen -= time;
        } else {
            timer_hp_regen = 1000 / hp_regen;
            if (player_hp < player_hp_max) {
                player_hp += 1;
            }
        }
        if (timer_mp_regen > 0) {
            timer_mp_regen -= time;
        } else {
            timer_mp_regen = 1000 / mp_regen;
            if (player_mp < player_mp_max) {
                player_mp += 1;
            }
        }
        if (attack1_cd > 0) {
            attack1_cd -= time;
        } else {
            attack1_cd = 0;
        }
        if (attack2_cd > 0) {
            attack2_cd -= time;
        } else {
            attack2_cd = 0;
        }
        for (int i = 0; i <= 9; i++) {
            if (cooldowns[i] > 0) {
                cooldowns[i] -= time;
            } else {
                cooldowns[i] = 0;
            }
        }

        if (attack == 1 && attack1_cd == 0) {
            for (int v = 0; v < v_monsters.size(); v++) {
                float mx = v_monsters[v].getMonsterCoordinateX();
        		float my = v_monsters[v].getMonsterCoordinateY();
                if (checkWeaponsRange(mx, my)) {
                    int random_crit = rand() % 100;
                    int ch = 0;
                    random_crit++;
                    if (random_crit <= critical_chance) {
                        ch = player_damage;
                    }
                    if (space_hit) {
                        v_monsters[v].hitMonster(player_damage * 3 + ch, time);
                        attack1_cd = attack_speed * 3;
                    } else {
                        v_monsters[v].hitMonster(player_damage + ch, time);
                        attack1_cd = attack_speed;
                    }
                    attack = 0;
                }
            }
            AnimationWoodenSwordSprite.setTextureRect(IntRect(0, 0, 1, 1));
            AnimationWoodenSwordSprite.setPosition(player_x - 20, player_y);
            attack_animation = 1;
            defence_counter = 0;
        }
        if (attack == 2 && attack2_cd == 0) {
            for (int v = 0; v < v_monsters.size(); v++) {
                float mx = v_monsters[v].getMonsterCoordinateX();
        		float my = v_monsters[v].getMonsterCoordinateY();
                if (checkWeaponsRange(mx, my)) {
                    int random_crit = rand() % 100;
                    int ch = 0;
                    random_crit++;
                    if (random_crit <= critical_chance) {
                        ch = player_damage;
                    }
                    if (space_hit) {
                        v_monsters[v].hitMonster(player_damage * 2 + ch, time);
                        attack2_cd = attack_speed * 3;
                        //stun
                    } else {
                        v_monsters[v].hitMonster(player_damage * 2 + ch, time);
                        attack2_cd = attack_speed * 2;
                    }
                    attack = 0;
                }
            }
            AnimationWoodenSwordSprite.setTextureRect(IntRect(0, 0, 1, 1));
            AnimationWoodenSwordSprite.setPosition(player_x - 20, player_y);
            attack_animation = 1;
            defence_counter = 0;
        }

        if (animation_timer > 0) {
            animation_timer -= time;
        } else {
            animation_timer = 150;
            if (attack_animation == 1) {
                if (player.dir == 0) { //D
                    AnimationWoodenSwordSprite.setTextureRect(IntRect(1, 131, 72, 64));
                    AnimationWoodenSwordSprite.setPosition(player_x, player_y);
                    herosprite.setTextureRect(IntRect(52 * 2, 64 * 2, 50, 62));
                }
                if (player.dir == 1) { //A
                    AnimationWoodenSwordSprite.setTextureRect(IntRect(1, 66, 72, 64));
                    AnimationWoodenSwordSprite.setPosition(player_x - 20, player_y);
                    herosprite.setTextureRect(IntRect(0, 64, 50, 62));
                }
                if (player.dir == 2) { //W
                    AnimationWoodenSwordSprite.setTextureRect(IntRect(1, 196, 72, 64));
                    AnimationWoodenSwordSprite.setPosition(player_x - 10, player_y - 4);
                    herosprite.setTextureRect(IntRect(52 * 3, 64 * 3, 50, 62));
                }
                if (player.dir == 3) { //S
                    AnimationWoodenSwordSprite.setTextureRect(IntRect(1, 1, 72, 64));
                    AnimationWoodenSwordSprite.setPosition(player_x - 20, player_y);
                    herosprite.setTextureRect(IntRect(52 * 3, 0, 50, 62));
                }
                attack_animation++;
            }
            else if (attack_animation == 2) {
                if (player.dir == 0) {
                    AnimationWoodenSwordSprite.setTextureRect(IntRect(74, 131, 72, 64));
                    AnimationWoodenSwordSprite.setPosition(player_x, player_y);
                    herosprite.setTextureRect(IntRect(52 * 3, 64 * 2, 50, 62));
                }
                if (player.dir == 1) {
                    AnimationWoodenSwordSprite.setTextureRect(IntRect(74, 66, 72, 64));
                    AnimationWoodenSwordSprite.setPosition(player_x - 20, player_y);
                    herosprite.setTextureRect(IntRect(52 * 3, 64, 50, 62));
                }
                if (player.dir == 2) {
                    AnimationWoodenSwordSprite.setTextureRect(IntRect(74, 196, 72, 64));
                    AnimationWoodenSwordSprite.setPosition(player_x, player_y - 5);
                    herosprite.setTextureRect(IntRect(52, 64 * 3, 50, 62));
                }
                if (player.dir == 3) {
                    AnimationWoodenSwordSprite.setTextureRect(IntRect(74, 1, 72, 64));
                    AnimationWoodenSwordSprite.setPosition(player_x - 20, player_y + 20);
                    herosprite.setTextureRect(IntRect(52 * 4, 0, 50, 62));
                }
                attack_animation++;
            }
            else if (attack_animation == 3) {
                if (player.dir == 0) {
                    AnimationWoodenSwordSprite.setTextureRect(IntRect(147, 131, 72, 64));
                    AnimationWoodenSwordSprite.setPosition(player_x, player_y + 30);
                    herosprite.setTextureRect(IntRect(52 * 4, 64 * 2, 50, 62));
                }
                if (player.dir == 1) {
                    AnimationWoodenSwordSprite.setTextureRect(IntRect(147, 66, 72, 64));
                    AnimationWoodenSwordSprite.setPosition(player_x - 20, player_y + 30);
                    herosprite.setTextureRect(IntRect(52 * 4, 64, 50, 62));
                }
                if (player.dir == 2) {
                    AnimationWoodenSwordSprite.setTextureRect(IntRect(147, 196, 72, 64));
                    AnimationWoodenSwordSprite.setPosition(player_x - 6, player_y + 2);
                    herosprite.setTextureRect(IntRect(52 * 4, 64 * 3, 50, 62));
                }
                if (player.dir == 3) {
                    AnimationWoodenSwordSprite.setTextureRect(IntRect(147, 1, 72, 64));
                    AnimationWoodenSwordSprite.setPosition(player_x, player_y + 20);
                    herosprite.setTextureRect(IntRect(52 * 3, 0, 50, 62));
                }
                attack_animation++;
            }
            else if (attack_animation == 4) {
                if (player.dir == 0) {
                    AnimationWoodenSwordSprite.setTextureRect(IntRect(220, 131, 72, 64));
                    AnimationWoodenSwordSprite.setPosition(player_x - 10, player_y + 27);
                    herosprite.setTextureRect(IntRect(0, 128, 50, 62));
                }
                if (player.dir == 1) {
                    AnimationWoodenSwordSprite.setTextureRect(IntRect(220, 66, 72, 64));
                    AnimationWoodenSwordSprite.setPosition(player_x - 10, player_y + 27);
                    herosprite.setTextureRect(IntRect(0, 64, 50, 62));
                }
                if (player.dir == 3) {
                    AnimationWoodenSwordSprite.setTextureRect(IntRect(220, 1, 72, 64));
                    AnimationWoodenSwordSprite.setPosition(player_x, player_y);
                    herosprite.setTextureRect(IntRect(52 * 4, 0, 50, 62));
                }
                attack_animation++;
            }
            else if (attack_animation == 5) {
                if (player.dir == 0) {
                    AnimationWoodenSwordSprite.setTextureRect(IntRect(1, 1, 72, 64));
                    herosprite.setTextureRect(IntRect(52 * int(current_frame), 128, 50, 62));
                }
                if (player.dir == 1) {
                    AnimationWoodenSwordSprite.setTextureRect(IntRect(1, 66, 72, 64));
                    herosprite.setTextureRect(IntRect(52 * int(current_frame), 64, 50, 62));
                }
                if (player.dir == 2) {
                    AnimationWoodenSwordSprite.setTextureRect(IntRect(1, 1, 72, 64));
                    herosprite.setTextureRect(IntRect(52 * int(current_frame), 192, 50, 62));
                }
                if (player.dir == 3) {
                    AnimationWoodenSwordSprite.setTextureRect(IntRect(1, 1, 72, 64));
                    herosprite.setTextureRect(IntRect(52 * int(current_frame), 0, 50, 62));
                }
                AnimationWoodenSwordSprite.setPosition(player_x - 20, player_y);
                attack_animation = 0;
            }
        }

        for (int i = 0; i < v_monsters.size(); i++) {
            if (v_monsters[i].getMonsterHP() <= 0) {
                other_sprites.erase(other_sprites.begin() + v_monsters[i].getMonsterSprite());
                sprite_counter--;
                if (i == target_number) {
                    target_m.erase(target_m.begin() + 0);
                    target_number = -1;
                    text.setString("");
                }
                for (int j = 0; j < v_monsters.size(); j++) {
                    if (j > i) {
                        v_monsters[j].reduceMonsterSprite();
                    }
                }
                for (int j = 0; j < items_dropped_sprites.size(); j++) {
                    if (items_dropped_sprites[j] > v_monsters[i].getMonsterSprite()) {
                        items_dropped_sprites[j] = items_dropped_sprites[j] - 1;
                    }
                }
                v_monsters.erase(v_monsters.begin() + i);
            }
        }

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        #include "keys.h"

        if (target_m.size() != 0) {
            target_m[0] = v_monsters[target_number];
            std::stringstream ss;
            std::stringstream ss2;
            std::string t_lvl;
            std::string t_hp;
            std::string t_name;
	        ss<<target_m[0].getMonsterLVL();
	        ss>>t_lvl;
            ss2<<target_m[0].getMonsterHP();
            ss2>>t_hp;
            t_name = target_m[0].getMonsterName();
            text.setString("TARGET: " + t_name + "\nLVL: " + t_lvl + "\nHP: " + t_hp);
        }

        player.update(time);
        window.setView(view);
        window.clear();

        for (int i = 0; i < HEIGHT_MAP; i++) {
            for (int j = 0; j < WIDTH_MAP; j++) {
                defineTile(i, j);
                map_sprite.setPosition(j * 64, i * 64);
                window.draw(map_sprite);
            }
        }

        setImagesToSpellsInventory();
        setImagesToHotbar();
        gui();

        for (int lol = 0; lol < other_sprites.size(); lol++) {
            window.draw(other_sprites[lol]);
        }
        window.draw(herosprite);
        if (attack_animation != 0) {
            window.draw(AnimationWoodenSwordSprite);
        }
        if (defence && inv_items[28] != 0) {
            window.draw(EquipedShieldSprite);
        }
        window.draw(GuiSpellsHotbarSprite);
        for (int i = 0; i < 9; i++) {
            window.draw(SpellsHotbarSprites[i]);
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
            for (int i = 0; i < 27; i++) {
                window.draw(InventoryItemsSprite[i]);
            }
        }
        if (is_spells_inventory_open) {
            window.draw(GuiSpellsInventorySprite);
            for (int i = 0; i < 27; i++) {
                window.draw(SpellsInventoryPageSprite[i]);
            }
        }
        window.draw(GuiBarSprite);
        if (is_stats_open) {
            window.draw(GuiStatsSprite);
        }
        if (text_item_info.getString() != "") {
            window.draw(GuiInfoSprite);
        }
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
    while(true){}
	return 0;
}
