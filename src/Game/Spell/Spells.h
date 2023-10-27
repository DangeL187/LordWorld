class ColdSnap: public Spell {
public:
    ColdSnap(std::shared_ptr<Player>& player):
    Spell(1) {
        buff_duration = 5000;
        cooldown = 15000;
        damage_from_spell = 2 * player->magic_ice;
        mana_cost = 5;
        aoe_range = 64; //area of effect
        cast_range = 300;
        name = "ColdSnap";
        sprite = createSprite("ColdSnap.png");
        createDescription("If the enemy takes damage, he will get bonus damage", "The unknown power of cold");
    }

    void cast(std::vector<Monster>& monsters, int& mp, float px, float py, float pw, float ph, std::shared_ptr<Timer>& cooldown_timer) override {
        float mouse_x = px - (962 - Mouse::getPosition().x);
        float mouse_y = py - (544 - Mouse::getPosition().y);
        float player_center_x = px + pw / 2;
        float player_center_y = py + ph / 2;
        if (mp >= mana_cost && getDistanceBetween(mouse_x, mouse_y, player_center_x, player_center_y) <= cast_range) {
            for (auto& monster: monsters) {
                float monster_x = monster.getX();
                float monster_y = monster.getY();
                float monster_center_x = monster_x + monster.getWidth() / 2;
                float monster_center_y = monster_y + monster.getHeight() / 2;
                if (getDistanceBetween(mouse_x, mouse_y, monster_center_x, monster_center_y) <= aoe_range) {
                    //std::cout << "FUCK " << damage_from_spell << "\n";
                    monster.giveBuff(1, buff_duration);
                    monster.hitMonster(damage_from_spell);
                    cooldown_timer->run(cooldown);
                    mp -= mana_cost;
                    break;
                }
            }
        }
    }
};

class ColdSnap2: public Spell {
public:
    ColdSnap2(std::shared_ptr<Player>& player):
    Spell(2) {
        buff_duration = 5000;
        cooldown = 15000;
        damage_from_spell = 3 * player->magic_ice;
        mana_cost = 4;
        aoe_range = 64; //area of effect
        cast_range = 100;
        name = "ColdSnap2";
        sprite = createSprite("ColdSnap2.png");
        createDescription("If the enemy takes damage, he will get bonus damage", "The unknown power of cold");
    }

    void cast(std::vector<Monster>& monsters, int& mp, float px, float py, float pw, float ph, std::shared_ptr<Timer>& cooldown_timer) override {
        float mouse_x = px - (962 - Mouse::getPosition().x);
        float mouse_y = py - (544 - Mouse::getPosition().y);
        float player_center_x = px + pw / 2;
        float player_center_y = py + ph / 2;
        if (mp >= mana_cost && getDistanceBetween(mouse_x, mouse_y, player_center_x, player_center_y) <= cast_range) {
            for (auto& monster: monsters) {
                float monster_x = monster.getX();
                float monster_y = monster.getY();
                float monster_center_x = monster_x + monster.getWidth() / 2;
                float monster_center_y = monster_y + monster.getHeight() / 2;
                if (getDistanceBetween(mouse_x, mouse_y, monster_center_x, monster_center_y) <= aoe_range) {
                    //std::cout << "FUCK2 " << damage_from_spell << "\n";
                    monster.giveBuff(1, buff_duration);
                    monster.hitMonster(damage_from_spell);
                    cooldown_timer->run(cooldown);
                    mp -= mana_cost;
                    break;
                }
            }
        }
    }
};
