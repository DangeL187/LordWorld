class MonsterBase {
public:
    int timer_ColdSnap_tick = 0;
protected:
    float x, y;
	float w, h, dx, dy, speed;
    int dmg, hp, mp, lvl, as, xp;
	int dir = 0;
	int random_generated_dir = 0;
	float as_cd;
	float monster_frame;
    float move_monster_timer = 0;
	int static_sprite;
	std::string name;
	std::vector<std::string> buffs;
    std::vector<int> drop;
	std::vector<int> drop_chance;
	std::vector<int> timers; //spells timers
	Image image;
	Texture texture;
	Sprite sprite;
	bool dealt = false;
	bool stun = false;

    void defineMonster(std::string name, auto& monster_sprites_, auto& sprite) {
        if (name == "Rat") {
            dmg = 2;
            hp = 10;
            mp = 10;
            lvl = 1;
            as = 1000;
            xp = 5;
            drop.push_back(8);
            drop_chance.push_back(50);
            sprite = monster_sprites_[0]; //Rat
            //replace this shit with returning array [sprite, int]
		}
        else if (name == "Rat2") {
            dmg = 2;
            hp = 10;
            mp = 10;
            lvl = 1;
            as = 1000;
            xp = 5;
            drop.push_back(8);
            drop_chance.push_back(50);
            sprite = monster_sprites_[1]; //Rat
            //replace this shit with returning array [sprite, int]
		}
    }

    void defineBuff(auto& v, auto& player) {
        if (buffs[v] == "ColdSnap") {
            if (timer_ColdSnap_tick == 0 && dealt) { //replace with some global counter
                hp -= 1 * player->magic_ice;
                timer_ColdSnap_tick = 1000;
            }
            if (timers[v] <= 0) {
                timer_ColdSnap_tick = 0;
            }
        }
        if (buffs[v] == "AttackStun") {
            stun = true;
        }
    }

    void buffTimers(auto& v, auto& time) {
        if (timers[v] > 0) {
            timers[v] -= time;
        } else {
            timers[v] = 0;
        }
        if (timer_ColdSnap_tick > 0) {
            timer_ColdSnap_tick -= time;
        } else {
            timer_ColdSnap_tick = 0;
        }
    }
};
