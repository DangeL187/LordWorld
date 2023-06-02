class PlayerBase {
public:
    Sprite sprite;
    int attack = 0;
    int attack_animation = 0;
    int attack_speed = 1000;
	int dir = 0;
    int range = 1; //*64
	int inv_items[33]; //items inventory
	int inv_types[24]; //item types invenory
    int inv_spells[24]; //spells inventory
    int hotbar_spells[9]; //spells hotbar
    int cooldowns[9] {0, 0, 0, 0, 0, 0, 0, 0, 0}; //spell cooldowns
    int hp = 10, mp = 10, lvl = 1;
    int hp_max = 10, mp_max = 10, xp = 0;
    int spell_name = 0;
    int spell_slot = 0;
    int defence_counter = 0;
    float hp_regen = 0.1, mp_regen = 0.1;
    float p_cords[2] {300, 300};
    float w, h, dx, dy;
    float current_frame = 0;
    float speed = 0;
    float attack1_cd = 0, attack2_cd = 0;
    float animation_timer = 0;
    float dash_timer = 0;
    float dash_cd = 0;
    float space_timer = 0;
    float no_attack_timer = 0;
    float timer_hp_regen = 0;
    float timer_mp_regen = 0;
    bool aiming = false;
	bool defence = false;
    bool space_hit = false;
    bool is_inventory_open = false;
    bool is_spells_inventory_open = false;
    bool is_stats_open = false;
    bool is_dialog = false;
protected:
    void attacks(auto& time, auto& game) {  // move to its own class?
        if (attack == 1 && attack1_cd == 0 && inv_items[27] != 0) {
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
                    if (space_hit) {
                        game.v_monsters[v].hitMonster(game.player->damage * 3 + ch, time, game.player);
                        attack1_cd = attack_speed * 3;
                    } else {
                        game.v_monsters[v].hitMonster(game.player->damage + ch, time, game.player);
                        attack1_cd = attack_speed;
                    }
                }
            }
            game.AnimationWeaponSprite.setTextureRect(IntRect(0, 0, 1, 1));
            game.AnimationWeaponSprite.setPosition(p_cords[0] - 20, p_cords[1]);
            attack1_cd = attack_speed;
            attack = 0;
            attack_animation = 1;
            defence_counter = 0;
        }
        if (attack == 2 && attack2_cd == 0 && inv_items[27] != 0) {
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
                    if (space_hit) {
                        game.v_monsters[v].hitMonster(game.player->damage * 2 + ch, time, game.player);
                        game.v_monsters[v].giveBuff("AttackStun", 500);
                        attack2_cd = attack_speed * 3;
                    } else {
                        game.v_monsters[v].hitMonster(game.player->damage * 2 + ch, time, game.player);
                        attack2_cd = attack_speed * 2;
                    }
                }
            }
            game.AnimationWeaponSprite.setTextureRect(IntRect(0, 0, 1, 1));
            game.AnimationWeaponSprite.setPosition(p_cords[0] - 20, p_cords[1]);
            attack2_cd = attack_speed * 2;
            attack = 0;
            attack_animation = 1;
            defence_counter = 0;
        }
    }
    void animations(auto& time, auto& game) {  // move to its own class
        if (animation_timer > 0) {
            animation_timer -= time;
        } else {
            animation_timer = 150;
            if (attack_animation != 0 && attack_animation < 5) {
                attack_animation++;
            } else {
                game.AnimationWeaponSprite.setTextureRect(IntRect(0, 0, 1, 1));
                game.AnimationWeaponSprite.setPosition(p_cords[0] - 20, p_cords[1]);
                attack_animation = 0;
            }
        }
        if (attack_animation == 5) {
            auto cf = int(current_frame); if (cf == 3) { cf = 1; }
			sprite.setTextureRect(IntRect(w * cf + cf + 1, h * dir + dir + 1, w, h)); //w, h - width, height

            game.AnimationWeaponSprite.setTextureRect(IntRect(0, 0, 1, 1));
            game.AnimationWeaponSprite.setPosition(p_cords[0] - 20, p_cords[1]);
            attack_animation = 0;
        }
        if (attack_animation != 0 && attack_animation != 5)  {
            int n = ((attack_animation % 2)-1) * ((attack_animation % 2)-1) + 3;
            sprite.setTextureRect(IntRect(w * n + n + 1, h * dir + dir + 1, w, h));
            game.AnimationWeaponSprite.setTextureRect(IntRect(80 * (attack_animation - 1) + attack_animation, 76 * dir + dir + 1, 80, 76)); //80, 76 - width, height
            game.AnimationWeaponSprite.setPosition(p_cords[0] - 16, p_cords[1] - 4);
        }

        int n = dir / 2 * (dir - 1);
        game.AnimationShieldSprite.setTextureRect(IntRect(47 * n + n + 1, 1, 47, 28));
        game.AnimationShieldSprite.setPosition(p_cords[0], p_cords[1] + 30);

        if (dash_timer > 0) {
            sprite.setTextureRect(IntRect(w * 5 + 6, h * dir + dir + 1, w, h));
            game.AnimationDashSprite.setTextureRect(IntRect(94 * dir + dir + 1, 1, 94, 108));
            game.AnimationDashSprite.setPosition(p_cords[0] - 26, p_cords[1] - 22);
        }
    }
};
