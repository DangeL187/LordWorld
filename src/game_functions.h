void targeting() {
    int out = player_x - (962 - Mouse::getPosition().x);
	int outy = player_y - (544 - Mouse::getPosition().y);
	for (int v = 0; v < v_monsters.size(); v++) {
		float mx = v_monsters[v].getMonsterCoordinateX();
		float my = v_monsters[v].getMonsterCoordinateY();
        float condx = mx/1 + range*64 - 14;
        float condy = my/1 + range*64;
		if (mx/1 <= out && out <= condx && my/1 <= outy && outy <= condy) {
			if (target_m.size() == 0) {
                target_m.push_back(v_monsters[v]);
                target_number = v;
            }
			else {
                target_m[0] = v_monsters[v];
                target_number = v;
            }
		}
	}
}

void spellDamaged() { //TODO: different types of damage range, unite it with monsters_damaged?
    damaged_numbers.clear();
    int out = player_x - (962 - Mouse::getPosition().x);
	int outy = player_y - (544 - Mouse::getPosition().y);
	for (int v = 0; v < v_monsters.size(); v++) {
        float mx = v_monsters[v].getMonsterCoordinateX();
		float my = v_monsters[v].getMonsterCoordinateY();
        float condx = mx/1 + range*64;
        float condy = my/1 + range*64;
		if (mx/1 <= out && out <= condx && my/1 <= outy && outy <= condy) { //TODO: fix aoe range?
			damaged_numbers.push_back(v);
		}
	}
}

void moveCurrentFrame(float get_time) {
	current_frame += 0.005 * get_time;
	if (current_frame > 3) {
        current_frame -= 3;
    }
}

static void createMonster(float x, float y, float w, float h, std::string name) {
    Monster m(x, y, w, h, name);
    v_monsters.push_back(m);
}
void createNPC(float x, float y, float w, float h, std::string name) {
    NPC m(x, y, w, h, name);
    v_NPC.push_back(m);
}