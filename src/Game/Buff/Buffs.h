#include "Buff.h"

class ColdSnapBuff: public Buff {
private:
    std::shared_ptr<Timer> tick_timer;
public:
    ColdSnapBuff(float duration):
    Buff(duration) {
        name = "ColdSnap";
        tick_timer = std::make_shared<Timer>();
        tick_timer->run(1000);
    }
    void update(auto& game, auto& monster) {
        if (tick_timer->getTime() == 0 && monster.isDealt()) {
            //std::cout << "BUFF!\n";
            //TODO: add dynamic text
            monster.setHP(monster.getHP() - 1 * game.player->magic_ice);
            tick_timer->run(1000);
        }
        if (buff_timer->getTime() <= 0) {
            tick_timer->stop();
        }
    }
};
class AttackStunBuff: public Buff {
public:
    AttackStunBuff(float duration):
    Buff(duration) {
        name = "AttackStun";
    }
    void update(auto& game, auto& monster) {
        monster.stunMonster(true);
    }
};
