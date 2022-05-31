//stats:
int strength = 1;
int armor = 0;
int magic = 1;
float critical_chance = 1; //%
//resists:
float magic_resistance = 1; //%
float physical_resistance = 1; //%
//magic:
int magic_ice = 1;
int magic_fire = 1;
int magic_earth = 1;
int magic_wind = 1;
int magic_dark = 1;
int magic_light = 1;
//skills:
int melee_weapon = 1;
int range_weapon = 1;

float player_x = 0, player_y = 0;
int player_dir = 0;
int attack = 0;
int attack_animation = 0;
float range = 1; //*64
int armor_shield = 0;
int armor_helmet = 0;
int armor_chestplate = 0;
int armor_pants = 0;
int armor_boots = 0;
int sprite_counter = 0;
int attack1_cd = 0;
int attack2_cd = 0;
int spell_slot = 0;
int timer_ColdSnap;
int timer_ColdSnap_tick;
float timer_hp_regen = 10000, timer_mp_regen = 10000; //10000 is 0.1 per second
int player_hp = 10, player_mp = 10, player_lvl = 1;
int player_hp_max = 10, player_mp_max = 10 , player_xp = 0;
int player_damage = 1;
int defence_counter = 0;
int attack_speed = 1000; //1 second
int weapon_type = 1; //1-circle attack; 2-straight; 3-cone; 4-front-back line;
int spell_name = 0;
int target_number = -1;
int inv_items[33]; //items inventory //from [24] to [26] - other
//[27] - weapon, [28] - shield, [29] - helmet, [30] - chestplate, [31] - pants, [32] - boots
int inv_types[24]; //item types inventory
int inv_spells[300]; //spells inventory
int hotbar_spells[9]; //spells hotbar
int cooldowns[9] {0, 0, 0, 0, 0, 0, 0, 0, 0}; // cooldowns
float attack1_cd_timer = 0;
float attack2_cd_timer = 0;
float animation_timer = 0;
float move_monster_timer = 0;
float space_timer = 0;
float current_frame = 0;
float hp_regen = 0.1, mp_regen = 0.1;
bool defence = false;
bool space_hit = false;
bool aiming = false;
bool aiming_kid1 = false;
bool aiming_kid2 = false;
bool aiming_kid3 = false;
bool aiming_kid4 = false;
bool aiming_kid5 = false;
bool aiming_kid6 = false;
bool aiming_kid7 = false;
bool aiming_kid8 = false;
bool aiming_kid9 = false;
bool is_inventory_open = false;
bool is_spells_inventory_open = false;
bool is_stats_open = false;
bool is_dialog = false;
std::vector<int> items_dropped_id;
std::vector<int> items_dropped_x;
std::vector<int> items_dropped_y;
std::vector<int> items_dropped_sprites; //rename to sprite
std::vector<int> items_dropped_type; //0 - nothing, 1 - weapon, 2 - shield
//3 - helmet, 4 - chestplate, 5 - pants, 6 - boots, 7 - ring, 8.. - item