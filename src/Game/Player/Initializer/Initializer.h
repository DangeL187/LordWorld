class Initializer {
public: //TODO: ->protected
    //visuals:
    Sprite sprite;
    float current_frame = 0;
    //basic vars:
    int dir = 0;
    float dx, dy;
    float w, h, x, y;
    float speed = 0;
    //stats:
    int hp = 10, mp = 100, lvl = 1;
    int hp_max = 10, mp_max = 100, xp = 0;
    float hp_regen = 0.1, mp_regen = 0.1;
    //fight:
    int attack_animation = 0;
    int attack_speed = 1000;
    int attack_type = 0;
    int range = 1; //*64
    //NPC:
    int dialog_phase = 0;
    //inventory:
    Item inv_items[33]; //items inventory
    int inv_spells[24]; //spells inventory
    int hotbar_spells[9]; //spells hotbar
    int spell_id = 0;
    int spell_slot = 0;
    //cooldowns:
    int cooldowns[9] {0, 0, 0, 0, 0, 0, 0, 0, 0}; //spell cooldowns
    float attack1_cd = 0, attack2_cd = 0;
    float combo_counter = 0;
    float dash_cd = 0;
    float shield_cd = 0;
    //timers:
    float animation_timer = 0;
    float critical_timer = 0;
    float dash_timer = 0;
    float defence_timer = 0;
    float hold_attack_timer = 0;
    float show_cd_shield_timer = 0;
    float timer_hp_regen = 0;
    float timer_mp_regen = 0;
    //bools:
    bool is_aiming = false;
    bool is_attack_stun = false;
	bool is_defence = false;
    bool is_space_hit = false;
    bool is_dialog = false;
    bool is_inventory_open = false;
    bool is_inventory_spells_open = false;
    bool is_stats_open = false;
    //stats:
    int armor = 0;
	int armor_shield = 0;
	int armor_helmet = 0;
	int armor_chestplate = 0;
	int armor_pants = 0;
	int armor_boots = 0;
	int damage = 0;
	int strength = 1;
    int magic = 1;
    int critical_chance = 1; //%
    int magic_resistance = 1;
    int physical_resistance = 1;
    int magic_ice = 1;
    int magic_fire = 1;
    int magic_earth = 1;
    int magic_wind = 1;
    int magic_dark = 1;
    int magic_light = 1;
    int melee_weapon = 1; //*64
    int range_weapon = 1; //*64
	int weapon_type = 1; //1-circle attack; 2-straight; 3-conus; 4-vertical line;
    //keys:
    std::vector<bool> is_movement_keys {false, false, false, false};
    bool key_critical = false;
	bool key_event = false, key_drop_item = false;
	bool key_m1 = false, key_m2 = false;
	bool key_m1_go = false, key_m2_go = false;
	bool key_defence = false, key_defence_go = false;
	bool key_enter = false, key_enter_go = false;
protected:
    bool isOnlyOneIsTrue(std::vector<bool> v, std::vector<Keyboard::Key> keys, unsigned int id) {
        v.erase(v.begin() + id);
        if (!std::accumulate(v.begin(), v.end(), 0) && Keyboard::isKeyPressed(keys[id])) {
            return true;
        }
        return false;
    }

    void initialize() {
        NewSprite *new_player_sprite = new NewSprite("../images/hero.png"); //TODO: createSprite
        sprite = new_player_sprite->getSprite();
		sprite.setTextureRect(IntRect(1, 1, w, h));
        /*for (int i = 0; i < 33; i++) { //add zero items in inventory
            inv_items[i] = 0;
            if (i < 24) {
                inv_types[i] = 0;
            }
        }*/
        for (int i = 0; i < 24; i++) { //add zero items in spell inventory
            inv_spells[i] = 0;
        }
        for (int i = 0; i < 9; i++) { //add zero items in hotbar
            hotbar_spells[i] = 0;
        }
    }
};
