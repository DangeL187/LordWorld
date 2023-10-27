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
    void update(bool is_dealt, int& hp, bool& stun_monster) override {
        if (tick_timer->isOver() && is_dealt) {
            //std::cout << "BUFF!\n";
            //TODO: add dynamic text
            hp -= 1;
            tick_timer->run(1000);
        }
    }
};
class AttackStunBuff: public Buff {
public:
    AttackStunBuff(float duration):
    Buff(duration) {
        name = "AttackStun";
    }
    void update(bool is_dealt, int& hp, bool& stun_monster) override {
        stun_monster = true;
    }
};
