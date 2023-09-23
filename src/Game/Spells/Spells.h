void setImages(auto& game, int size, auto& arr1, auto& arr2) {
    for (int i = 0; i < size; i++) {
        if (arr1[i] == 1) { //Cold Snap
            arr2[i] = game.renderer->ColdSnapSprite;
        }
        else if (arr1[i] == 2) { //Cold Snap2
            arr2[i] = game.renderer->ColdSnap2Sprite;
        }
        else {
            arr2[i] = game.renderer->InventoryItemEmptySprite;
        }
    }
}

void defineSpell(auto& player, auto& spell_name, auto& get_damage, auto& get_mana) {
    switch (spell_name) {
        case 1:
            get_damage = 2 * player->magic_ice;
            get_mana = 5;
            break;
        case 2:
            get_damage = 2 * player->magic_ice;
            get_mana = 5;
            break;
    }
}

void spells(auto& time, auto& game) {
    if (game.player->spell_name == 1 && game.player->cooldowns[game.player->spell_slot] == 0) {
        int damage_from_spell;
        int mana_cost;
        defineSpell(game.player, game.player->spell_name, damage_from_spell, mana_cost);
        game.spellDamaged(game);
        for (int v = 0; v < game.damaged_numbers.size(); v++) {
            float mx = game.v_monsters[game.damaged_numbers[v]].getX();
            float my = game.v_monsters[game.damaged_numbers[v]].getY();
            float condx = pow(pow((mx - game.player->getX()), 2), 0.5);
            float condy = pow(pow((my - game.player->getY()), 2), 0.5);
            if (condx <= 300 && condy <= 300 && game.player->mp >= mana_cost) {
                std::cout << "FUCK " << damage_from_spell << "\n";
                game.v_monsters[game.damaged_numbers[v]].giveBuff("ColdSnap", 5000);
                game.v_monsters[game.damaged_numbers[v]].hitMonster(damage_from_spell, time, game.player);
                game.v_monsters[game.damaged_numbers[v]].timer_ColdSnap_tick = 1000;
                break;
            }
        }
        if (game.damaged_numbers.size() > 0 && game.player->mp >= mana_cost) {
            game.player->cooldowns[game.player->spell_slot] = 15000;
            game.player->mp -= mana_cost;
        } else {
            game.renderer->GuiNoManaSprites[game.player->spell_slot].setColor(sf::Color(0, 0, 0, 160));
            std::cout << "No mana!\n";
        }
    }
    if (game.player->spell_name == 2 && game.player->cooldowns[game.player->spell_slot] == 0) {
        int damage_from_spell = 2 * game.player->magic_ice;
        int mana_cost = 5;
        game.spellDamaged(game);
        for (int v = 0; v < game.damaged_numbers.size(); v++) {
            float mx = game.v_monsters[game.damaged_numbers[v]].getX();
            float my = game.v_monsters[game.damaged_numbers[v]].getY();
            float condx = pow(pow((mx - game.player->getX()), 2), 0.5);
            float condy = pow(pow((my - game.player->getY()), 2), 0.5);
            if (condx <= 300 && condy <= 300 && game.player->mp >= mana_cost) {
                std::cout << "FUCK " << damage_from_spell << "\n";
                game.v_monsters[game.damaged_numbers[v]].giveBuff("ColdSnap", 5000);
                game.v_monsters[game.damaged_numbers[v]].hitMonster(damage_from_spell, time, game.player);
                game.v_monsters[game.damaged_numbers[v]].timer_ColdSnap_tick = 1000;
                break;
            }
        }
        if (game.damaged_numbers.size() > 0 && game.player->mp >= mana_cost) {
            game.player->cooldowns[game.player->spell_slot] = 15000;
            game.player->mp -= mana_cost;
        } else {
            std::cout << "No mana!\n";
        }
    }
}
