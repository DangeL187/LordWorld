#include "Buff.h"

class ColdSnap: public Buff {
private:
    int timer_tick = 0;
public:
    ColdSnap(auto& game, auto& monster):
    Buff() {
        name = "ColdSnap";
    }
    void update() {
        std::vector<std::reference_wrapper<int>> timers;
        timers.push_back(timer_tick);
        updateTimers(timers);

        if (timer_tick == 0 && monster->isDealt()) {
            monster->setHP(monster->getHP() - 1 * game.player->magic_ice);
            timer_tick = 1000;
        }
        if (timer_buff <= 0) {
            timer_tick = 0;
        }
    }
};
