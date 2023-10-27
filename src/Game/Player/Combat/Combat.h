class Combat: virtual public Initializer {
private:
    bool checkWeaponsRange(float mx, float my) {
		switch (inv_items[27].getWeaponType()) {
            case 1: //Sword
                return (isInsideRectangle(x, y, mx-64, my-64, 128, 128));
                break;
        }
		return false;
	}
    void attack(auto& time, auto& game, auto& attack_cd, int type) {
        if (attack_type == type && attack_cd->isOver() && inv_items[27].getID() != 0) {
            attack_cd->run(attack_speed * attack_type);
            bool is_monster_damaged = false;
            int old_combo_counter = combo_counter;
            for (int v = 0; v < game.entity_manager->v_monsters.size(); v++) {
                auto& monster = game.entity_manager->v_monsters[v];
                float mx = monster.getX();
                float my = monster.getY();
                if (checkWeaponsRange(mx, my)) {
                    int random_crit = 1 + rand() % 100;
                    int ah = damage * (attack_type - 1); //additional hit
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
                    if (dash_timer->isRunning()) {
                        ah += damage;
                    }
                    if (is_attack_stun) {
                        monster.giveBuff(2, 1500);
                    }
                    if (is_space_hit) {
                        ah += damage * (3 - attack_type);
                    }
                    monster.hitMonster(damage + ah);
                    auto get_pos_x = mx + int(monster.getWidth() / 2);
                    auto get_pos_y = my + 20;
                    auto dmg = std::to_string(damage + ah);
                    game.renderer->interface_manager->interface_dynamic_text.createDynamicText(18, 500, dmg, get_pos_x, get_pos_y);
                }
            }
            if (combo_counter == 4 || combo_counter == old_combo_counter) {
                combo_counter = 0;
            }
            if (is_space_hit) {
                attack_cd->run(attack_speed * 3);
            }
            inv_items[27].getAnimationSprite().setTextureRect(IntRect(0, 0, 1, 1));
            inv_items[27].getAnimationSprite().setPosition(x - 20, y);
            attack_type = 0;
            attack_animation = 1;
            is_attack_stun = false;
        }
    }
protected:
    void combat(auto& time, auto& game) {
        attack(time, game, game.player->attack1_cd, 1);
        attack(time, game, game.player->attack2_cd, 2);
    }
};
