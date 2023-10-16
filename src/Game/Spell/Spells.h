#include "Spell.h"

class ColdSnap: public Spell {
public:
    ColdSnap(auto& game) {
        buff_duration = 5000;
        cooldown = 15000;
        damage_from_spell = 2 * game.player->magic_ice;
        mana_cost = 5;
        aoe_range = 64; //area of effect
        cast_range = 300;
    }

    void cast(auto& game) {
        float player_x = game.player->getX();
        float player_y = game.player->getY();
        float mouse_x = player_x - (962 - Mouse::getPosition().x);
        float mouse_y = player_y - (544 - Mouse::getPosition().y);
        float player_center_x = player_x + game.player->getWidth() / 2;
        float player_center_y = player_y + game.player->getHeight() / 2;
        if (game.player->mp >= mana_cost && getDistanceBetween(mouse_x, mouse_y, player_center_x, player_center_y) <= cast_range) {
            for (auto& v: game.entity_manager->v_monsters) {
                float monster_x = v.getX();
                float monster_y = v.getY();
                float monster_center_x = monster_x + v.getWidth() / 2;
                float monster_center_y = monster_y + v.getHeight() / 2;
                if (getDistanceBetween(mouse_x, mouse_y, monster_center_x, monster_center_y) <= aoe_range) {
                    //std::cout << "FUCK " << damage_from_spell << "\n";
                    v.giveBuff(1, buff_duration);
                    v.hitMonster(damage_from_spell, game);
                    game.player->cooldowns[game.player->spell_slot] = cooldown;
                    game.player->mp -= mana_cost;
                    break;
                }
            }
        } else {
            game.renderer->sprite_manager->GuiNoManaSprites[game.player->spell_slot].setColor(sf::Color(0, 0, 0, 160));
        }
    }
};

class ColdSnap2: public Spell {
public:
    ColdSnap2(auto& game) {
        buff_duration = 5000;
        cooldown = 15000;
        damage_from_spell = 3 * game.player->magic_ice;
        mana_cost = 4;
        aoe_range = 64; //area of effect
        cast_range = 100;
    }

    void cast(auto& game) {
        float player_x = game.player->getX();
        float player_y = game.player->getY();
        float mouse_x = player_x - (962 - Mouse::getPosition().x);
        float mouse_y = player_y - (544 - Mouse::getPosition().y);
        float player_center_x = player_x + game.player->getWidth() / 2;
        float player_center_y = player_y + game.player->getHeight() / 2;
        if (game.player->mp >= mana_cost && getDistanceBetween(mouse_x, mouse_y, player_center_x, player_center_y) <= cast_range) {
            for (auto& v: game.entity_manager->v_monsters) {
                float monster_x = v.getX();
                float monster_y = v.getY();
                float monster_center_x = monster_x + v.getWidth() / 2;
                float monster_center_y = monster_y + v.getHeight() / 2;
                if (getDistanceBetween(mouse_x, mouse_y, monster_center_x, monster_center_y) <= aoe_range) {
                    //std::cout << "FUCK2 " << damage_from_spell << "\n";
                    v.giveBuff(1, buff_duration);
                    v.hitMonster(damage_from_spell, game);
                    game.player->cooldowns[game.player->spell_slot] = cooldown;
                    game.player->mp -= mana_cost;
                    break;
                }
            }
        } else {
            game.renderer->sprite_manager->GuiNoManaSprites[game.player->spell_slot].setColor(sf::Color(0, 0, 0, 160));
        }
    }
};
