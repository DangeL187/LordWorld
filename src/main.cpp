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
#include "Map/Map.h"
#include "Graphics/NewSprite.h"
#include "Game/Game.h"
#include "Map/DefineTile.h"
#include "Game/WindowManager.h"
#include "Game/Renderer.h"

int main() {
    Game game;
    Renderer renderer;

    renderer.createWindow();
    renderer.viewReset();

    //renderer.createSprite("map.png");
    renderer.createMapSprite("map.png");

    while(renderer.windowIsOpen()) {
        renderer.windowHandleEvents();
        renderer.windowSetView();
        renderer.windowClear();

        //temp:
        renderer.viewSetCenter();
        //

        renderer.drawSprites();
        renderer.windowDisplay();
    }

    return 0;
}
