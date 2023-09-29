#include "Map/Map.h"
#include "Window/WindowManager.h"
#include "Graphics/Renderer.h"
#include "Info/Info.h"
#include "Buff/BuffManager.h"
#include "Spell/Spells.h"
#include "Player/Player.h"
#include "Entities/EntityManager.h"
#include "Update/UpdateManager.h"

class Game {
public:
    Monster *target_m = NULL; //pointer to targeted monster
    std::shared_ptr<Player> player;
    std::vector<NPC> v_NPC;
    std::vector<int> damaged_numbers;
    std::shared_ptr<Map> map;
    std::shared_ptr<WindowManager> window_manager;
    std::shared_ptr<Renderer> renderer;
    std::shared_ptr<EntityManager> entity_manager;
    std::shared_ptr<UpdateManager> update_manager;

    Game() = default;

    void createEntityManager() {
        entity_manager = std::make_shared<EntityManager>();
    }
    void createRenderer() {
        renderer = std::make_shared<Renderer>(map);
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
    void createNPC(float x, float y, float w, float h, std::string name) {
        NPC m(x, y, w, h, name, renderer->sprite_manager->NPC_sprites, renderer->sprite_manager->other_sprite_counter, renderer->sprite_manager->current_other_sprites);
        v_NPC.push_back(m);
    }

    void targeting(auto& game) {
        int out = game.player->getX() - (962 - Mouse::getPosition().x);
        int outy = game.player->getY() - (544 - Mouse::getPosition().y);
        for (int v = 0; v < game.entity_manager->v_monsters.size(); v++) {
            float mx = game.entity_manager->v_monsters[v].getX();
    		float my = game.entity_manager->v_monsters[v].getY();
            float condx = mx/1 + 64 - 14;
            float condy = my/1 + 64;
            if (mx/1 <= out && out <= condx && my/1 <= outy && outy <= condy) {
                target_m = &game.entity_manager->v_monsters[v];
            }
        }
    }
    void spellDamaged(auto& game) { //TODO: different types of damage range
        damaged_numbers.clear();
        int out = game.player->getX() - (962 - Mouse::getPosition().x);
    	int outy = game.player->getY() - (544 - Mouse::getPosition().y);
    	for (int v = 0; v < game.entity_manager->v_monsters.size(); v++) {
            float mx = game.entity_manager->v_monsters[v].getX();
    		float my = game.entity_manager->v_monsters[v].getY();
            float condx = mx/1 + 1*64; //replace with unique number
            float condy = my/1 + 1*64; //replace with unique number
    		if (mx/1 <= out && out <= condx && my/1 <= outy && outy <= condy) { //TODO: fix aoe range?
    			damaged_numbers.push_back(v);
    		}
    	}
    }
};
