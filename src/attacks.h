void attacks(auto time0) {
    if (attack == 1 && attack1_cd == 0) {
        for (int v = 0; v < v_monsters.size(); v++) {
            float mx = v_monsters[v].getMonsterCoordinateX();
        	float my = v_monsters[v].getMonsterCoordinateY();
            if (checkWeaponsRange(mx, my)) {
                int random_crit = rand() % 100;
                int ch = 0;
                random_crit++;
                if (random_crit <= critical_chance) {
                    ch = player_damage;
                }
                if (space_hit) {
                    v_monsters[v].hitMonster(player_damage * 3 + ch, time0);
                    attack1_cd = attack_speed * 3;
                } else {
                    v_monsters[v].hitMonster(player_damage + ch, time0);
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
    if (attack == 2 && attack2_cd == 0) {
        for (int v = 0; v < v_monsters.size(); v++) {
            float mx = v_monsters[v].getMonsterCoordinateX();
    		float my = v_monsters[v].getMonsterCoordinateY();
            if (checkWeaponsRange(mx, my)) {
                int random_crit = rand() % 100;
                int ch = 0;
                random_crit++;
                if (random_crit <= critical_chance) {
                    ch = player_damage;
                }
                    if (space_hit) {
                    v_monsters[v].hitMonster(player_damage * 2 + ch, time0);
                    v_monsters[v].giveBuff("AttackStun", 500);
                    attack2_cd = attack_speed * 3;
                } else {
                    v_monsters[v].hitMonster(player_damage * 2 + ch, time0);
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
