void monsterDeath() {
    for (int i = 0; i < v_monsters.size(); i++) {
        if (v_monsters[i].getMonsterHP() <= 0) {
            other_sprites.erase(other_sprites.begin() + v_monsters[i].getMonsterSprite());
            sprite_counter--;
            if (i == target_number) {
                target_m.erase(target_m.begin() + 0);
                target_number = -1;
                text.setString("");
            }
            for (int j = 0; j < v_monsters.size(); j++) {
                if (j > i) {
                    v_monsters[j].reduceMonsterSprite();
                }
            }
            for (int j = 0; j < items_dropped_sprites.size(); j++) {
                if (items_dropped_sprites[j] > v_monsters[i].getMonsterSprite()) {
                    items_dropped_sprites[j] = items_dropped_sprites[j] - 1;
                }
            }
            player_xp += v_monsters[i].getMonsterXP();
            v_monsters[i].dropMonster();
            v_monsters.erase(v_monsters.begin() + i);
        }
    }
}
