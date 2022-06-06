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
#include <memory>
#include "split.h"
using namespace sf;
#include "Graphics/NewSprite.h"
#include "Map/DefineTile.h"
#include "Game/Game.h"

int main() {
    Game game;

    game.createWindow();
    game.viewReset();
    game.initResources();
    game.createPlayer();

    while(game.windowIsOpen()) {
        game.windowHandleEvents();
        game.windowSetView();
        game.windowClear();

        game.updates();

        game.drawSprites();
        game.windowDisplay();
    }

    return 0;
}
