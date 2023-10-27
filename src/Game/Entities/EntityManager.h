#include "Item/Item.h"
#include "Item/Armor/Shields.h"
#include "Item/Armor/Helmets.h"
#include "Item/Armor/Chestplates.h"
#include "Item/Armor/Pants.h"
#include "Item/Armor/Boots.h"
#include "Item/Artifact/Artifacts.h"
#include "Item/Items.h"
#include "Item/Weapon/Weapons.h"
#include "Monster/Monsters.h"
#include "NPC/NPCs.h"

class EntityManager {
public:
    std::vector<Item> v_items;
    std::vector<Monster> v_monsters;
    std::vector<NPC> v_NPC;

    EntityManager() = default;

    void createItem(float x, float y, unsigned int id) {
        switch (id) {
            case 1: {
                WoodenSword m(x, y);
                v_items.push_back(m);
                break;
            }
            case 2: {
                IronShield m(x, y);
                v_items.push_back(m);
                break;
            }
            case 3: {
                IronHelmet m(x, y);
                v_items.push_back(m);
                break;
            }
            case 4: {
                IronChestplate m(x, y);
                v_items.push_back(m);
                break;
            }
            case 5: {
                IronPants m(x, y);
                v_items.push_back(m);
                break;
            }
            case 6: {
                IronBoots m(x, y);
                v_items.push_back(m);
                break;
            }
            case 7: {
                IronRing m(x, y);
                v_items.push_back(m);
                break;
            }
            case 8: {
                RatTail m(x, y);
                v_items.push_back(m);
                break;
            }
        }
    }

    void createMonster(float x, float y, float w, float h, unsigned int id) {
        switch (id) {
            case 1: {
                Rat m(x, y, w, h);
                v_monsters.push_back(m);
                break;
            }
            case 2: {
                Rat2 m(x, y, w, h);
                v_monsters.push_back(m);
                break;
            }
        }
    }

    void createNPC(float x, float y, float w, float h, unsigned int id) {
        switch (id) {
            case 1: {
                Trader m(x, y, w, h);
                v_NPC.push_back(m);
                break;
            }
        }
    }
};
