class SpriteUpdater {
protected:
    void updateSprites(auto& game) {
        auto& sprite_manager = game.renderer->sprite_manager;
        float view_x = game.window_manager->viewGetCenterX();
        float view_y = game.window_manager->viewGetCenterY();
        sprite_manager->gui_sprites[0].setPosition(view_x - 960, view_y - 540);
        sprite_manager->gui_sprites[1].setPosition(view_x - 300, view_y - 400);
        sprite_manager->gui_sprites[2].setPosition(view_x - 300, view_y - 496);
        sprite_manager->gui_sprites[3].setPosition(view_x - 540, view_y + 380);
        sprite_manager->gui_sprites[4].setPosition(view_x - 920, view_y - 310);
        sprite_manager->gui_sprites[5].setPosition(view_x - 540, view_y + 80);

        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 4; j++) {
                float condix1 = view_x + 261 - 15 + 112 * j;
                float condiy1 = view_y - 343 - 15 + 112 * i;
                float condix2 = view_x + 231 + 112 * j;
                float condiy2 = view_y - 373 + 112 * i;
                sprite_manager->InventoryItemsSprite[i * 4 + j].setPosition(condix1, condiy1);
                sprite_manager->SpellsInventorySprite[i * 4 + j].setPosition(condix2+5, condiy2);
            }
        }

        for (int i = 0; i < 9; i++) {
            int damage_from_spell;
            int mana_cost;
            sprite_manager->SpellsHotbarSprites[i].setPosition(view_x - 536 + 112 * i, view_y + 384);
            sprite_manager->GuiNoManaSprites[i].setPosition(view_x - 536 + 112 * i, view_y + 384);
            defineSpell(game.player, game.player->hotbar_spells[i], damage_from_spell, mana_cost);
            if (game.player->hotbar_spells[i] != 0 && (game.player->cooldowns[i] != 0 || game.player->mp < mana_cost)) {
                sprite_manager->GuiNoManaSprites[i].setColor(sf::Color(0, 0, 0, 160));
            } else {
                sprite_manager->GuiNoManaSprites[i].setColor(sf::Color(0, 0, 0, 0));
            }
        }
        if (game.player->aiming) {
            int id = game.player->spell_slot;
            sprite_manager->GuiPickedSpellSprite.setPosition(view_x - 536 + 112 * id, view_y + 384);
        }

        if (game.player->inv_items[27] != 0) {
            sprite_manager->GuiEquipmentSprites[0].setPosition(view_x - 231 - 15, view_y - 227 - 15);
        } else {
            sprite_manager->GuiEquipmentSprites[0].setPosition(view_x - 231 - 29, view_y - 227 - 29);
        }
        if (game.player->inv_items[28] != 0) {
            sprite_manager->GuiEquipmentSprites[1].setPosition(view_x + 89 - 15, view_y - 227 - 15);
        } else {
            sprite_manager->GuiEquipmentSprites[1].setPosition(view_x + 89 - 29, view_y - 227 - 29);
        }
        if (game.player->inv_items[29] != 0) {
            sprite_manager->GuiEquipmentSprites[2].setPosition(view_x - 71 - 15, view_y - 351 - 15);
        } else {
            sprite_manager->GuiEquipmentSprites[2].setPosition(view_x - 71 - 29, view_y - 351 - 29);
        }
        if (game.player->inv_items[30] != 0) {
            sprite_manager->GuiEquipmentSprites[3].setPosition(view_x - 71 - 15, view_y - 227 - 15);
        } else {
            sprite_manager->GuiEquipmentSprites[3].setPosition(view_x - 71 - 29, view_y - 227 - 29);
        }
        if (game.player->inv_items[31] != 0) {
            sprite_manager->GuiEquipmentSprites[4].setPosition(view_x - 71 - 15, view_y - 103 - 15);
        } else {
            sprite_manager->GuiEquipmentSprites[4].setPosition(view_x - 71 - 29, view_y - 103 - 29);
        }
        if (game.player->inv_items[32] != 0) {
            sprite_manager->GuiEquipmentSprites[5].setPosition(view_x - 71 - 15, view_y + 21 - 15);
        } else {
            sprite_manager->GuiEquipmentSprites[5].setPosition(view_x - 71 - 29, view_y + 21 - 29);
        }
        sprite_manager->InventoryItemsSprite[24].setPosition(view_x - 203 - 15, view_y + 185 - 15);
        sprite_manager->InventoryItemsSprite[25].setPosition(view_x - 71 - 15, view_y + 185 - 15);
        sprite_manager->InventoryItemsSprite[26].setPosition(view_x + 61 - 15, view_y + 185 - 15);

        sprite_manager->GuiIndicatorSprite.setPosition(game.player->getX()+18, game.player->getY()-34);
    }
};
