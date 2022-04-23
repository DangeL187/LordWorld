void spells(float get_time) {
    if (spell_name == "ColdSnap" && cooldowns[spell_slot] == 0) {
        int damage_from_spell = 2; //2 * lvl_ice_magic
        spellDamaged();
        for (int v = 0; v < damaged_numbers.size(); v++) {
            float mx = v_monsters[damaged_numbers[v]].getMonsterCoordinateX();
        	float my = v_monsters[damaged_numbers[v]].getMonsterCoordinateY();
            float condx = pow(pow((mx - player_x), 2), 0.5);
            float condy = pow(pow((my - player_y), 2), 0.5);
            if (condx <= 100 && condy <= 100) {
                v_monsters[damaged_numbers[v]].hitMonster(damage_from_spell, get_time);
                v_monsters[damaged_numbers[v]].giveBuff("ColdSnap", 5000);
                timer_ColdSnap_tick = 1000;
                cooldowns[spell_slot] = 15000;
        	}
        }
    }
}
