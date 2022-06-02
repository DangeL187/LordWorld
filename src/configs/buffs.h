if (buffs[v] == "ColdSnap") {
    if (timer_ColdSnap_tick == 0 && dealt) { //replace with some global counter
        hp -= 1 * magic_ice;
        timer_ColdSnap_tick = 1000;
    }
    if (timers[v] <= 0) {
        timer_ColdSnap_tick = 0;
    }
}
if (buffs[v] == "AttackStun") {
    stun = true;
}
