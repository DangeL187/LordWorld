#include "Map/Map.h"
#include "Window/WindowManager.h"
#include "Graphics/Renderer.h"
#include "Info/Info.h"
#include "Buff/BuffManager.h"
#include "Spell/SpellManager.h"
#include "Entities/EntityManager.h"
#include "Player/Player.h"
#include "Update/UpdateManager.h"

class Game {
private:
    void createEntityManager() {
        entity_manager = std::make_shared<EntityManager>();
    }
    void createRenderer() {
        renderer = std::make_shared<Renderer>(map);
    }
    void createSpellManager() {
        spell_manager = std::make_shared<SpellManager>();
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

public:
    Monster *target_m = NULL; //pointer to targeted monster
    std::shared_ptr<Player> player;
    std::shared_ptr<Map> map;
    std::shared_ptr<Renderer> renderer;
    std::shared_ptr<SpellManager> spell_manager;
    std::shared_ptr<EntityManager> entity_manager;
    std::shared_ptr<UpdateManager> update_manager;
    std::shared_ptr<WindowManager> window_manager;

    Game() {
        createWindowManager("Lord World", 1920, 1080);
        createMap();
        createRenderer();
        createEntityManager();
        createSpellManager();
        createUpdateManager();
        window_manager->viewReset();
        createPlayer(500, 500, 44.0, 64.0);
        entity_manager->createMonster(300, 300, 50.0, 62.0, 1, renderer->sprite_manager);
        entity_manager->createMonster(400, 400, 50.0, 62.0, 2, renderer->sprite_manager);
        entity_manager->createNPC(800, 804, 44.0, 64.0, 1, renderer->sprite_manager);
        entity_manager->createItem(600, 600, 1, renderer->sprite_manager);
        entity_manager->createItem(700, 600, 2, renderer->sprite_manager);
        entity_manager->createItem(800, 600, 3, renderer->sprite_manager);
        entity_manager->createItem(900, 600, 4, renderer->sprite_manager);
        entity_manager->createItem(1000, 600, 5, renderer->sprite_manager);
        entity_manager->createItem(1100, 600, 6, renderer->sprite_manager);

        //just for testing:
        player->hotbar_spells[0] = 1;
        player->hotbar_spells[1] = 2;
        player->hotbar_spells[2] = 1;
        player->hotbar_spells[3] = 2;
        player->hotbar_spells[4] = 1;
        player->hotbar_spells[5] = 2;
        player->hotbar_spells[6] = 1;
        player->hotbar_spells[7] = 2;
        player->hotbar_spells[8] = 1;
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
};
