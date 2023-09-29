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
            for (int v = 0; v < game.entity_manager->v_monsters.size(); v++) {
                auto& monster = game.entity_manager->v_monsters[v];
                float mx = monster.getX();
                float my = monster.getY();
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
                        monster.giveBuff(2, 1500);
                        game.player->attack_stun = false;
                    }
                    if (game.player->space_hit) {
                        ah += game.player->damage * (3 - attack_type);
                        attack_cd = game.player->attack_speed * 3;
                    }
                    monster.hitMonster(game.player->damage + ah, game);
                    auto get_pos_x = monster.getX() + int(monster.getWidth() / 2);
                    auto get_pos_y = monster.getY() + 20;
                    auto dmg = std::to_string(game.player->damage + ah);
                    game.renderer->createDynamicText(game.renderer->font, 30, 500, dmg, get_pos_x, get_pos_y);
                }
            }
            if (game.player->combo_counter == 4 || game.player->combo_counter == old_combo_counter) {
                game.player->combo_counter = 0;
            }
            if (game.player->space_hit) {
                attack_cd = game.player->attack_speed * 3;
            }
            auto px = game.player->getX() - 20;
            auto py = game.player->getY();
            game.renderer->sprite_manager->AnimationWeaponSprite.setTextureRect(IntRect(0, 0, 1, 1));
            game.renderer->sprite_manager->AnimationWeaponSprite.setPosition(px, py);
            game.player->attack = 0;
            game.player->attack_animation = 1;
        }
    }
};
