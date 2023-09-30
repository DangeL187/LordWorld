class TimeUpdater {
protected:
    float time;
    Clock clock;

    void updateTimers(auto& game) {
        if (game.player->space_timer > 0) {
            game.player->space_timer -= time;
            if (500 <= game.player->space_timer && game.player->space_timer <= 750) {
                game.player->space_hit = true;
            } else {
                game.player->space_hit = false;
            }
        } else {
            game.player->space_timer = 0;
        }

        if (game.player->timer_hp_regen > 0) {
            game.player->timer_hp_regen -= time;
        } else {
            game.player->timer_hp_regen = 1000 / game.player->hp_regen;
            if (game.player->hp < game.player->hp_max) {
                game.player->hp += 1;
            }
        }

        if (game.player->timer_mp_regen > 0) {
            game.player->timer_mp_regen -= time;
        } else {
            game.player->timer_mp_regen = 1000 / game.player->mp_regen;
            if (game.player->mp < game.player->mp_max) {
                game.player->mp += 1;
            }
        }

        if (Mouse::isButtonPressed(Mouse::Left) && game.player->attack_animation == 0) {
            game.player->hold_attack_timer += time;
            if (game.player->hold_attack_timer >= 1000) {
                game.player->attack_stun = true;
            }
        } else {
            game.player->hold_attack_timer = 0;
        }

        if (game.player->animation_timer > 0) {
            game.player->animation_timer -= time;
        } else {
            game.player->animation_timer = 150;
            if (game.player->attack_animation != 0 && game.player->attack_animation < 5) {
                game.player->attack_animation++;
            } else {
                game.player->attack_animation = 0;
            }
        }

        if (game.player->defence_timer > 0 && game.player->inv_items[28] != 0) {
            game.player->defence_timer -= time;
            game.player->defence = true;
        } else {
            game.player->defence_timer = 0;
            game.player->defence = false;
        }

        if (game.player->attack1_cd > 0) {
            game.player->attack1_cd -= time;
        } else {
            game.player->attack1_cd = 0;
        }

        if (game.player->attack2_cd > 0) {
            game.player->attack2_cd -= time;
        } else {
            game.player->attack2_cd = 0;
        }

        if (game.player->shield_cd > 0) {
            game.player->shield_cd -= time;
        } else {
            game.player->shield_cd = 0;
        }

        if (game.player->dash_cd > 0) {
            game.player->dash_cd -= time;
        } else {
            game.player->dash_cd = 0;
        }

        for (auto& i: game.player->cooldowns) {
            if (i > 0) {
                i -= time;
            } else {
                i = 0;
            }
        }
    }
};
