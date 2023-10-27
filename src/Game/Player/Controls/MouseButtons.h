#include "Casting.h"

class MouseButtons: virtual public Initializer, protected Casting {
protected:
    void mouseButtons(auto& game) {
        mouseLeft(game);
        mouseRight(game);
    }
private:
    void mouseLeft(auto& game) {
        if (Mouse::isButtonPressed(Mouse::Left)) {
            if (key_m1) {
                key_m1_go = true;
            }
            if (hold_attack_timer->isOver()) {
                if (attack_animation == 0) {
                    is_attack_stun = true;
                }
            }
            if (is_defence) {
                hold_attack_timer->run(1000);
            }
        } else {
            key_m1 = true;
            if (key_m1_go && !Mouse::isButtonPressed(Mouse::Right)) {
                if (!is_inventory_open && !is_inventory_spells_open && attack_animation == 0 && !is_aiming && !is_defence && attack1_cd->isOver()) {
                    attack_type = 1; //first type of attack
                } else {
                    attack_type = 0;
                }
                if (is_aiming) {
                    is_aiming = false;
                    key_m1 = false;
                    castSpell(game.entity_manager->v_monsters);
                }
                key_m1_go = false;
            }
            hold_attack_timer->run(1000);
        }
    }
    void mouseRight(auto& game) {
        if (Mouse::isButtonPressed(Mouse::Right) && key_m2) {
            key_m2_go = true;
        }
        if (!Mouse::isButtonPressed(Mouse::Right)) {
            key_m2 = true;
            if (key_m2_go && !Mouse::isButtonPressed(Mouse::Left)) {
                bool is_ctrl = Keyboard::isKeyPressed(Keyboard::LControl);
                if (!is_inventory_open && !is_inventory_spells_open && attack_animation == 0 && attack2_cd->isOver() && !is_ctrl) {
                    attack_type = 2; //second type of attack
                } else {
                    attack_type = 0;
                }
                if (is_aiming) {
                    is_aiming = false;
                    key_m2 = false;
                }
                game.renderer->interface_manager->interface_inventory.event(game.player);
                key_m2_go = false;
            }
        }
    }
};
