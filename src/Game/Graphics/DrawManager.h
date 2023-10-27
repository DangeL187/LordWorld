class DrawManager {
protected:
    void drawMap(std::shared_ptr<WindowManager>& window_manager, std::shared_ptr<Map>& map) {
        for (int i = 0; i < map->getMapHeight(); i++) {
            for (int j = 0; j < map->getMapWidth(); j++) {
                map->defineTile(i, j);
                map->setSpritePosition(j * 64, i * 64);
                window_manager->windowDraw(map->getSprite());
            }
        }
    }
    void drawEntities(std::shared_ptr<WindowManager>& window_manager, std::shared_ptr<EntityManager>& entity_manager, std::shared_ptr<Player>& player) {
        for (auto& item: entity_manager->v_items) {
            window_manager->windowDraw(item.getSprite());
        }
        for (auto& monster: entity_manager->v_monsters) {
            window_manager->windowDraw(monster.getSprite());
        }
        for (auto& npc: entity_manager->v_NPC) {
            window_manager->windowDraw(npc.getSprite());
        }

        window_manager->windowDraw(player->getSprite());
    }
    void drawAnimations(std::shared_ptr<WindowManager>& window_manager, std::shared_ptr<Player>& player) {
        if (player->attack_animation != 0) {
            window_manager->windowDraw(player->inv_items[27].getAnimationSprite());
        }
        if (player->is_defence) {
            window_manager->windowDraw(player->inv_items[28].getAnimationSprite());
        }
        if (player->dash_timer->isRunning()) {
            window_manager->windowDraw(player->getAnimationDashSprite());
        }
    }
};
