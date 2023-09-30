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
        for (int i = 0; i < 33; i++) { //add zero items in inventory
            inv_items[i] = 0;
            if (i < 24) {
                inv_types[i] = 0;
            }
        }
        for (int i = 0; i < 24; i++) { //add zero items in spell inventory
            inv_spells[i] = 0;
        }
        for (int i = 0; i < 9; i++) { //add zero items in hotbar
            hotbar_spells[i] = 0;
        }
        hotbar_spells[0] = 1;
        hotbar_spells[1] = 2;
        hotbar_spells[2] = 1;
        hotbar_spells[3] = 2;
        hotbar_spells[4] = 1;
        hotbar_spells[5] = 2;
        hotbar_spells[6] = 1;
        hotbar_spells[7] = 2;
        hotbar_spells[8] = 1;
	}

	void interactionWithMap(auto& game) {
	    for (int i = y / 64; i < (y + h) / 64; i++) {
	        for (int j = x / 64; j < (x + w) / 64; j++) {
				for (auto& v: game.v_NPC) {
                    float nx = v.getX();
                    float ny = v.getY();
					if (x < nx + w && x + w > nx && y < ny + h && y + h > ny) {
						if (dy>0) y = (ny - h);
				        if (dy<0) y = (ny + h);
				        if (dx>0) x = (nx - w);
				        if (dx<0) x = (nx + w);
					}
				}
                auto t = game.map->getTileMapID(i, j);
		        if (t == 4) {
			        if (dy>0) setY(i * 64 - h);
			        if (dy<0) setY(i * 64 + 64);
			        if (dx>0) setX(j * 64 - w);
			        if (dx<0) setX(j * 64 + 64);
		        }
		        if (t == 5) {
			        setX(300); setY(300);
					game.map->setTileMapID(i, j, 0);
		        }
	        }
	    }
    }

    void update(float time, auto& game) {
		switch (dir) {
			case 0: dx = speed; dy = 0; break;
			case 1: dx = -speed; dy = 0; break;
			case 2: dx = 0; dy = -speed; break;
			case 3: dx = 0; dy = speed; break;
		}

		x += dx*time;
		y += dy*time;
		speed = 0;

		interactionWithMap(game);
		sprite.setPosition(getX(), getY());
		setEquipmentStats(game.renderer->sprite_manager, inv_items);
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
    float getWidth() {
        return w;
    }
    float getHeight() {
        return h;
    }
    float getX() {
        return x;
    }
    float getY() {
	    return y;
    }
};
