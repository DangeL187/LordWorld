#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <array>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <cmath>
#include <memory>
#include <functional>
#include <variant>
#include "split.h"
#define PI 3.14159265
using namespace sf;
#include "Game/Game.h"

int main() {
    Game game;

    game.createWindowManager("Lord World", 1920, 1080);
    game.createMap();
    game.createRenderer();
    game.createEntityManager();
    game.createUpdateManager();
    game.window_manager->viewReset();
    game.createPlayer(500, 500, 44.0, 64.0);
    game.entity_manager->createMonster(300, 300, 50.0, 62.0, 1, game);
    game.entity_manager->createMonster(400, 400, 50.0, 62.0, 2, game);
    game.createNPC(800, 804, 44.0, 64.0, "Trader");
    game.entity_manager->createItem(600, 600, 1, game);
    game.entity_manager->createItem(700, 600, 2, game);

    while(game.window_manager->windowIsOpen()) {
        //game.createMonster(400, 400, 50.0, 62.0, "Rat"); //stress test
        game.window_manager->windowHandleEvents();
        game.window_manager->windowSetView();
        game.window_manager->windowClear();
        game.update_manager->update(game);
        game.renderer->sprite_manager->drawSprites(game);
        game.window_manager->windowDisplay();
    }

    return 0;
}
