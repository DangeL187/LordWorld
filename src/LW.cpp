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

#include "game_vars.h"
#include "init_gui.h"
#include "init_text.h"
#include "init_images.h"
#include "equipment.h" //set equipment
#include "createItem.h"
#include "classes.h"
#include "drawmap.h" //-> defineTile()
#include "weapon_types.h"
#include "gui.h"
#include "info.h"

std::vector<Monster> v_monsters; //all monsters
std::vector<Monster> target_m; //targeted monster
std::vector<NPC> v_NPC; //all NPCs
std::vector<int> damaged_numbers; //monsters under attack

#include "game_functions.h"
#include "spells.h"
#include "text.h"
#include "updates.h"
#include "global_timers.h"
#include "attacks.h"
#include "animations.h"
#include "gainLVL.h"
#include "monsterDeath.h"
#include "guiTarget.h"
#include "draw_sprites.h"

int main() {
    #include "images.h" //load images

    inv_spells[0] = 1;
    inv_spells[1] = 2;
    hotbar_spells[0] = 1; //temp

    setText();

    for (int i = 0; i <= 33; i++) { //add zero items in inventory
        inv_items[i] = 0;
    }

    std::cout << "I tink its k\n";

    RenderWindow window(VideoMode(1920, 1080), "Lord World", sf::Style::Fullscreen);
    view.reset(FloatRect(0, 0, 1920, 1080));

    Player player(500, 500, 50.0, 62.0);

    createNPC(392, 386, 50.0, 62.0, "Trader");
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

        updates(time);
        global_timers(time);
        attacks(time);
        animations(player, time);
        gainLVL();
        monsterDeath();

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        #include "keys.h"

        guiTarget();

        player.update(time, v_NPC);
        window.setView(view);
        window.clear();

        setImagesToSpellsInventory();
        setImagesToHotbar();
        gui();
        draw_sprites(window);
    }
    while(true){}
	return 0;
}
