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

Sprite GuiBarSprite, GuiInventorySprite;
Image GuiBarImage, GuiInventoryImage;
Texture GuiBarTexture, GuiInventoryTexture;

//InventorySlots
Sprite InventorySlotsSprite[27];
Sprite InventorySlotHelmSprite;
Sprite InventorySlotChestSprite;
Sprite InventorySlotPantsSprite;
Sprite InventorySlotBootsSprite;
Sprite InventorySlotWeaponSprite;
Sprite InventorySlotShieldSprite;
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
//

Sprite herosprite;
Sprite herosprites[3];
std::vector<Sprite> other_sprites;
String File[3]{"../images/main.png", "../images/main0.png", "../images/main3.png"};
Image all_images[3]; Texture all_textures[3];
int sprite_counter = 0;

int player_x = 0, player_y = 0;
int attack = 0;
int range = 1; //*32
std::string spell_name;
bool aiming_kid = false;
bool aiming = false;
bool inventory_open = false;

int attack1_cd = 0;
int spell_slot = 0;
int timer_ColdSnap;
int timer_ColdSnapTick;
int cooldowns[9] {0, 0, 0, 0, 0, 0, 0, 0, 0}; //cooldowns

std::string weapon = "Wooden Sword";
int player_hp = 10000, player_mp = 10000, player_lvl = 1;
int damage = 1;
int attack_speed = 1000; //1 second
int weapon_type = 1; //1-circle attack; 2-straight; 3-conus; 4-front-back line;

#include "weapon_types.h"

#include "classes.h"

std::vector<Monster> v_monsters; //whole monsters
std::vector<Monster> target_m; //targeted monster
std::vector<int> damaged_numbers; //monsters under attack
int target_number = 0;
std::vector<Item> v_items; //whole items
std::vector<int> items_floor;
std::vector<int> items_floor_x;
std::vector<int> items_floor_y;
std::vector<int> items_floor_sprite;
int inv_items[33]; //items inventory
std::vector<std::string> inv_spells; //spells inventory
std::string hotbar_spells[4]; //spells hotbar

void targeting() {
    int out = player_x - (960 - Mouse::getPosition().x);
	int outy = player_y - (570 - Mouse::getPosition().y);
	for (int v = 0; v < v_monsters.size(); v++) {
		float mx = v_monsters[v].getmonstercoordinateX();
		float my = v_monsters[v].getmonstercoordinateY();
		if (mx/1 <= out && out <= mx/1 + range*64 && my/1 <= outy && outy <= my/1 + range*64) {
			if (target_m.size() == 0) { target_m.push_back(v_monsters[v]); target_number = v; }
			else { target_m[0] = v_monsters[v]; target_number = v; }
		}
	}
}

void spell_damaged() { //TODO: different types of damage range, unite it with monsters_damaged?
    damaged_numbers.clear();
    int out = player_x - (960 - Mouse::getPosition().x);
	int outy = player_y - (570 - Mouse::getPosition().y);
	for (int v = 0; v < v_monsters.size(); v++) {
		float mx = v_monsters[v].getmonstercoordinateX();
		float my = v_monsters[v].getmonstercoordinateY();
		if (mx/1 <= out && out <= mx/1 + range*64 && my/1 <= outy && outy <= my/1 + range*64) { //TODO: fix aoe range?
			damaged_numbers.push_back(v);
		}
	}
}

void monsters_damaged() { //TODO: different types of damage range?
    damaged_numbers.clear();
	for (int v = 0; v < v_monsters.size(); v++) {
		float mx = v_monsters[v].getmonstercoordinateX();
		float my = v_monsters[v].getmonstercoordinateY();
		damaged_numbers.push_back(v);
	}
}

Monster somemonster(float X0, float Y0, float W0, float H0, std::string NAME0) {
    Monster somemonster0(X0, Y0, W0, H0, NAME0);
    return somemonster0;
}

