void setImages(auto& game, int size, auto& arr1, auto& arr2) {
    for (int i = 0; i < size; i++) {
        if (arr1[i] == 1) { //Cold Snap
            arr2[i] = game.renderer->sprite_manager->ColdSnapSprite;
        }
        else if (arr1[i] == 2) { //Cold Snap2
            arr2[i] = game.renderer->sprite_manager->ColdSnap2Sprite;
        }
        else {
            arr2[i] = game.renderer->sprite_manager->InventoryItemEmptySprite;
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
            auto& monster = game.entity_manager->v_monsters[game.damaged_numbers[v]];
            float mx = monster.getX();
            float my = monster.getY();
            float condx = pow(pow((mx - game.player->getX()), 2), 0.5);
            float condy = pow(pow((my - game.player->getY()), 2), 0.5);
            if (condx <= 300 && condy <= 300 && game.player->mp >= mana_cost) {
                std::cout << "FUCK " << damage_from_spell << "\n";
                monster.giveBuff(game.player->spell_name, 5000);
                monster.hitMonster(damage_from_spell, game);
                break;
            }
        }
        if (game.damaged_numbers.size() > 0 && game.player->mp >= mana_cost) {
            game.player->cooldowns[game.player->spell_slot] = 15000;
            game.player->mp -= mana_cost;
        } else {
            game.renderer->sprite_manager->GuiNoManaSprites[game.player->spell_slot].setColor(sf::Color(0, 0, 0, 160));
            std::cout << "No mana!\n";
        }
    }
    if (game.player->spell_name == 2 && game.player->cooldowns[game.player->spell_slot] == 0) {
        int damage_from_spell;
        int mana_cost;
        defineSpell(game.player, game.player->spell_name, damage_from_spell, mana_cost);
        game.spellDamaged(game);
        for (int v = 0; v < game.damaged_numbers.size(); v++) {
            auto& monster = game.entity_manager->v_monsters[game.damaged_numbers[v]];
            float mx = monster.getX();
            float my = monster.getY();
            float condx = pow(pow((mx - game.player->getX()), 2), 0.5);
            float condy = pow(pow((my - game.player->getY()), 2), 0.5);
            if (condx <= 300 && condy <= 300 && game.player->mp >= mana_cost) {
                std::cout << "FUCK " << damage_from_spell << "\n";
                monster.giveBuff(game.player->spell_name-1, 5000);
                monster.hitMonster(damage_from_spell, game);
                break;
            }
        }
        if (game.damaged_numbers.size() > 0 && game.player->mp >= mana_cost) {
            game.player->cooldowns[game.player->spell_slot] = 15000;
            game.player->mp -= mana_cost;
        } else {
            game.renderer->sprite_manager->GuiNoManaSprites[game.player->spell_slot].setColor(sf::Color(0, 0, 0, 160));
            std::cout << "No mana!\n";
        }
    }
}
