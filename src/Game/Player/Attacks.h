class Attacks {
protected:
    void attacks(auto& time, auto& game) {
        attack1(time, game);
        attack2(time, game);
    }

    void attack1(auto& time, auto& game) {
        if (game.player->attack == 1 && game.player->attack1_cd == 0 && game.player->inv_items[27] != 0) {
            for (int v = 0; v < game.v_monsters.size(); v++) {
                float mx = game.v_monsters[v].getX();
                float my = game.v_monsters[v].getY();
                if (game.player->checkWeaponsRange(game, mx, my)) {
                    int random_crit = rand() % 100;
                    int ch = 0;
                    random_crit++;
                    if (random_crit <= game.player->critical_chance) {
                        ch = game.player->damage;
                    }
                    if (game.player->space_hit) {
                        game.v_monsters[v].hitMonster(game.player->damage * 3 + ch, time, game.player);
                        game.player->attack1_cd = game.player->attack_speed * 3;
                    } else {
                        game.v_monsters[v].hitMonster(game.player->damage + ch, time, game.player);
                        game.player->attack1_cd = game.player->attack_speed;
                    }
                }
            }
            game.AnimationWeaponSprite.setTextureRect(IntRect(0, 0, 1, 1));
            game.AnimationWeaponSprite.setPosition(game.player->getX() - 20, game.player->getY());
            game.player->attack1_cd = game.player->attack_speed;
            game.player->attack = 0;
            game.player->attack_animation = 1;
            game.player->defence_counter = 0;
        }
    }

    void attack2(auto& time, auto& game) {
        if (game.player->attack == 2 && game.player->attack2_cd == 0 && game.player->inv_items[27] != 0) {
            for (int v = 0; v < game.v_monsters.size(); v++) {
                float mx = game.v_monsters[v].getX();
                float my = game.v_monsters[v].getY();
                if (game.player->checkWeaponsRange(game, mx, my)) {
                    int random_crit = rand() % 100;
                    int ch = 0;
                    random_crit++;
                    if (random_crit <= game.player->critical_chance) {
                        ch = game.player->damage;
                    }
                    if (game.player->space_hit) {
                        game.v_monsters[v].hitMonster(game.player->damage * 2 + ch, time, game.player);
                        game.v_monsters[v].giveBuff("AttackStun", 500);
                        game.player->attack2_cd = game.player->attack_speed * 3;
                    } else {
                        game.v_monsters[v].hitMonster(game.player->damage * 2 + ch, time, game.player);
                        game.player->attack2_cd = game.player->attack_speed * 2;
                    }
                }
            }
            game.AnimationWeaponSprite.setTextureRect(IntRect(0, 0, 1, 1));
            game.AnimationWeaponSprite.setPosition(game.player->getX() - 20, game.player->getY());
            game.player->attack2_cd = game.player->attack_speed * 2;
            game.player->attack = 0;
            game.player->attack_animation = 1;
            game.player->defence_counter = 0;
        }
    }
};
