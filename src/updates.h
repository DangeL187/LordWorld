void updates(auto time) {
    for (int v0 = 0; v0 < v_monsters.size(); v0++) {
        v_monsters[v0].update(time);
        v_monsters[v0].moveMonster(time);
        for (int v1 = 0; v1 < v_monsters.size(); v1++) {
            float mx1 = v_monsters[v0].getMonsterCoordinateX();
            float mx2 = v_monsters[v1].getMonsterCoordinateX();
            float my1 = v_monsters[v0].getMonsterCoordinateY();
            float my2 = v_monsters[v1].getMonsterCoordinateY();
            float condx = pow(pow((mx1 - mx2), 2), 0.5);
    		float condy = pow(pow((my1 - my2), 2), 0.5);
            //todo: replace 52 and 64 with unique values for each monster
        	if (condx <= 52 && condy <= 64 && v0 != v1) { //collision with monsters
                if (v_monsters[v0].getMonsterDX() > 0) {
                    v_monsters[v0].addMonsterX(false);
                }
                if (v_monsters[v0].getMonsterDX() < 0) {
                    v_monsters[v0].addMonsterX(true);
                }
                if (v_monsters[v0].getMonsterDY() > 0) {
                    v_monsters[v0].addMonsterY(false);
                }
                if (v_monsters[v0].getMonsterDY() < 0) {
                    v_monsters[v0].addMonsterY(true);
                }
    		}
        }
	}
    for (int v0 = 0; v0 < v_NPC.size(); v0++) {
        v_NPC[v0].update(time);
    }
}
