void setImagesToHotbar() {
    for (int i = 0; i < 9; i++) {
        if (hotbar_spells[i] == 1) { //Cold Snap
            SpellsHotbarSprites[i] = ColdSnapSprite;
        }
        else if (hotbar_spells[i] == 2) { //Cold Snap2
            SpellsHotbarSprites[i] = ColdSnap2Sprite;
        }
        else {
            SpellsHotbarSprites[i] = InventoryItemEmptySprite;
        }
    }
}

void setImagesToSpellsInventory() {
    for (int i = 0; i < 27; i++) {
        if (inv_spells[i] == 1) { //Cold Snap
            SpellsInventoryPageSprite[i] = ColdSnapSprite;
        }
        else if (inv_spells[i] == 2) { //Cold Snap2
            SpellsInventoryPageSprite[i] = ColdSnap2Sprite;
        }
        else {
            SpellsInventoryPageSprite[i] = InventoryItemEmptySprite;
        }
    }
}

void spells(float get_time) {
    if (spell_name == 1 && cooldowns[spell_slot] == 0) {
        int damage_from_spell = 2 * magic_ice;
        spellDamaged();
        for (int v = 0; v < damaged_numbers.size(); v++) {
            float mx = v_monsters[damaged_numbers[v]].getMonsterCoordinateX();
        	float my = v_monsters[damaged_numbers[v]].getMonsterCoordinateY();
            float condx = pow(pow((mx - player_x), 2), 0.5);
            float condy = pow(pow((my - player_y), 2), 0.5);
            if (condx <= 300 && condy <= 300) {
                v_monsters[damaged_numbers[v]].giveBuff("ColdSnap", 5000);
                v_monsters[damaged_numbers[v]].hitMonster(damage_from_spell, get_time);
                timer_ColdSnap_tick = 1000;
                cooldowns[spell_slot] = 15000;
        	}
        }
    }
}
