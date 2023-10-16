#include "Buffs.h"

class BuffManager {
public:
    #include "ListOfBuffs.h" // "So this is where the magic happens" (read docs!)

    BuffManager() = default;

    void giveBuff(int id, float duration) {
        switch (id) {
            case 1: {
                ColdSnapBuff m(duration);
                v_buffs.push_back(m);
                break;
            }
            case 2: {
                AttackStunBuff m(duration);
                v_buffs.push_back(m);
                break;
            }
        }
    }
    void update(auto& game, auto& monster) {
        for (int v = 0; v < v_buffs.size(); v++) {
            std::visit([&](auto& i) { i.update(game, monster); }, v_buffs[v]);
            float buff_time = std::visit([](auto& i) { return i.getBuffTime(); }, v_buffs[v]);
            if (buff_time == 0) {
                v_buffs.erase(v_buffs.begin() + v);
            }
        }
    }
};
