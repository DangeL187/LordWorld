#include "PlayerVars.h"
#include "Keys.h"
#include "Equipment.h"

class Player: public Keys, public Equipment {
public:
    Player(float X, float Y, float W, float H) {
		dx=0; dy=0; speed=0;
		w = W; h = H;
        p_cords[0] = X; p_cords[1] = Y;
        NewSprite *new_player_sprite = new NewSprite("../images/hero.png");
        sprite = new_player_sprite->getSprite();
		sprite.setTextureRect(IntRect(0, 0, w, h));
	}

	void interactionWithMap(auto &map_manager, auto &v_NPC) {
	    for (int i = p_cords[1] / 64; i < (p_cords[1]+ h) / 64; i++) {
	        for (int j = p_cords[0] / 64; j < (p_cords[0] + w) / 64; j++) {
				/*for (int l = 0; l < v_NPC.size(); l++) {
					if (p_pos.first < v_NPC[l].getX() + 54 &&
					    p_pos.first + 50 > v_NPC[l].getX() &&
					    p_pos.second < v_NPC[l].getY() + 62 &&
					    p_pos.second + 62 > v_NPC[l].getY())
					{
						if (dy>0) p_pos.second = i * 64 + 4;
				        if (dy<0) p_pos.second = i * 64 + 64;
				        if (dx>0) p_pos.first = j * 64 + 22;
				        if (dx<0) p_pos.first = j * 64 + 15;
					}
				}*/
		        if (map_manager.getTileMapID(i, j) == 1 ||
					(map_manager.getTileMapID(i, j) >= 3 &&
					map_manager.getTileMapID(i, j) <= 31))
				{
			        if (dy>0) p_cords[1] = i * 64 - h;
			        if (dy<0) p_cords[1] = i * 64 + 64;
			        if (dx>0) p_cords[0] = j * 64 - w;
			        if (dx<0) p_cords[0] = j * 64 + 64;
		        }
		        if (map_manager.getTileMapID(i, j) == 2) {
			        p_cords[0] = 300; p_cords[1] = 300;
					map_manager.setTileMapID(i, j, 0);
			        //TODO: make createMonster() available to call from here
		        }
	        }
	    }
    }

    void update(float time, auto &map_manager, auto &v_NPC, auto &game) {
		switch (dir) {
			case 0: dx = speed; dy = 0; break;
			case 1: dx = -speed; dy = 0; break;
			case 2: dx = 0; dy = -speed; break;
			case 3: dx = 0; dy = speed; break;
		}

		p_cords[0] += dx*time;
		p_cords[1] += dy*time;
		speed = 0;
		interactionWithMap(map_manager, v_NPC);
		sprite.setPosition(p_cords[0], p_cords[1]);
		setEquipmentStats(inv_items);
        keys(time, v_NPC, v_NPC, game); //replace third argument with v_monsters
	}

    Sprite getSprite() {
        return sprite;
    }
    float getX() {
        return p_cords[0];
    }
    float getY() {
	    return p_cords[1];
    }
};
