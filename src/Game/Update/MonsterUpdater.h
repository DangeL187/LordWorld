class MonsterUpdater {
private:
    void monsterDeath(auto& game) {
        auto& monsters = game.entity_manager->v_monsters;
        for (int i = 0; i < monsters.size(); i++) {
            if (monsters[i].getHP() <= 0) {
                std::vector<Sprite>& cos = game.renderer->sprite_manager->current_other_sprites;
                cos.erase(cos.begin() + monsters[i].getSprite());
                game.renderer->sprite_manager->other_sprite_counter--;
                game.target_m = NULL;
                game.renderer->text_manager->text_target.setString("");
                for (int j = 0; j < monsters.size(); j++) {
                    if (j > i) {
                        monsters[j].reduceSprite();
                    }
                }
                game.player->xp += monsters[i].getXP();
                monsters[i].dropMonster(game);
                monsters.erase(monsters.begin() + i);
            }
        }
    }
protected:
    void updateMonsters(auto& time, auto& game) {
        monsterDeath(game);

        auto& monsters = game.entity_manager->v_monsters;
        int index1 = 0;
        for (auto& monster1: monsters) {
            int index2 = 0;
            monster1.update(time, game, game.player);
            monster1.moveMonster(time, game, game.player);
            for (auto& monster2: monsters) {
                float mx1 = monster1.getX();
                float mx2 = monster2.getX();
                float my1 = monster1.getY();
                float my2 = monster2.getY();
                float condx = pow(pow((mx1 - mx2), 2), 0.5);
                float condy = pow(pow((my1 - my2), 2), 0.5);
                //todo: replace 52 and 64 with unique values for each monster
                if (condx <= 52 && condy <= 64 && index1 != index2) { //collision with monsters
                    if (monster1.getDX() > 0) {
                        monster1.addX(false);
                    }
                    if (monster1.getDX() < 0) {
                        monster1.addX(true);
                    }
                    if (monster1.getDY() > 0) {
                        monster1.addY(false);
                    }
                    if (monster1.getDY() < 0) {
                        monster1.addY(true);
                    }
                }
                index2++;
            }
            index1++;
        }
    }
};
