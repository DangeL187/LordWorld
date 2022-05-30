void global_timers(auto time1) {
    if (space_timer > 0) {
        space_timer -= time1;
        if (750 >= space_timer && space_timer >= 500) {
            space_hit = true;
        } else {
            space_hit = false;
        }
    } else {
        space_timer = 0;
    }
    if (timer_hp_regen > 0) {
        timer_hp_regen -= time1;
    } else {
        timer_hp_regen = 1000 / hp_regen;
        if (player_hp < player_hp_max) {
            player_hp += 1;
        }
    }
    if (timer_mp_regen > 0) {
        timer_mp_regen -= time1;
    } else {
        timer_mp_regen = 1000 / mp_regen;
        if (player_mp < player_mp_max) {
            player_mp += 1;
        }
    }
    if (attack1_cd > 0) {
        attack1_cd -= time1;
    } else {
        attack1_cd = 0;
    }
    if (attack2_cd > 0) {
        attack2_cd -= time1;
    } else {
        attack2_cd = 0;
    }
    for (int i = 0; i <= 9; i++) {
        if (cooldowns[i] > 0) {
            cooldowns[i] -= time1;
        } else {
            cooldowns[i] = 0;
        }
    }
}
