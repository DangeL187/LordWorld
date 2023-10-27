class Casting: virtual public Initializer {
protected:
    void castSpell(std::vector<Monster>& monsters) {
        if (cooldowns[spell_slot]->isOver()) {
            hotbar_spells[spell_slot]->cast(monsters, mp, x, y, w, h, cooldowns[spell_slot]);
        }
    }
};
