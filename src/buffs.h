if (buffs[v] == "ColdSnap") {
    if (timer_ColdSnapTick == 0 && dealt) { //replace with some global counter
        hp -= 1;
        std::cout << "WORKS!\n";
        timer_ColdSnapTick = 1000;
    }
    if (timers[v] <= 0) {
        timer_ColdSnapTick = 0;
    }
}
