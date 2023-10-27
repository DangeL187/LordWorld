#include "Buffs.h"

class BuffManager {
public:
    std::vector<std::shared_ptr<Buff>> v_buffs;

    BuffManager() = default;

    void giveBuff(int id, float duration) {
        switch (id) {
            case 1: {
                v_buffs.push_back(std::make_shared<ColdSnapBuff>(duration));
                break;
            }
            case 2: {
                v_buffs.push_back(std::make_shared<AttackStunBuff>(duration));
                break;
            }
        }
    }

    void update(auto& monster) {
        for (unsigned int v = 0; v < v_buffs.size(); v++) {
            bool stun_monster = false;
            v_buffs[v]->update(monster.isDealt(), monster.getHP(true), stun_monster); if (stun_monster) { monster.stunMonster(true); }
            if (v_buffs[v]->getBuffTime() == 0) {
                v_buffs.erase(v_buffs.begin() + v);
            }
        }
    }
};
