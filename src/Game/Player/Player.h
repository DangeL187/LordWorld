#include "PlayerVars.h"
#include "Keys.h"
#include "Equipment.h"

class Player: public Keys, public Equipment {
private:
    Sprite sprite;
	std::pair<float, float> p_pos{300, 300};
    float w, h, dx, dy;
	int inv_items[33]; //items inventory
	int inv_types[24]; //item types invenory
public:
    Player(float X, float Y, float W, float H) {
		dx=0; dy=0; speed=0;
		w = W; h = H;
		p_pos.first = X; p_pos.second = Y;
        NewSprite *new_player_sprite = new NewSprite("../images/hero.png");
        sprite = new_player_sprite->getSprite();
		sprite.setTextureRect(IntRect(0, 0, w, h));
	}

	void interactionWithMap(auto &map_manager, auto &v_NPC) {
	    for (int i = p_pos.second / 64; i < (p_pos.second + h) / 64; i++) {
	        for (int j = p_pos.first / 64; j < (p_pos.first + w) / 64; j++) {
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
			        if (dy>0) p_pos.second = i * 64 - h;
			        if (dy<0) p_pos.second = i * 64 + 64;
			        if (dx>0) p_pos.first = j * 64 - w;
			        if (dx<0) p_pos.first = j * 64 + 64;
		        }
		        if (map_manager.getTileMapID(i, j) == 2) {
			        p_pos.first = 300; p_pos.second = 300;
					map_manager.setTileMapID(i, j, 0);
			        //TODO: make createMonster() available to call from here
		        }
	        }
	    }
    }

    void update(float time, auto &map_manager, auto &v_NPC, auto &items_dropped_id) {
		switch (dir) {
			case 0: dx = speed; dy = 0; break;
			case 1: dx = -speed; dy = 0; break;
			case 2: dx = 0; dy = -speed; break;
			case 3: dx = 0; dy = speed; break;
		}

		p_pos.first += dx*time;
		p_pos.second += dy*time;
		speed = 0;
		interactionWithMap(map_manager, v_NPC);
		sprite.setPosition(p_pos.first, p_pos.second);
		setEquipmentStats(inv_items);
        keys(time, sprite, v_NPC, v_NPC, items_dropped_id); //replace third argument with v_monsters
	}

    Sprite getSprite() {
        return sprite;
    }
    float getX() {
        return p_pos.first;
    }
    float getY() {
	    return p_pos.second;
    }
};
