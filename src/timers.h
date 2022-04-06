if (timers[v] > 0) {
    timers[v] -= globaltime;
} if (timers[v] <= 0) {
    timers[v] = 0;
}
if (timer_ColdSnapTick > 0) {
    timer_ColdSnapTick -= globaltime;
} if (timer_ColdSnapTick <= 0) {
    timer_ColdSnapTick = 0;
}
