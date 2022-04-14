void spellCast() {

}

void spells(float get_time) {
    if (spell_name == "ColdSnap" and cooldowns[spell_slot] == 0) {
        int damage_from_spell = 2; //2 * lvl_ice_magic
        spellDamaged();
        for (int v = 0; v < damaged_numbers.size(); v++) {
            int out = player_x - (960 - Mouse::getPosition().x);
        	int outy = player_y - (570 - Mouse::getPosition().y);
            float condx = pow(pow((out - player_x), 2), 0.5);
            float condy = pow(pow((outy - player_y), 2), 0.5);
            if (condx <= 100 && condy <= 100) {
                v_monsters[damaged_numbers[v]].hitMonster(damage_from_spell, get_time);
                v_monsters[damaged_numbers[v]].giveBuff("ColdSnap", 5000);
                timer_ColdSnap_tick = 1000;
                cooldowns[spell_slot] = 15000;
            }
        }
    }
}
