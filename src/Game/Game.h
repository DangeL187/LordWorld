#include "WindowManager.h"
#include "Renderer.h"
#include "Player.h"

class Game: public Renderer {
public:
    float time;
    Clock clock;
    std::shared_ptr<Player> player;

    Game() = default;

    void initResources() {
        createMapSprite("map.png");
        //createGuiSprites()...
    }
    void viewSetCenter() {
        view.setCenter(player->getX(), player->getY());
    }
    void drawSprites() {
        for (int i = 0; i < HEIGHT_MAP; i++) {
            for (int j = 0; j < WIDTH_MAP; j++) {
                defineTile(i, j);
                map_sprite.setPosition(j * 64, i * 64);
                window->draw(map_sprite);
            }
        }
        for (auto& i_sprite: gui_sprites) {
            window->draw(i_sprite);
        }
        window->draw(player->getSprite());
    }
    void createPlayer() {
        player = std::make_shared<Player>(500, 500, 50.0, 62.0);
    }
    void updates() {
        time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time/800;
        player->update(time);
        viewSetCenter();
    }
};
