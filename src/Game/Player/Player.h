#include "Attacks.h"
#include "Animations.h"
#include "PlayerBase.h"
#include "Equipment.h"
#include "Keys.h"

class Player: public Keys {
public:
    Player(float x_, float y_, float w_, float h_) {
		dx=0; dy=0; speed=0;
		w = w_; h = h_;
        x = x_; y = y_;
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
	    for (int i = getY() / 64; i < (getY()+ h) / 64; i++) {
	        for (int j = getX() / 64; j < (getX() + w) / 64; j++) {
				for (int l = 0; l < game.v_NPC.size(); l++) {
					if (getX() < game.v_NPC[l].getX() + 54 &&
					    getX() + 50 > game.v_NPC[l].getX() &&
					    getY() < game.v_NPC[l].getY() + 62 &&
					    getY() + 62 > game.v_NPC[l].getY())
					{
						if (dy>0) setY(i * 64 + 4);
				        if (dy<0) setY(i * 64 + 64);
				        if (dx>0) setX(j * 64 + 22);
				        if (dx<0) setX(j * 64 + 15);
					}
				}
                auto t = map_manager.getTileMapID(i, j);
		        if (t == 4) {
			        if (dy>0) setY(i * 64 - h);
			        if (dy<0) setY(i * 64 + 64);
			        if (dx>0) setX(j * 64 - w);
			        if (dx<0) setX(j * 64 + 64);
		        }
		        if (t == 5) {
			        setX(300); setY(300);
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

		x += dx*time;
		y += dy*time;
		speed = 0;
		interactionWithMap(map_manager, game);
		sprite.setPosition(getX(), getY());
		setEquipmentStats(game, inv_items);
        keys(time, game);
        attacks(time, game);
        animations(game);
	}

    void setX(float set_x) {
        x = set_x;
    }
    void setY(float set_y) {
        y = set_y;
    }
    Sprite getSprite() {
        return sprite;
    }
    float getX() {
        return x;
    }
    float getY() {
	    return y;
    }
};
