void attacks(float time0) {
    // attack 1
    if (attack == 1 && attack1_cd == 0) {
        for (auto& monster : v_monsters)
        {
            float mx = monster.getMonsterCoordinateX();
            float my = monster.getMonsterCoordinateY();
            if (checkWeaponsRange(mx, my)) {
                auto random_crit = rand() % 100;
                int ch = 0;
                random_crit++;
                if (random_crit <= critical_chance)
                {
                    ch = player_damage;
                }

                if (space_hit) {
                    monster.hitMonster(player_damage * 3 + ch, time0);
                    attack1_cd = attack_speed * 3;
                }
                else {
                    monster.hitMonster(player_damage + ch, time0);
                    attack1_cd = attack_speed;
                }
            }
        }

        AnimationWoodenSwordSprite.setTextureRect(IntRect(0, 0, 1, 1));
        AnimationWoodenSwordSprite.setPosition(player_x - 20, player_y);
        attack1_cd = attack_speed;
        attack = 0;
        attack_animation = 1;
        defence_counter = 0;
    }

    // attack 2
    if (attack == 2 && attack2_cd == 0) {
        for (auto& monster : v_monsters)
        {
            float mx = monster.getMonsterCoordinateX();
            float my = monster.getMonsterCoordinateY();
            if (checkWeaponsRange(mx, my)) {
                auto random_crit = rand() % 100;
                int ch = 0;
                random_crit++;
                if (random_crit <= critical_chance) {
                    ch = player_damage;
                }
                if (space_hit) {
                    monster.hitMonster(player_damage * 2 + ch, time0);
                    monster.giveBuff("AttackStun", 500);
                    attack2_cd = attack_speed * 3;
                } else {
                    monster.hitMonster(player_damage * 2 + ch, time0);
                    attack2_cd = attack_speed * 2;
                }
            }
        }

        AnimationWoodenSwordSprite.setTextureRect(IntRect(0, 0, 1, 1));
        AnimationWoodenSwordSprite.setPosition(player_x - 20, player_y);
        attack2_cd = attack_speed * 2;
        attack = 0;
        attack_animation = 1;
        defence_counter = 0;
    }
}
