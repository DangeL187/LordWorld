class Buff {
protected:
    std::string name;
    int timer_buff = 0;
public:
    Buff() {}

    void updateTimers(std::vector<std::reference_wrapper<int>> timers) {
        if (timers[v] > 0) {
            timers[v] -= time;
        } else {
            timers[v] = 0;
        }
        if (timer_ColdSnap_tick > 0) {
            timer_ColdSnap_tick -= time;
        } else {
            timer_ColdSnap_tick = 0;
        }
    }

    /*void defineBuff(auto& v, auto& game) {
        if (buffs[v] == "ColdSnap") {
            if (timer_ColdSnap_tick == 0 && dealt) { //replace with some global counter
                hp -= 1 * player->magic_ice;
                timer_ColdSnap_tick = 1000;
            }
            if (timers[v] <= 0) {
                timer_ColdSnap_tick = 0;
            }
        }
        if (buffs[v] == "AttackStun") {
            stun = true;
        }
    }*/
};
