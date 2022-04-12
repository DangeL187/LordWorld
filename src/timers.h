if (timers[v] > 0) {
    timers[v] -= globaltime;
} if (timers[v] <= 0) {
    timers[v] = 0;
}
if (timer_ColdSnap_tick > 0) {
    timer_ColdSnap_tick -= globaltime;
} if (timer_ColdSnap_tick <= 0) {
    timer_ColdSnap_tick = 0;
}
