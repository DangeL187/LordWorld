class SpriteDrawer: virtual public SpriteInitializer {
public:
    void drawMap(auto& game) {
        for (int i = 0; i < game.map->getMapHeight(); i++) {
            for (int j = 0; j < game.map->getMapWidth(); j++) {
                game.map->defineTile(i, j);
                game.map->setSpritePosition(j * 64, i * 64);
                game.window_manager->windowDraw(game.map->getSprite());
            }
        }
    }
    void drawEntities(auto& game) {
        for (auto& i_sprite: current_item_sprites) {
            game.window_manager->windowDraw(i_sprite);
        }
        for (auto& i_sprite: current_other_sprites) {
            game.window_manager->windowDraw(i_sprite);
        }
        game.window_manager->windowDraw(game.player->getSprite());
    }
    void drawAnimations(auto& game) {
        if (game.player->attack_animation != 0) {
            game.window_manager->windowDraw(AnimationWeaponSprite);
        }
        if (game.player->is_defence && game.player->inv_items[28].getID() != 0) {
            game.window_manager->windowDraw(AnimationShieldSprite);
        }
        if (game.player->dash_timer > 0) {
            game.window_manager->windowDraw(AnimationDashSprite);
        }
    }
    void drawInterface(auto& game) {
        if (500 <= game.player->critical_timer && game.player->critical_timer <= 750) {
            game.window_manager->windowDraw(GuiIndicatorSprite);
        }
        game.window_manager->windowDraw(GuiBarSprite);
        game.window_manager->windowDraw(GuiHotbarSprite);
        if (game.player->is_dialog) {
            game.window_manager->windowDraw(NPCTalkSprite);
        }

        //TODO: TEMP:
        game.window_manager->windowDraw(circle);
    }
    void drawStats(auto& game) {
        if (game.player->is_stats_open) {
            game.window_manager->windowDraw(GuiStatsSprite);
        }
    }
    void drawInventory(auto& game) {
        if (game.player->is_inventory_open && !game.player->is_inventory_spells_open) {
            game.window_manager->windowDraw(GuiInventorySprite);
            for (auto& i_sprite: InventoryItemsSprites) {
                game.window_manager->windowDraw(i_sprite);
            }
            game.window_manager->windowDraw(GuiSlotWeaponSprite);
            game.window_manager->windowDraw(GuiSlotShieldSprite);
            game.window_manager->windowDraw(GuiSlotHelmSprite);
            game.window_manager->windowDraw(GuiSlotChestSprite);
            game.window_manager->windowDraw(GuiSlotPantsSprite);
            game.window_manager->windowDraw(GuiSlotBootsSprite);
        }
        if (!game.player->is_inventory_open && game.player->is_inventory_spells_open) {
            game.window_manager->windowDraw(GuiInventorySpellsSprite);
            for (auto& i_sprite: InventorySpellsSprites) {
                game.window_manager->windowDraw(i_sprite);
            }
        }
    }
    void drawHotbar(auto& game) {
        for (auto& i_sprite: HotbarSprites) {
            game.window_manager->windowDraw(i_sprite);
        }
        if (game.player->is_aiming) {
            game.window_manager->windowDraw(GuiPickedSpellSprite);
        }
        for (auto& i: GuiNoManaSprites) {
            game.window_manager->windowDraw(i);
        }
    }
    void drawinfo(auto& game) {
        if (game.renderer->text_manager->text_info.getString() != "") {
            game.window_manager->windowDraw(GuiInfoSprite);
        }
    }
};
