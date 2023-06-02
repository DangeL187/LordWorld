#include "PlayerBase.h"
#include "Equipment.h"
#include "Keys.h"

class Player: public Keys {
public:
    Player(float x_, float y_, float w_, float h_) {
		dx=0; dy=0; speed=0;
		w = w_; h = h_;
        p_cords[0] = x_; p_cords[1] = y_;
        NewSprite *new_player_sprite = new NewSprite("../images/hero.png");
        sprite = new_player_sprite->getSprite();
		sprite.setTextureRect(IntRect(1, 1, w, h));
        for (int i = 0; i <= 33; i++) { //add zero items in inventory
            inv_items[i] = 0;
            if (i <= 24) {
                inv_types[i] = 0;
            }
        }
	for (int i = 0; i <= 24; i++) { //add zero items in inventory
            inv_spells[i] = 0;
        }
        hotbar_spells[0] = 1;
        hotbar_spells[1] = 2;
	}

	void interactionWithMap(auto& map_manager, auto& game) {
	    for (int i = p_cords[1] / 64; i < (p_cords[1]+ h) / 64; i++) {
	        for (int j = p_cords[0] / 64; j < (p_cords[0] + w) / 64; j++) {
				for (int l = 0; l < game.v_NPC.size(); l++) {
					if (p_cords[0] < game.v_NPC[l].getX() + 54 &&
					    p_cords[0] + 50 > game.v_NPC[l].getX() &&
					    p_cords[1] < game.v_NPC[l].getY() + 62 &&
					    p_cords[1] + 62 > game.v_NPC[l].getY())
					{
						if (dy>0) p_cords[1] = i * 64 + 4;
				        if (dy<0) p_cords[1] = i * 64 + 64;
				        if (dx>0) p_cords[0] = j * 64 + 22;
				        if (dx<0) p_cords[0] = j * 64 + 15;
					}
				}
                auto t = map_manager.getTileMapID(i, j);
		        if (t == 4) {
			        if (dy>0) p_cords[1] = i * 64 - h;
			        if (dy<0) p_cords[1] = i * 64 + 64;
			        if (dx>0) p_cords[0] = j * 64 - w;
			        if (dx<0) p_cords[0] = j * 64 + 64;
		        }
		        if (t == 5) {
			        p_cords[0] = 300; p_cords[1] = 300;
					map_manager.setTileMapID(i, j, 0);
		        }
	        }
	    }
    }

    void update(float time, auto& map_manager, auto& game) {
		switch (dir) {
			case 0: dx = speed; dy = 0; break;
			case 1: dx = -speed; dy = 0; break;
			case 2: dx = 0; dy = -speed; break;
			case 3: dx = 0; dy = speed; break;
		}

		p_cords[0] += dx*time;
		p_cords[1] += dy*time;
		speed = 0;
		interactionWithMap(map_manager, game);
		sprite.setPosition(p_cords[0], p_cords[1]);
		setEquipmentStats(game, inv_items);
        keys(time, game);
        attacks(time, game);
        animations(time, game);
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
