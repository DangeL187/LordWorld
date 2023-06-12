class Attacks {
protected:
    void attacks(auto& time, auto& game) {
        attack1(time, game);
        attack2(time, game);
    }

    void attack1(auto& time, auto& game) {
        if (game.player->attack == 1 && game.player->attack1_cd == 0 && game.player->inv_items[27] != 0) {
            bool is_monster_damaged = false;
            int old_combo_counter = game.player->combo_counter;
            for (int v = 0; v < game.v_monsters.size(); v++) {
                float mx = game.v_monsters[v].getX();
                float my = game.v_monsters[v].getY();
                if (game.player->checkWeaponsRange(game, mx, my)) {
                    int random_crit = rand() % 100;
                    int ah = 0; //additional hit
                    random_crit++;
                    if (!is_monster_damaged) {
                        game.player->combo_counter++;
                        is_monster_damaged = true;
                    }
                    if (game.player->combo_counter == 4) {
                        ah += game.player->damage;
                    }
                    if (random_crit <= game.player->critical_chance) {
                        ah += game.player->damage;
                    }
                    if (game.player->dash_timer > 0) {
                        ah += game.player->damage;
                    }
                    if (game.player->attack_stun) {
                      game.v_monsters[v].giveBuff("AttackStun", 1500);
                      game.player->attack_stun = false;
                    }
                    if (game.player->space_hit) {
                        game.v_monsters[v].hitMonster(game.player->damage * 3 + ah, time, game.player);
                        game.player->attack1_cd = game.player->attack_speed * 3;
                    } else {
                        game.v_monsters[v].hitMonster(game.player->damage + ah, time, game.player);
                        game.player->attack1_cd = game.player->attack_speed;
                    }
                }
            }
            if (game.player->combo_counter == 4 || game.player->combo_counter == old_combo_counter) {
                game.player->combo_counter = 0;
            }
            game.AnimationWeaponSprite.setTextureRect(IntRect(0, 0, 1, 1));
            game.AnimationWeaponSprite.setPosition(game.player->getX() - 20, game.player->getY());
            game.player->attack1_cd = game.player->attack_speed;
            game.player->attack = 0;
            game.player->attack_animation = 1;
        }
    }

    void attack2(auto& time, auto& game) {
        if (game.player->attack == 2 && game.player->attack2_cd == 0 && game.player->inv_items[27] != 0) {
            bool is_monster_damaged = false;
            for (int v = 0; v < game.v_monsters.size(); v++) {
                float mx = game.v_monsters[v].getX();
                float my = game.v_monsters[v].getY();
                if (game.player->checkWeaponsRange(game, mx, my)) {
                    int random_crit = rand() % 100;
                    int ah = 0; //additional hit
                    random_crit++;
                    if (!is_monster_damaged) {
                        game.player->combo_counter++;
                        is_monster_damaged = true;
                    }
                    if (game.player->combo_counter == 4) {
                        ah += game.player->damage;
                    }
                    if (random_crit <= game.player->critical_chance) {
                        ah += game.player->damage;
                    }
                    if (game.player->dash_timer > 0) {
                        ah += game.player->damage;
                    }
                    if (game.player->attack_stun) {
                      game.v_monsters[v].giveBuff("AttackStun", 1500);
                      game.player->attack_stun = false;
                    }
                    if (game.player->space_hit) {
                        game.v_monsters[v].hitMonster(game.player->damage * 3 + ah, time, game.player);
                        game.player->attack2_cd = game.player->attack_speed * 3;
                    } else {
                        game.v_monsters[v].hitMonster(game.player->damage * 2 + ah, time, game.player);
                        game.player->attack2_cd = game.player->attack_speed * 2;
                    }
                }
            }
            if (game.player->combo_counter == 4) {
                game.player->combo_counter = 0;
            }
            game.AnimationWeaponSprite.setTextureRect(IntRect(0, 0, 1, 1));
            game.AnimationWeaponSprite.setPosition(game.player->getX() - 20, game.player->getY());
            game.player->attack2_cd = game.player->attack_speed * 2;
            game.player->attack = 0;
            game.player->attack_animation = 1;
        }
    }
};
