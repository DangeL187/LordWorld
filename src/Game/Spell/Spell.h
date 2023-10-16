class Spell {
protected:
    int buff_duration = 0;
    int cooldown = 0;
    int damage_from_spell = 0;
    int mana_cost = 0;
    float aoe_range = 0;
    float cast_range = 0;
    
public:
    int getManacost() {
        return mana_cost;
    }
};
