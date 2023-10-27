#include "NewSprite.h"
#include "Map/Map.h"
#include "Window/WindowManager.h"
#include "Buff/BuffManager.h"
#include "Entities/EntityManager.h"
#include "Spell/Spell.h"
#include "Player/Player.h"
#include "Spell/Spells.h"
#include "Graphics/Renderer.h"
#include "Update/UpdateManager.h"

class Game {
public:
    std::shared_ptr<Player> player;
    std::shared_ptr<Map> map;
    std::shared_ptr<Renderer> renderer;
    std::shared_ptr<EntityManager> entity_manager;
    std::shared_ptr<UpdateManager> update_manager;
    std::shared_ptr<WindowManager> window_manager;

    Game() {
        createWindowManager("Lord World", 1920, 1080);
        window_manager->viewReset();
        createMap();
        createRenderer();
        createEntityManager();
        createUpdateManager();
        createPlayer(500, 500, 44.0, 64.0);
        entity_manager->createMonster(300, 300, 50.0, 62.0, 1);
        entity_manager->createMonster(400, 400, 50.0, 62.0, 2);
        entity_manager->createNPC(800, 804, 44.0, 64.0, 1);
        entity_manager->createItem(600, 600, 1);
        entity_manager->createItem(700, 600, 2);
        entity_manager->createItem(800, 600, 3);
        entity_manager->createItem(900, 600, 4);
        entity_manager->createItem(1000, 600, 5);
        entity_manager->createItem(1100, 600, 6);
        entity_manager->createItem(1200, 600, 7);
        entity_manager->createItem(1300, 600, 7);
        entity_manager->createItem(1400, 600, 7);

        //just for testing:
        player->hotbar_spells[0] = std::make_shared<ColdSnap>(player);
        player->hotbar_spells[1] = std::make_shared<ColdSnap2>(player);
        player->hotbar_spells[2] = std::make_shared<ColdSnap>(player);
        player->hotbar_spells[3] = std::make_shared<ColdSnap2>(player);
        player->hotbar_spells[4] = std::make_shared<ColdSnap>(player);
        player->hotbar_spells[5] = std::make_shared<ColdSnap2>(player);
        player->hotbar_spells[6] = std::make_shared<ColdSnap>(player);
        player->hotbar_spells[7] = std::make_shared<ColdSnap2>(player);
    }
    void run() {
        while(window_manager->windowIsOpen()) {
            window_manager->windowHandleEvents();
            window_manager->windowSetView();
            window_manager->windowClear();
            update_manager->update(*this);
            renderer->draw(*this);

            window_manager->windowDisplay();
        }
    }
private:
    void createEntityManager() {
        entity_manager = std::make_shared<EntityManager>();
    }
    void createRenderer() {
        renderer = std::make_shared<Renderer>();
    }
    void createUpdateManager() {
        update_manager = std::make_shared<UpdateManager>();
    }
    void createWindowManager(std::string name, int w, int h) {
        window_manager = std::make_shared<WindowManager>(name, w, h);
    }
    void createMap() {
        map = std::make_shared<Map>();
    }
    void createPlayer(float x, float y, float w, float h) {
        player = std::make_shared<Player>(x, y, w, h);
    }
};
