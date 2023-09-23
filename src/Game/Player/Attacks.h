class Attacks {
protected:
    void attacks(auto& time, auto& game) {
        attack(time, game, game.player->attack1_cd, 1);
        attack(time, game, game.player->attack2_cd, 2);
    }

    void attack(auto& time, auto& game, auto& attack_cd, int attack_type) {
        if (game.player->attack == attack_type && attack_cd == 0 && game.player->inv_items[27] != 0) {
            attack_cd = game.player->attack_speed * attack_type;
            bool is_monster_damaged = false;
            int old_combo_counter = game.player->combo_counter;
            for (int v = 0; v < game.v_monsters.size(); v++) {
                float mx = game.v_monsters[v].getX();
                float my = game.v_monsters[v].getY();
                if (game.player->checkWeaponsRange(game, mx, my)) {
                    int random_crit = rand() % 100;
                    int ah = game.player->damage * (attack_type-1); //additional hit
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
                        ah += game.player->damage * (3 - attack_type);
                        attack_cd = game.player->attack_speed * 3;
                    }
                    game.v_monsters[v].hitMonster(game.player->damage + ah, time, game.player);
                    auto get_pos_x = game.v_monsters[v].getX() + int(game.v_monsters[v].getWidth() / 2);
                    auto get_pos_y = game.v_monsters[v].getY() + 20;
                    game.renderer->createDynamicText(game.renderer->font, 30, 500, std::to_string(game.player->damage + ah), get_pos_x, get_pos_y);
                }
            }
            if (game.player->combo_counter == 4 || game.player->combo_counter == old_combo_counter) {
                game.player->combo_counter = 0;
            }
            if (game.player->space_hit) {
                attack_cd = game.player->attack_speed * 3;
            }
            game.renderer->AnimationWeaponSprite.setTextureRect(IntRect(0, 0, 1, 1));
            game.renderer->AnimationWeaponSprite.setPosition(game.player->getX() - 20, game.player->getY());
            game.player->attack = 0;
            game.player->attack_animation = 1;
        }
    }
};