int main() {
    sf::RectangleShape rectangle(sf::Vector2f(120, 50));

    hotbar_spells[0] = "ColdSnap"; //temp
//text part
    //target:
    Font font;//шрифт
    font.loadFromFile("../font/OceanSummer.ttf");
    Text text("", font, 40);
    text.setColor(Color::White);
    //text.setStyle(sf::Text::Bold);
    //player:
    Text player_stats_hp("", font, 40);
    player_stats_hp.setColor(Color::White);
    player_stats_hp.setStyle(sf::Text::Bold);
    Text player_stats_mp("", font, 40);
    player_stats_mp.setColor(Color::White);
    player_stats_mp.setStyle(sf::Text::Bold);
    Text player_stats_lvl("", font, 40);
    player_stats_lvl.setColor(Color::White);
    player_stats_lvl.setStyle(sf::Text::Bold);
//
    //add zero items in inventory
    for (int i = 0; i <= 33; i++) {
        inv_items[i] = 0;
    }
    //

    #include "images.h"

    std::cout << "I tink its k\n";

    RenderWindow window(VideoMode(1920, 1080), "Lord World");
    view.reset(FloatRect(0, 0, 1920, 1080));

    Player p(500, 500, 50.0, 62.0);

    Monster rat(300, 300, 50.0, 62.0, "Rat");
    v_monsters.push_back(rat);
    Monster rat2(400, 400, 50.0, 62.0, "Rat2");
    v_monsters.push_back(rat2);

    Item item00(-3000, -3000, 50.0, 62.0, "Zero Item"); //zero item
    Item item1(600, 600, 50.0, 62.0, "Wooden Sword");
    v_items.push_back(item1); //add item1 to whole items
    items_floor.push_back(item1.getid()); //add item1's id to items_floor
    items_floor_x.push_back(item1.getitemcoordinateX()); //add item1's x to items_floor_x
    items_floor_y.push_back(item1.getitemcoordinateY()); //add item1's y to items_floor_y
    items_floor_sprite.push_back(item1.getitemsprite()); //add item1's' sprite to items_floor_sprite

    //for (int vi = 0; vi < v_items.size(); vi++) {
    //    items_floor.push_back(v_items[vi]);
    //}

    //Monster rat3 = somemonster(200, 200, 50.0, 62.0, "Rat");
    //v_monsters.push_back(rat3);
    //v_monsters.push_back(somemonster(300, 300, 25.0, 31.0, "Rat")); WHY DA FUCK IT DOESN'T WOOOOORK!?
    //v_monsters.push_back(somemonster(400, 400, 25.0, 31.0, "Rat2"));

    Image map_image;
	map_image.loadFromFile("../images/map.png");
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);

    float attack1_cd_timer = 0;
    float CurrentFrame = 0;
	Clock clock;

    while (window.isOpen()) {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time/800;

        for (int v0 = 0; v0 < v_monsters.size(); v0++) {
			v_monsters[v0].checkbuff(time);
            v_monsters[v0].update(time);
		}

        //temp:
        item00.update(time);
        item1.update(time);
        //

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
            monsters_damaged();
            for (int v = 0; v < damaged_numbers.size(); v++) {
                if (check_weapons_range(v_monsters[damaged_numbers[v]].getmonstercoordinateX(), v_monsters[damaged_numbers[v]].getmonstercoordinateY())) {
                    v_monsters[damaged_numbers[v]].hitmonster(damage, time);
                    attack = 0;
                }
            }
            attack1_cd = attack_speed;
        }

        for (int i = 0; i < v_monsters.size(); i++) {
            if (v_monsters[i].getmonsterHP() <= 0) {
                other_sprites.erase(other_sprites.begin() + v_monsters[i].getmonstersprite());
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
            std::stringstream ss; std::stringstream ss2; std::string t_lvl; std::string t_hp;
	        ss<<target_m[0].getmonsterLVL();
	        ss>>t_lvl;
            ss2<<target_m[0].getmonsterHP();
            ss2>>t_hp;
            text.setString("TARGET: " + target_m[0].getmonsterNAME() + "\nLVL: " + t_lvl + "\nHP: " + t_hp);
        }

        p.update(time);
        window.setView(view);
        window.clear();

        #include "drawmap.h"

        #include "gui.h"

        window.draw(herosprite);
        for (int lol = 0; lol < other_sprites.size(); lol++) {
            window.draw(other_sprites[lol]);
        }
        if (inventory_open) {
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
