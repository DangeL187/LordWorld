void setImages(auto& game, int size, auto& arr1, auto& arr2) {
    for (int i = 0; i < size; i++) {
        if (arr1[i] == 1) { //Cold Snap
            arr2[i] = game.ColdSnapSprite;
        }
        else if (arr1[i] == 2) { //Cold Snap2
            arr2[i] = game.ColdSnap2Sprite;
        }
        else {
            arr2[i] = game.InventoryItemEmptySprite;
        }
    }
}

void spells(auto& time, auto& game) {
    if (game.player->spell_name == 1 && game.player->cooldowns[game.player->spell_slot] == 0) {
        int damage_from_spell = 2 * game.player->magic_ice;
        game.spellDamaged(game);
        for (int v = 0; v < game.damaged_numbers.size(); v++) {
            float mx = game.v_monsters[game.damaged_numbers[v]].getX();
            float my = game.v_monsters[game.damaged_numbers[v]].getY();
            float condx = pow(pow((mx - game.player->p_cords[0]), 2), 0.5);
            float condy = pow(pow((my - game.player->p_cords[1]), 2), 0.5);
            if (condx <= 300 && condy <= 300) {
                std::cout << "FUCK " << damage_from_spell << "\n";
                game.v_monsters[game.damaged_numbers[v]].giveBuff("ColdSnap", 5000);
                game.v_monsters[game.damaged_numbers[v]].hitMonster(damage_from_spell, time, game.player);
                game.v_monsters[game.damaged_numbers[v]].timer_ColdSnap_tick = 1000;
                game.player->cooldowns[game.player->spell_slot] = 15000;
            }
        }
    }
    if (game.player->spell_name == 2 && game.player->cooldowns[game.player->spell_slot] == 0) {
        int damage_from_spell = 2 * game.player->magic_ice;
        game.spellDamaged(game);
        for (int v = 0; v < game.damaged_numbers.size(); v++) {
            float mx = game.v_monsters[game.damaged_numbers[v]].getX();
            float my = game.v_monsters[game.damaged_numbers[v]].getY();
            float condx = pow(pow((mx - game.player->p_cords[0]), 2), 0.5);
            float condy = pow(pow((my - game.player->p_cords[1]), 2), 0.5);
            if (condx <= 300 && condy <= 300) {
                std::cout << "FUCK " << damage_from_spell << "\n";
                game.v_monsters[game.damaged_numbers[v]].giveBuff("ColdSnap", 5000);
                game.v_monsters[game.damaged_numbers[v]].hitMonster(damage_from_spell, time, game.player);
                game.v_monsters[game.damaged_numbers[v]].timer_ColdSnap_tick = 1000;
                game.player->cooldowns[game.player->spell_slot] = 15000;
            }
        }
    }
}
