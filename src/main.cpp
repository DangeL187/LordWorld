#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <array>
#include <fstream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstdlib>
#include <string>
#include <sstream>
#include <cmath>
#include <memory>
#include "split.h"
using namespace sf;
#include "Graphics/NewSprite.h"
#include "Map/MapManager.h"
#include "Game/Game.h"

int main() {
    MapManager map_manager;
    Game game;

    game.createWindow();
    game.viewReset();
    game.initResources(map_manager, game);
    game.createPlayer(500, 500, 44.0, 64.0);
    game.createMonster(300, 300, 50.0, 62.0, "Rat");
    game.createMonster(400, 400, 50.0, 62.0, "Rat");
    game.createItem(1, 600, 600);
    game.createItem(2, 700, 600);
    //game.AnimationWeaponSprite = game.AnimationWoodenSwordSprite;
    game.AnimationWeaponSprite.setTextureRect(IntRect(0, 0, 1, 1));

    while(game.windowIsOpen()) {
        //game.createMonster(400, 400, 50.0, 62.0, "Rat"); //stress test
        game.windowHandleEvents();
        game.windowSetView();
        game.windowClear();

        game.updates(map_manager, game);
        game.drawSprites(map_manager);
        game.windowDisplay();
    }

    return 0;
}
