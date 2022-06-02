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
#include "split.h"
using namespace sf;

class Game {
public:
    View view;
    Clock clock;
    unsigned int window_w = 1920;
    unsigned int window_h = 1080;
    float time;
    float player_x = 300;
    float player_y = 300;

    Game() {
        RenderWindow window(VideoMode(window_w, window_h), "Lord World");
        viewReset();

        while(window.isOpen()) {
            windowEventClosed(&window);
            
            window.setView(view);
            window.clear();
            window.display();
        }
    }

    void windowEventClosed(auto get_window) {
        Event event;
        while (get_window->pollEvent(event)) {
            if (event.type == Event::Closed) {
                get_window->close();
            }
        }
    }

    void viewReset() {
        view.reset(FloatRect(0, 0, window_w, window_h));
    }
};

int main() {
    Game game;

    return 0;
}
