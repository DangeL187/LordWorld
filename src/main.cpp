#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <array>
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
    game.initResources(map_manager);
    game.createPlayer(500, 500, 50.0, 62.0);

    while(game.windowIsOpen()) {
        game.windowHandleEvents();
        game.windowSetView();
        game.windowClear();

        game.updates(map_manager, game);

        game.drawSprites(map_manager);
        game.windowDisplay();
    }

    return 0;
}
