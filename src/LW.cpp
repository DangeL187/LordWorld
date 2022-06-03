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
    void windowHandleEvents() {
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
public:
    std::vector<Sprite> v_sprites;

    Renderer() {

    }

    void createSprite(std::string name) {
        Image image;
        Texture texture;
        Sprite sprite;
        image.loadFromFile("../images/map.png");
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        sprite.setPosition(300, 300);
        v_sprites.push_back(sprite);
    }
    void drawSprites() {
        for (auto& i_sprite : v_sprites) {
            window->draw(i_sprite);
        }
    }
};

int main() {
    Game game;

    while(game.windowIsOpen()) {
        game.windowHandleEvents();
        game.windowSetView();
        game.windowClear();
        //Renderer.createSprite("map.png"); // ???
        game.windowDisplay();
    }

    return 0;
}
