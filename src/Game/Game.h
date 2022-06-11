#include "WindowManager.h"
#include "Renderer.h"
#include "Player/Player.h"
#include "NPC/NPC.h"

class Game: public Renderer {
public:
    float time;
    Clock clock;
    std::shared_ptr<Player> player;
    std::vector<NPC> v_NPC;
    std::vector<int> items_dropped_id;
    std::vector<int> items_dropped_x;
    std::vector<int> items_dropped_y;
    std::vector<int> items_dropped_sprite;
    std::vector<int> items_dropped_type; //replace with one vector

    Game() = default;

    void initResources(auto &map_manager) {
        createMapSprite("map.png", map_manager);
        //createGuiSprites()...
    }
    void viewSetCenter() {
        view.setCenter(player->getX(), player->getY());
    }
    void drawSprites(auto &map_manager) {
        for (int i = 0; i < map_manager.getMapHeight(); i++) {
            for (int j = 0; j < map_manager.getMapWidth(); j++) {
                map_manager.defineTile(i, j);
                map_manager.setSpritePosition(j * 64, i * 64);
                window->draw(map_manager.getSprite());
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
    void updates(auto &map_manager) {
        time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time/800;
        player->update(time, map_manager, v_NPC, items_dropped_id);
        viewSetCenter();
    }
};
