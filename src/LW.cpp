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

Image GuiBarImage, GuiInventoryImage;
Texture GuiBarTexture, GuiInventoryTexture;
Sprite GuiBarSprite, GuiInventorySprite;

Image InventorySlotsImage[27];
Image InventorySlotHelmImage;
Image InventorySlotChestImage;
Image InventorySlotPantsImage;
Image InventorySlotBootsImage;
Image InventorySlotWeaponImage;
Image InventorySlotShieldImage;
Texture InventorySlotsTexture[27];
Texture InventorySlotHelmTexture;
Texture InventorySlotChestTexture;
Texture InventorySlotPantsTexture;
Texture InventorySlotBootsTexture;
Texture InventorySlotWeaponTexture;
Texture InventorySlotShieldTexture;
Sprite InventorySlotsSprite[27];
Sprite InventorySlotHelmSprite;
Sprite InventorySlotChestSprite;
Sprite InventorySlotPantsSprite;
Sprite InventorySlotBootsSprite;
Sprite InventorySlotWeaponSprite;
Sprite InventorySlotShieldSprite;

String File[3]{"../images/main.png", "../images/main0.png", "../images/main3.png"};
Image all_images[3];
Image map_image;
Texture all_textures[3];
Texture map;
Sprite herosprite;
Sprite s_map; //rename to map_sprite
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
int inv_items[33]; //items inventory
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

std::vector<Monster> v_monsters; //whole monsters
std::vector<Monster> target_m; //targeted monster
std::vector<Item> v_items; //whole items
std::vector<int> damaged_numbers; //monsters under attack
std::vector<int> items_floor;
std::vector<int> items_floor_x;
std::vector<int> items_floor_y;
std::vector<int> items_floor_sprites;
std::vector<std::string> inv_spells; //spells inventory
std::string hotbar_spells[4]; //spells hotbar

void targeting() {
    int out = player_x - (960 - Mouse::getPosition().x);
	int outy = player_y - (570 - Mouse::getPosition().y);
	for (int v = 0; v < v_monsters.size(); v++) {
		float mx = v_monsters[v].getMonsterCoordinateX();
		float my = v_monsters[v].getMonsterCoordinateY();
        float condx = mx/1 + range*64;
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

Image tempImage1; //temp!
Texture tempTexture1;
Sprite tempSprite1;
Image tempImage2;
Texture tempTexture2;
Sprite tempSprite2;

int createItem(int ID, int get_x, int get_y) {
    items_floor.push_back(ID);
    items_floor_x.push_back(get_x);
    items_floor_y.push_back(get_y);
    items_floor_sprites.push_back(sprite_counter);

    if (ID == 0) {
        other_sprites.push_back(tempSprite2);
    }
    if (ID == 1) {
        other_sprites.push_back(tempSprite1);
    }

    other_sprites[sprite_counter].setTextureRect(IntRect(0, 0, 100, 100));
    other_sprites[sprite_counter].setPosition(get_x, get_y);
    sprite_counter++;
    std::cout << "SPRITE CREATED " << sprite_counter << std::endl;
}

#include "spells.h"

int main() {
    hotbar_spells[0] = "ColdSnap"; //temp

    tempImage1.loadFromFile("../images/Wooden Sword.png");
    tempTexture1.loadFromImage(tempImage1);
    tempSprite1.setTexture(tempTexture1);
    tempImage2.loadFromFile("../images/Zero Item.png");
    tempTexture2.loadFromImage(tempImage2);
    tempSprite2.setTexture(tempTexture2);

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

    RenderWindow window(VideoMode(1920, 1080), "Lord World");
    view.reset(FloatRect(0, 0, 1920, 1080));

    Player player(500, 500, 50.0, 62.0);

    Monster rat(300, 300, 50.0, 62.0, "Rat");
    v_monsters.push_back(rat);
    Monster rat2(400, 400, 50.0, 62.0, "Rat2");
    v_monsters.push_back(rat2);

    //v_items.push_back(item1); //add item1 to whole items
    //items_floor.push_back(item1.getItemID()); //add item1's id to items_floor
    //items_floor_x.push_back(item1.getItemCoordinateX()); //add item1's x to items_floor_x
    //items_floor_y.push_back(item1.getItemCoordinateY()); //add item1's y to items_floor_y
    //items_floor_sprites.push_back(item1.getItemSprite()); //add item1's' sprite to items_floor_sprite
    //items_floor_static_sprites.push_back(item1.getItemStaticSprite());

    createItem(1, 600, 600);
    createItem(0, 700, 700);

    map_image.loadFromFile("../images/map.png");
    map.loadFromImage(map_image);
    s_map.setTexture(map);

    Clock clock;

    while (window.isOpen()) {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time/800;

        for (int v0 = 0; v0 < v_monsters.size(); v0++) {
			v_monsters[v0].checkBuff(time);
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
        //std::cout << "?: " << cooldowns[0] << std::endl;
        //for (int i = 0; i <= 33; i++) {
        //    std::cout << "INV: " << inv_items[i] << std::endl;
        //}
        //std::cout << "INV: " << inv_items[0] << std::endl; //TEMP, TODO: DELETE

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
                v_monsters.erase(v_monsters.begin() + i);
                if (damaged_numbers[i] == target_number) {
                    target_m.erase(target_m.begin() + 0);
                }
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
                s_map.setPosition(j * 64, i * 64);
                window.draw(s_map);
            }
        }

        gui();

        window.draw(herosprite);
        for (int lol = 0; lol < other_sprites.size(); lol++) {
            window.draw(other_sprites[lol]);
        }
        if (is_inventory_open) {
            window.draw(GuiInventorySprite);
            window.draw(InventorySlotWeaponSprite);
            window.draw(InventorySlotShieldSprite);
            window.draw(InventorySlotChestSprite);
            window.draw(InventorySlotHelmSprite);
            window.draw(InventorySlotPantsSprite);
            window.draw(InventorySlotBootsSprite);
            for (int i = 0; i < 27; i++) {
                window.draw(InventorySlotsSprite[i]);
            }
        }
        window.draw(GuiBarSprite);
        window.draw(text);
        window.draw(player_stats_hp);
        window.draw(player_stats_mp);
        window.draw(player_stats_lvl);
        window.display();
//
    }
	return 0;
}
