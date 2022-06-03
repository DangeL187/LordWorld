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

class NewSprite {
public:
    Image image;
    Texture texture;
    Sprite sprite;

    NewSprite() {
        image.loadFromFile("../images/map.png");
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        sprite.setPosition(300, 300);
    }
    Sprite getSprite() {
        return sprite;
    }
};

class Game {
protected:
    View view;
    unsigned int window_w = 1920;
    unsigned int window_h = 1080;
    std::shared_ptr<RenderWindow> window;
    Clock clock;
    float time;
    float player_x = 300;
    float player_y = 300;
public:
    //Game() { }
};

class Renderer: public Game {
public:
    std::vector<Sprite> v_sprites;

    Renderer() {

    }

    void createWindow() {
        window = std::make_shared<RenderWindow>(VideoMode(window_w, window_h), "Lord World");
    }
    void viewReset() {
        view.reset(FloatRect(0, 0, window_w, window_h));
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
    bool windowIsOpen() {
        return window->isOpen();
    }

    void createSprite(std::string name) {
        NewSprite *new_sprite = new NewSprite();
        v_sprites.push_back(new_sprite->getSprite());
    }
    void drawSprites() {
        for (auto& i_sprite : v_sprites) {
            window->draw(i_sprite);
        }
    }
};

int main() {
    Game game;
    Renderer renderer;

    renderer.createWindow();
    renderer.viewReset();

    renderer.createSprite("map.png");

    while(renderer.windowIsOpen()) {
        renderer.windowHandleEvents();
        renderer.windowSetView();
        renderer.windowClear();
        renderer.drawSprites();
        renderer.windowDisplay();
    }

    return 0;
}
