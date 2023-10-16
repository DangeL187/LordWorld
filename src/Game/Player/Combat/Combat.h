class Combat: virtual public Initializer {
private:
    bool checkWeaponsRange(float mx, float my) {
		switch (weapon_type) {
            case 1: //Wooden Sword
				float condxm = mx/1 - melee_weapon*64;
	        	float condxp = mx/1 + melee_weapon*64;
		        float condyp = my/1 + melee_weapon*64;
				float condym = my/1 - melee_weapon*64;
	       		return (condxm <= x && x <= condxp && condym <= y && y <= condyp);
                break;
        }
		return false;
	}
    void attack(auto& time, auto& game, auto& attack_cd, int type) {
        if (attack_type == type && attack_cd == 0 && inv_items[27].getID() != 0) {
            attack_cd = attack_speed * attack_type;
            bool is_monster_damaged = false;
            int old_combo_counter = combo_counter;
            for (int v = 0; v < game.entity_manager->v_monsters.size(); v++) {
                auto& monster = game.entity_manager->v_monsters[v];
                float mx = monster.getX();
                float my = monster.getY();
                if (checkWeaponsRange(mx, my)) {
                    int random_crit = rand() % 100;
                    int ah = damage * (attack_type-1); //additional hit
                    random_crit++;
                    if (!is_monster_damaged) {
                        combo_counter++;
                        is_monster_damaged = true;
                    }
                    if (combo_counter == 4) {
                        ah += damage;
                    }
                    if (random_crit <= critical_chance) {
                        ah += damage;
                    }
                    if (dash_timer > 0) {
                        ah += damage;
                    }
                    if (is_attack_stun) {
                        monster.giveBuff(2, 1500);
                        is_attack_stun = false;
                    }
                    if (is_space_hit) {
                        ah += damage * (3 - attack_type);
                        attack_cd = attack_speed * 3;
                    }
                    monster.hitMonster(damage + ah, game);
                    auto get_pos_x = monster.getX() + int(monster.getWidth() / 2);
                    auto get_pos_y = monster.getY() + 20;
                    auto dmg = std::to_string(game.player->damage + ah);
                    game.renderer->text_manager->createDynamicText(game.renderer->text_manager->font, 30, 500, dmg, get_pos_x, get_pos_y);
                }
            }
            if (combo_counter == 4 || combo_counter == old_combo_counter) {
                combo_counter = 0;
            }
            if (is_space_hit) {
                attack_cd = attack_speed * 3;
            }
            game.renderer->sprite_manager->AnimationWeaponSprite.setTextureRect(IntRect(0, 0, 1, 1));
            game.renderer->sprite_manager->AnimationWeaponSprite.setPosition(x - 20, y);
            attack_type = 0;
            attack_animation = 1;
        }
    }
protected:
    void combat(auto& time, auto& game) {
        attack(time, game, game.player->attack1_cd, 1);
        attack(time, game, game.player->attack2_cd, 2);
    }
};
