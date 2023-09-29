#include "Item/Items.h"
#include "Monster/Monsters.h"
#include "NPC/NPC.h"

class EntityManager {
public:
    std::vector<Item> v_items;
    std::vector<Monster> v_monsters;

    EntityManager() = default;

    void createItem(float x, float y, unsigned int id, auto& game) {
        int sprite = game.renderer->sprite_manager->loadItemSprite(x, y, id);
        switch (id) {
            case 1: {
                WoodenSword m(x, y, id, sprite);
                v_items.push_back(m);
                break;
            }
            case 2: {
                IronShield m(x, y, id, sprite);
                v_items.push_back(m);
                break;
            }
            case 3: {
                IronHelmet m(x, y, id, sprite);
                v_items.push_back(m);
                break;
            }
            case 4: {
                IronChestplate m(x, y, id, sprite);
                v_items.push_back(m);
                break;
            }
            case 5: {
                IronPants m(x, y, id, sprite);
                v_items.push_back(m);
                break;
            }
            case 6: {
                IronBoots m(x, y, id, sprite);
                v_items.push_back(m);
                break;
            }
            case 7: {
                IronRing m(x, y, id, sprite);
                v_items.push_back(m);
                break;
            }
            case 8: {
                RatTail m(x, y, id, sprite);
                v_items.push_back(m);
                break;
            }
        }
    }

    void createMonster(float x, float y, float w, float h, unsigned int id, auto& game) {
        int sprite = game.renderer->sprite_manager->loadMonsterSprite(x, y, w, h, id);
        switch (id) {
            case 1: {
                Rat m(x, y, w, h, id, sprite);
                v_monsters.push_back(m);
                break;
            }
            case 2: {
                Rat2 m(x, y, w, h, id, sprite);
                v_monsters.push_back(m);
                break;
            }
        }
    }
};
