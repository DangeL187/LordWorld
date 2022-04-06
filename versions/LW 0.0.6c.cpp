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
#include "Files/map.h"
#include "Files/view.h"
#include "Files/split.h"

using namespace sf;

Sprite somesprite;
Sprite herosprite;
Sprite herosprites[3];
std::vector<Sprite> other_sprites;
String File[3]{"Images/main.png", "Images/main2.png", "Images/main3.png"};
Image all_images[3]; Texture all_textures[3];
int sprite_counter = 0;

int player_x = 0, player_y = 0;
int attack = 0;
int range = 1; //*32
std::string spell_name;
bool aiming_kid = false;
bool aiming = false;

int attack1_cd = 0;
int timer_ColdSnap;
int timer_ColdSnapTick;

std::string weapon = "Wooden Sword";
int player_hp = 0, player_mp = 0, player_lvl = 1;
int damage = 1;
int attack_speed = 1000; //1 second
int weapon_type = 1; //1-circle attack; 2-straight; 3-conus; 4-front-back line;

#include "Files/weapon_types.h"

#include "Files/classes.h"

std::vector<Monster> v_monsters; //whole monsters
std::vector<Monster> target_m; //targeted monster
std::vector<int> damaged_numbers; //monsters under attack
int target_number = 0;
//std::vector<std::string> inv_spells; //spells inventory
std::string inv_spells[4]; //spells hotbar

void targeting() {
    int out = player_x - (960 - Mouse::getPosition().x);
	int outy = player_y - (570 - Mouse::getPosition().y);
	for (int v = 0; v < v_monsters.size(); v++) {
		float mx = v_monsters[v].getmonstercoordinateX();
		float my = v_monsters[v].getmonstercoordinateY();
		if (mx/1 <= out && out <= mx/1 + range*32 && my/1 <= outy && outy <= my/1 + range*32) {
			if (target_m.size() == 0) { target_m.push_back(v_monsters[v]); target_number = v; }
			else { target_m[0] = v_monsters[v]; target_number = v; }
		}
	}
}

void spell_damaged() { //TODO: different types of damage range, unite it with monsters_damaged
    damaged_numbers.clear();
    int out = player_x - (960 - Mouse::getPosition().x);
	int outy = player_y - (570 - Mouse::getPosition().y);
	for (int v = 0; v < v_monsters.size(); v++) {
		float mx = v_monsters[v].getmonstercoordinateX();
		float my = v_monsters[v].getmonstercoordinateY();
		if (mx/1 <= out && out <= mx/1 + range*32 && my/1 <= outy && outy <= my/1 + range*32) { //TODO: fix aoe range
			damaged_numbers.push_back(v);
		}
	}
}

void monsters_damaged() { //TODO: different types of damage range
    damaged_numbers.clear();
	for (int v = 0; v < v_monsters.size(); v++) {
		float mx = v_monsters[v].getmonstercoordinateX();
		float my = v_monsters[v].getmonstercoordinateY();
		damaged_numbers.push_back(v);
	}
}

int main() {
    inv_spells[0] = "ColdSnap"; //temp
//text part
    //target:
    Font font;//шрифт
    font.loadFromFile("Font/OceanSummer.ttf");
    Text text("", font, 40);
    text.setColor(Color::White);
    //text.setStyle(sf::Text::Bold);
    //player:
    Text player_stats("", font, 50);
    player_stats.setColor(Color::Green);
    player_stats.setStyle(sf::Text::Bold);
//

    #include "Files/images.h"

    std::cout << "I tink its k\n";

    RenderWindow window(VideoMode(1920, 1080), "Lord World");
    view.reset(FloatRect(0, 0, 1920, 1080));

    Player p(500, 500, 25.0, 31.0);

    Monster test_rat(300, 300, 25.0, 31.0, "Rat");
    Monster test_rat2(400, 400, 25.0, 31.0, "Rat2");
    v_monsters.push_back(test_rat);
    v_monsters.push_back(test_rat2);

    Image map_image;
	map_image.loadFromFile("Images/map.png");
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
		}

        if (attack1_cd > 0) {
            attack1_cd -= time;
        } else {
            attack1_cd = 0;
        }

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

        #include "Files/keys.h"
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
        test_rat.update(time); //edit
        test_rat2.update(time);
        window.setView(view);
        window.clear();

        #include "Files/drawmap.h"

        window.draw(herosprite);
        for (int lol = 0; lol < other_sprites.size(); lol++) {
            window.draw(other_sprites[lol]);
        }

//
        std::stringstream ss; std::stringstream ss2; std::stringstream ss3;
        std::string p_lvl; std::string p_hp; std::string p_mp;
        ss<<player_lvl;
        ss>>p_lvl;
        ss2<<player_hp;
        ss2>>p_hp;
        ss3<<player_mp;
        ss3>>p_mp;
        player_stats.setString("LVL: " + p_lvl + "\nHP: " + p_hp + "\nMP: " + p_mp);
        player_stats.setPosition(view.getCenter().x - 950, view.getCenter().y - 500);
		text.setPosition(view.getCenter().x + 700, view.getCenter().y - 500);
        window.draw(player_stats);
        window.draw(text);
//

        window.display();

    }

	return 0;
}
