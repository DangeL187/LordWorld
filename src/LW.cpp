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
#include "map.h"
using namespace sf;

class Game {
private:
    View view;
    unsigned int window_w = 1920;
    unsigned int window_h = 1080;
protected:
    Clock clock;
    float time;
    float player_x = 300;
    float player_y = 300;
    std::shared_ptr<RenderWindow> window;
public:
    Game() {
        window = std::make_shared<RenderWindow>(VideoMode(window_w, window_h), "Lord World");
        viewReset();
    }

    void viewReset() {
        view.reset(FloatRect(0, 0, window_w, window_h));
    }
    bool windowIsOpen() {
        return window->isOpen();
    }
    void windowEventClosed() {
        Event event;
        while (window->pollEvent(event)) {
            if (event.type == Event::Closed) {
                window->close();
            }
        }
    }
    void windowSetView() {
        window->setView(view);
    }
    void windowClear() {
        window->clear();
    }
    void windowDisplay() {
        window->display();
    }
};

class Renderer: public Game {
    Renderer() {

    }
};

int main() {
    Game game;

    while(game.windowIsOpen()) {
        game.windowEventClosed();
        game.windowSetView();
        game.windowClear();
        game.windowDisplay();
    }

    return 0;
}
