class Initializer {
public: //TODO: ->protected?
    //visuals:
    Sprite sprite;
    Sprite AnimationDashSprite;
    float current_frame = 0;
    //basic vars:
    int dir = 0;
    float dx, dy;
    float w, h, x, y;
    float basic_speed = 0.15;
    float speed = 0;
    //stats:
    int hp = 10, mp = 100, lvl = 1;
    int hp_max = 10, mp_max = 100, xp = 0;
    float hp_regen = 0.1, mp_regen = 0.1;
    //combat:
    int attack_animation = 0;
    int attack_speed = 1000;
    int attack_type = 0;
    int damage = 0;
    float combo_counter = 0;
    //NPC:
    int dialog_phase = 0;
    //inventory:
    Item inv_items[33]; //items inventory
    int inv_spells[24]; //spells inventory //TODO: remove
    std::vector<std::shared_ptr<Spell>> hotbar_spells; //spells hotbar
    int spell_id = 0;
    int spell_slot = 0;
    //cooldowns:
    std::vector<std::shared_ptr<Timer>> cooldowns; //spell cooldowns
    std::shared_ptr<Timer> attack1_cd, attack2_cd;
    std::shared_ptr<Timer> dash_cd;
    //timers:
    std::shared_ptr<Timer> animation_timer;
    std::shared_ptr<Timer> critical_timer;
    std::shared_ptr<Timer> dash_timer;
    std::shared_ptr<Timer> hold_attack_timer;
    std::shared_ptr<Timer> hp_regen_timer;
    std::shared_ptr<Timer> mp_regen_timer;
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
    int strength = 0;
    int agility = 0;
    int intelligence = 0;

    int armor = 0;
	int critical_chance = 1; //%
    int magic_resistance = 1;
    //magic:
    int magic = 1;
    int magic_dark = 1;
    int magic_earth = 1;
    int magic_fire = 1;
    int magic_ice = 1;
    int magic_light = 1;
    int magic_wind = 1;
    //keys:
    std::vector<bool> is_movement_keys {false, false, false, false};
    bool key_critical = false;
	bool key_event = false, key_drop_item = false;
	bool key_m1 = false, key_m2 = false;
	bool key_m1_go = false, key_m2_go = false;
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
        sprite = createSprite("hero.png");
		sprite.setTextureRect(IntRect(1, 1, w, h));
        AnimationDashSprite = createSprite("AnimationDash.png");

        attack1_cd = std::make_shared<Timer>();
        attack2_cd = std::make_shared<Timer>();
        dash_cd = std::make_shared<Timer>();
        animation_timer = std::make_shared<Timer>();
        critical_timer = std::make_shared<Timer>();
        dash_timer = std::make_shared<Timer>();
        hold_attack_timer = std::make_shared<Timer>();
        hp_regen_timer = std::make_shared<Timer>();
        mp_regen_timer = std::make_shared<Timer>();

        for (int i = 0; i < 9; i++) {
            cooldowns.push_back(std::make_shared<Timer>());
            hotbar_spells.push_back(std::make_shared<NullSpell>());
        }

        inv_items[27].getSprite() = createSprite("GuiSlotWeapon.png");
        inv_items[28].getSprite() = createSprite("GuiSlotShield.png");
        inv_items[29].getSprite() = createSprite("GuiSlotHelm.png");
        inv_items[30].getSprite() = createSprite("GuiSlotChest.png");
        inv_items[31].getSprite() = createSprite("GuiSlotPants.png");
        inv_items[32].getSprite() = createSprite("GuiSlotBoots.png");

        for (int i = 24; i <= 32; i++) {
            if (i < 27) {
                inv_items[i].getType() = 7;
            } else {
                inv_items[i].getType() = i - 26;
            }
        }
    }
};
