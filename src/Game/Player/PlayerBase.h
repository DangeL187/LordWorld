class PlayerBase: public Attacks, public Animations {
public:
    //visuals:
    Sprite sprite;
    float current_frame = 0;
    //basic vars:
    int dir = 0;
    float w, h, dx, dy;
    float x = 300;
    float y = 300;
    float speed = 0;
    //stats:
    int hp = 10, mp = 10, lvl = 1;
    int hp_max = 10, mp_max = 10, xp = 0;
    float hp_regen = 0.1, mp_regen = 0.1;
    //fight:
    int attack = 0;
    int attack_animation = 0;
    int attack_speed = 1000;
    int range = 1; //*64
    //inventory:
    int inv_items[33]; //items inventory
	  int inv_types[24]; //item types invenory
    int inv_spells[24]; //spells inventory
    int hotbar_spells[9]; //spells hotbar
    int spell_name = 0;
    int spell_slot = 0;
    //cooldowns:
    int cooldowns[9] {0, 0, 0, 0, 0, 0, 0, 0, 0}; //spell cooldowns
    float attack1_cd = 0, attack2_cd = 0;
    float combo_counter = 0;
    float dash_cd = 0;
    float shield_cd = 0;
    //timers:
    float animation_timer = 0;
    float dash_timer = 0;
    float defence_timer = 0;
    float hold_attack_timer = 0;
    float space_timer = 0;
    float timer_hp_regen = 0;
    float timer_mp_regen = 0;
    //bools:
    bool aiming = false;
    bool attack_stun = false;
	  bool defence = false;
    bool space_hit = false;
    bool is_dialog = false;
    bool is_inventory_open = false;
    bool is_spells_inventory_open = false;
    bool is_stats_open = false;
};
