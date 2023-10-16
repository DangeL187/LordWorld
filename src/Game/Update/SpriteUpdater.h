class SpriteUpdater {
protected:
    void updateSprites(auto& game) {
        auto& sprite_manager = game.renderer->sprite_manager;
        float view_x = game.window_manager->viewGetCenterX();
        float view_y = game.window_manager->viewGetCenterY();
        sprite_manager->GuiBarSprite.setPosition(view_x - 960, view_y - 540);
        sprite_manager->GuiInventorySprite.setPosition(view_x - 300, view_y - 400);
        sprite_manager->GuiInventorySpellsSprite.setPosition(view_x - 300, view_y - 496);
        sprite_manager->GuiHotbarSprite.setPosition(view_x - 540, view_y + 380);
        sprite_manager->GuiStatsSprite.setPosition(view_x - 920, view_y - 310);
        sprite_manager->NPCTalkSprite.setPosition(view_x - 540, view_y + 80);

        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 4; j++) {
                float condix1 = view_x + 261 - 15 + 112 * j;
                float condiy1 = view_y - 343 - 15 + 112 * i;
                float condix2 = view_x + 231 + 112 * j;
                float condiy2 = view_y - 373 + 112 * i;
                sprite_manager->InventoryItemsSprites[i * 4 + j].setPosition(condix1, condiy1);
                sprite_manager->InventorySpellsSprites[i * 4 + j].setPosition(condix2+5, condiy2);
            }
        }

        for (int i = 0; i < 9; i++) {
            sprite_manager->HotbarSprites[i] = sprite_manager->loadSpellSprite(game.player->hotbar_spells[i]);
            sprite_manager->HotbarSprites[i].setPosition(view_x - 536 + 112 * i, view_y + 384);
            sprite_manager->GuiNoManaSprites[i].setPosition(view_x - 536 + 112 * i, view_y + 384);
            int mana_cost = game.spell_manager->getSpellManacost(game);
            if (game.player->hotbar_spells[i] != 0 && (game.player->cooldowns[i] != 0 || game.player->mp < mana_cost)) {
                sprite_manager->GuiNoManaSprites[i].setColor(sf::Color(0, 0, 0, 160));
            } else {
                sprite_manager->GuiNoManaSprites[i].setColor(sf::Color(0, 0, 0, 0));
            }
        }
        if (game.player->is_aiming) {
            int id = game.player->spell_slot;
            sprite_manager->GuiPickedSpellSprite.setPosition(view_x - 536 + 112 * id, view_y + 384);
        }

        if (game.player->inv_items[27].getID() != 0) {
            sprite_manager->GuiSlotWeaponSprite.setPosition(view_x - 231 - 15, view_y - 227 - 15);
        } else {
            sprite_manager->GuiSlotWeaponSprite.setPosition(view_x - 231 - 29, view_y - 227 - 29);
        }
        if (game.player->inv_items[28].getID() != 0) {
            sprite_manager->GuiSlotShieldSprite.setPosition(view_x + 89 - 15, view_y - 227 - 15);
        } else {
            sprite_manager->GuiSlotShieldSprite.setPosition(view_x + 89 - 29, view_y - 227 - 29);
        }
        if (game.player->inv_items[29].getID() != 0) {
            sprite_manager->GuiSlotHelmSprite.setPosition(view_x - 71 - 15, view_y - 351 - 15);
        } else {
            sprite_manager->GuiSlotHelmSprite.setPosition(view_x - 71 - 29, view_y - 351 - 29);
        }
        if (game.player->inv_items[30].getID() != 0) {
            sprite_manager->GuiSlotChestSprite.setPosition(view_x - 71 - 15, view_y - 227 - 15);
        } else {
            sprite_manager->GuiSlotChestSprite.setPosition(view_x - 71 - 29, view_y - 227 - 29);
        }
        if (game.player->inv_items[31].getID() != 0) {
            sprite_manager->GuiSlotPantsSprite.setPosition(view_x - 71 - 15, view_y - 103 - 15);
        } else {
            sprite_manager->GuiSlotPantsSprite.setPosition(view_x - 71 - 29, view_y - 103 - 29);
        }
        if (game.player->inv_items[32].getID() != 0) {
            sprite_manager->GuiSlotBootsSprite.setPosition(view_x - 71 - 15, view_y + 21 - 15);
        } else {
            sprite_manager->GuiSlotBootsSprite.setPosition(view_x - 71 - 29, view_y + 21 - 29);
        }
        sprite_manager->InventoryItemsSprites[24].setPosition(view_x - 203 - 15, view_y + 185 - 15);
        sprite_manager->InventoryItemsSprites[25].setPosition(view_x - 71 - 15, view_y + 185 - 15);
        sprite_manager->InventoryItemsSprites[26].setPosition(view_x + 61 - 15, view_y + 185 - 15);

        sprite_manager->GuiIndicatorSprite.setPosition(game.player->getX()+18, game.player->getY()-34);
    }
};
