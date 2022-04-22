#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstdlib>
#include <string.h>
#include <sstream>
#include <cmath>
#include "map.h"
#include "view.h"
#include "split.h"

using namespace sf;

Image GuiBarImage, GuiInventoryImage, GuiSpellsHotbarImage;
Texture GuiBarTexture, GuiInventoryTexture, GuiSpellsHotbarTexture;
Sprite GuiBarSprite, GuiInventorySprite, GuiSpellsHotbarSprite;

Image InventoryItemsImage[27];
Image InventoryItemEmptyImage;
Image InventoryItemHelmImage;
Image InventoryItemChestImage;
Image InventoryItemPantsImage;
Image InventoryItemBootsImage;
Image InventoryItemWeaponImage;
Image InventoryItemShieldImage;
Texture InventoryItemsTexture[27];
Texture InventoryItemEmptyTexture;
Texture InventoryItemHelmTexture;
Texture InventoryItemChestTexture;
Texture InventoryItemPantsTexture;
Texture InventoryItemBootsTexture;
Texture InventoryItemWeaponTexture;
Texture InventoryItemShieldTexture;
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

Image map_image;
Texture map_texture;
Sprite map_sprite;
Sprite herosprite;
std::vector<Sprite> other_sprites;

Font font; //шрифт
Text text("", font, 40);
Text player_stats_hp("", font, 40);
Text player_stats_mp("", font, 40);
Text player_stats_lvl("", font, 40);

int player_x = 0, player_y = 0;
int attack = 0;
int range = 1; //*64
int sprite_counter = 0;
int attack1_cd = 0;
int spell_slot = 0;
int timer_ColdSnap;
int timer_ColdSnap_tick;
int player_hp = 10000, player_mp = 10000, player_lvl = 1;
int damage = 1;
int attack_speed = 1000; //1 second
int weapon_type = 1; //1-circle attack; 2-straight; 3-conus; 4-front-back line;
int target_number = 0;
int inv_items[33]; //items inventory //from [24] to [26] - other
//[27] - weapon, [28] - shield, [29] - helmet, [30] - chestplate, [31] - pants, [32] - boots
int inv_types[24]; //item types invenory
int cooldowns[9] {0, 0, 0, 0, 0, 0, 0, 0, 0}; //cooldowns
float attack1_cd_timer = 0;
float current_frame = 0;
bool aiming_kid = false;
bool aiming = false;
bool is_inventory_open = false;
std::string spell_name;
std::string weapon = "Wooden Sword"; //temp weapon

#include "classes.h"
#include "drawmap.h"
#include "weapon_types.h"
#include "gui.h"
#include "init_images.h"

std::vector<Monster> v_monsters; //whole monsters
std::vector<Monster> target_m; //targeted monster
std::vector<int> damaged_numbers; //monsters under attack
std::vector<int> items_dropped_id; //rename to items_dropped
std::vector<int> items_dropped_x;
std::vector<int> items_dropped_y;
std::vector<int> items_dropped_sprites; //rename to sprite
std::vector<int> items_dropped_type; //0 - nothing, 1 - weapon, 2 - shield
//3 - helmet, 4 - chestplate, 5 - pants, 6 - boots, 7 - ring, 8.. - item
std::vector<std::string> inv_spells; //spells inventory
std::string hotbar_spells[4]; //spells hotbar

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
    int out = player_x - (960 - Mouse::getPosition().x);
	int outy = player_y - (570 - Mouse::getPosition().y);
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

void monstersDamaged() { //TODO: different types of damage range?
    damaged_numbers.clear();
	for (int v = 0; v < v_monsters.size(); v++) {
        float mx = v_monsters[v].getMonsterCoordinateX();
		float my = v_monsters[v].getMonsterCoordinateY();
		damaged_numbers.push_back(v);
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
    other_sprites[sprite_counter].setPosition(get_x, get_y);
    sprite_counter++;
    std::cout << "SPRITE CREATED " << sprite_counter << std::endl;
}

#include "spells.h"

int main() {
    hotbar_spells[0] = "ColdSnap"; //temp

    font.loadFromFile("../font/OceanSummer.ttf");
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

    #include "images.h" //load images

    std::cout << "I tink its k\n";

    RenderWindow window(VideoMode(1920, 1080), "Lord World", sf::Style::Fullscreen);
    view.reset(FloatRect(0, 0, 1920, 1080));

    Player player(500, 500, 50.0, 62.0);

    Monster rat(300, 300, 50.0, 62.0, "Rat");
    v_monsters.push_back(rat);
    Monster rat2(400, 400, 50.0, 62.0, "Rat2");
    v_monsters.push_back(rat2);

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
		}

        if (attack1_cd > 0) {
            attack1_cd -= time;
        } else {
            attack1_cd = 0;
        }
        for (int i = 0; i <= 9; i++) {
            if (cooldowns[i] > 0) {
                cooldowns[i] -= time;
            } else {
                cooldowns[i] = 0;
            }
        }

        if (attack == 1 && attack1_cd == 0) {
            monstersDamaged();
            for (int v = 0; v < damaged_numbers.size(); v++) {
                float mx = v_monsters[damaged_numbers[v]].getMonsterCoordinateX();
        		float my = v_monsters[damaged_numbers[v]].getMonsterCoordinateY();
                if (checkWeaponsRange(mx, my)) {
                    v_monsters[damaged_numbers[v]].hitMonster(damage, time);
                    attack = 0;
                }
            }
            attack1_cd = attack_speed;
        }

        for (int i = 0; i < v_monsters.size(); i++) {
            if (v_monsters[i].getMonsterHP() <= 0) {
                other_sprites.erase(other_sprites.begin() + v_monsters[i].getMonsterSprite());
                sprite_counter--;
                if (damaged_numbers[i] == target_number) {
                    target_m.erase(target_m.begin() + 0);
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

        gui();

        window.draw(herosprite);
        for (int lol = 0; lol < other_sprites.size(); lol++) {
            window.draw(other_sprites[lol]);
        }
        window.draw(GuiSpellsHotbarSprite);
        for (int i = 0; i < 9; i++) {
            window.draw(SpellsHotbarSprites[i]);
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
        window.draw(GuiBarSprite);
        window.draw(text);
        window.draw(player_stats_hp);
        window.draw(player_stats_mp);
        window.draw(player_stats_lvl);
        window.display();
    }
    while(true){}
	return 0;
}
