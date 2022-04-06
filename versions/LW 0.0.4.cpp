#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstdlib>
#include <string.h>
#include "Files/map.h"
#include "Files/view.h"
#include "Files/split.h"

using namespace sf;

Sprite herosprite;
Sprite herosprites[3];
Sprite other_sprites[100];
String File[3]{"Images/main.png", "Images/main2.png", "Images/main3.png"};
Image all_images[3]; Texture all_textures[3];

int attack = 0;
int attack1_cd = 0;
int range = 1; //*32

std::string weapon = "Wooden Sword";
int damage = 1;
int attack_speed = 5000; //5 seconds
//int weapon_type = 1; //1-circle attack; 2-straight; 3-conus; 4-front-back line;

int player_x = 0, player_y = 0;

#include "Files/weapon_types.h"

#include "Files/classes.h"

int main() {
    #include "Files/images.h"

    std::cout << "I tink its k\n";

    RenderWindow window(VideoMode(1920, 1080), "Lord World");
    view.reset(FloatRect(0, 0, 1920, 1080));

    Player p(500, 500, 25.0, 31.0);

    Monster test_rat(300, 300, 25.0, 31.0, "Rat");

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

        if (attack1_cd > 0) {
            attack1_cd -= time;
        }

        if (attack1_cd <= 0) {
            attack1_cd = 0;
		}

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        #include "Files/keys.h"

        p.update(time);
        test_rat.update(time);

        window.setView(view);
        window.clear();

        #include "Files/drawmap.h"

        window.draw(herosprite);
        for (int lol = 0; lol < 100; lol++) {
            window.draw(other_sprites[lol]);
        }
        window.display();

    }

	return 0;
}
