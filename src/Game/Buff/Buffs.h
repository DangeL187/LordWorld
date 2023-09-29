#include "Buff.h"

class ColdSnap: public Buff {
private:
    float timer_tick = 1000;
public:
    ColdSnap(float duration):
    Buff(duration) {
        name = "ColdSnap";
    }
    void update(auto& game, auto& monster) {
        std::vector<std::reference_wrapper<float>> timers;
        timers.push_back(timer_tick);
        updateTimers(timers, game.update_manager->getTime());

        if (timer_tick == 0 && monster.isDealt()) {
            monster.setHP(monster.getHP() - 1 * game.player->magic_ice);
            timer_tick = 1000;
        }
        if (timer_buff <= 0) {
            timer_tick = 0;
        }
    }
};
class AttackStun: public Buff {
public:
    AttackStun(float duration):
    Buff(duration) {
        name = "AttackStun";
    }
    void update(auto& game, auto& monster) {
        std::vector<std::reference_wrapper<float>> timers;
        updateTimers(timers, game.update_manager->getTime());
        monster.stunMonster(true);
    }
};
