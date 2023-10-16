#include "Initializer/Initializer.h"
#include "Animations/Animations.h"
#include "Equipment/Equipment.h"
#include "Combat/Combat.h"
#include "Controls/Controls.h"

class Player: virtual public Initializer, virtual protected Equipment, protected Combat, protected Animations, protected Controls {
private:
    void updateLVL() {
        if (xp >= lvl * 100) {
            xp -= lvl * 100;
            lvl++;
        }
    }
public:
    Player(float x_, float y_, float w_, float h_) {
        dx=0; dy=0; speed=0;
		w = w_; h = h_;
        x = x_; y = y_;
        initialize();
	}

	void interactionWithMap(auto& game) {
	    for (int i = y / 64; i < (y + h) / 64; i++) {
	        for (int j = x / 64; j < (x + w) / 64; j++) {
				for (auto& npc: game.entity_manager->v_NPC) {
                    float nx = npc.getX();
                    float ny = npc.getY();
                    float nw = npc.getWidth();
                    float nh = npc.getHeight();
                    if (isCollision(x, y, w, h, nx, ny, nw, nh)) {
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

    void update(auto& time, auto& game) {
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
		Equipment::setEquipmentStats(game.renderer->sprite_manager);
        controls(time, game);
        combat(time, game);
        animations(game);
        updateLVL();
        sprite.setPosition(x, y);
	}

    void setX(float set_x) {
        x = set_x;
    }
    void setY(float set_y) {
        y = set_y;
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
    Sprite getSprite() {
        return sprite;
    }
};
