#include "MonsterBase.h"

class Monster: public MonsterBase {
public:
	Monster(float x_, float y_, float w_, float h_, std::string name_, auto& monster_sprites_, auto& other_sprite_counter_, auto& current_other_sprites_) {
		static_sprite = other_sprite_counter_;
		dx=0; dy=0; speed=0;
		w = w_; h = h_;
		name = name_;
		defineMonster(name, monster_sprites_, sprite);
		as_cd = as;
		current_other_sprites_.push_back(sprite);
		x = x_; y = y_;
		current_other_sprites_[static_sprite].setTextureRect(IntRect(0, 0, w, h));
		other_sprite_counter_++;
	}

	void interactionWithMap(auto& time, auto& game, auto& player) {
	    for (int i = y / 64; i < (y + h) / 64; i++) {
	        for (int j = x / 64; j < (x + w) / 64; j++) {
				auto t = game.map->getTileMapID(i, j);
		        if (t == 4) {
			        if (dy>0) y = i * 64 - h;
			        if (dy<0) y = i * 64 + 64;
			        if (dx>0) x = j * 64 - w;
			        if (dx<0) x = j * 64 + 64;
		        }
		        if (t == 5) {
			        x = 300; y = 300;
			        game.map->setTileMapID(i, j, 0);
		        }
	        }
	    }
		float condx0 = pow(pow((x - player->getX()), 2), 0.5);
		float condy0 = pow(pow((y - player->getY()), 2), 0.5);
		if (condx0 <= 52 && condy0 <= 64 && !stun) { //collision with player
			if (as_cd > 0) {
	            as_cd -= time;
				if (as_cd <= (as - 300)) {
					switch (dir) {
					    case 0: game.current_other_sprites[static_sprite].setTextureRect(IntRect(52 * int(monster_frame), 128, w, h)); break;
					    case 1: game.current_other_sprites[static_sprite].setTextureRect(IntRect(52 * int(monster_frame), 64, w, h)); break;
					    case 2: game.current_other_sprites[static_sprite].setTextureRect(IntRect(52 * int(monster_frame), 192, w, h)); break;
					    case 3: game.current_other_sprites[static_sprite].setTextureRect(IntRect(52 * int(monster_frame), 0, w, h)); break;
					}
				}
	        } else {
				float a = player->armor / 5;
				float aa = dmg - (dmg * (player->physical_resistance / 100));
				int b = static_cast<int>(aa) - static_cast<int>(a);
				if (b >= 0 && !player->defence) {
					player->hp -= b;
					player->shield_cd = 5000;
					auto get_pos_x = player->getX() + int(w / 2);
	                auto get_pos_y = player->getY() + 20;
	                game.createDynamicText(game.font, 30, 500, std::to_string(0-b), get_pos_x, get_pos_y, true);
				} else {
					player->shield_cd = 0;
				}
				switch (dir) {
					case 0: game.current_other_sprites[static_sprite].setTextureRect(IntRect(52 * 3, 128, w, h)); break;
					case 1: game.current_other_sprites[static_sprite].setTextureRect(IntRect(52 * 3, 64, w, h)); break;
					case 2: game.current_other_sprites[static_sprite].setTextureRect(IntRect(52 * 3, 192, w, h)); break;
					case 3: game.current_other_sprites[static_sprite].setTextureRect(IntRect(52 * 3, 0, w, h)); break;
				}
	            as_cd = as;
	        }
		} else { as_cd = as; }
    }

    void update(auto& time, auto& game, auto& player) {
		switch (dir) {
		    case 0: dx = speed; dy = 0; break;
		    case 1: dx = -speed; dy = 0; break;
		    case 2: dx = 0; dy = -speed; break;
		    case 3: dx = 0; dy = speed; break;
		}

		x += dx*time;
		y += dy*time;

		speed = 0;
		interactionWithMap(time, game, player);
		game.current_other_sprites[static_sprite].setPosition(x, y);
		checkBuff(time, player);
	}

	void moveMonster(auto& time, auto& game, auto& player) {
		if (move_monster_timer > 0) {
            move_monster_timer -= time;
        } else {
            random_generated_dir = rand() % 5;
            move_monster_timer = 1000;
        }
		float condx = pow(pow((x - player->getX()), 2), 0.5);
		float condy = pow(pow((y - player->getY()), 2), 0.5);
		if (condx <= 300 && condy <= 300 && !stun) {
			if (condx <= 52 && condy <= 64) {} //collision with player
			else {
				if (y <= player->getY()) {
					speed = 0.1; dir = 3;
					game.current_other_sprites[static_sprite].setTextureRect(IntRect(52 * int(monster_frame), 0, w, h));
					monster_frame += 0.005 * time;
					if (monster_frame > 3) {
				        monster_frame -= 3;
				    }
					update(time, game, player);
				}
				if (y >= player->getY()) {
					speed = 0.1; dir = 2;
					game.current_other_sprites[static_sprite].setTextureRect(IntRect(52 * int(monster_frame), 192, w, h));
					monster_frame += 0.005 * time;
					if (monster_frame > 3) {
				        monster_frame -= 3;
				    }
					update(time, game, player);
				}
				if (x <= player->getX()) {
					speed = 0.1; dir = 0;
					game.current_other_sprites[static_sprite].setTextureRect(IntRect(52 * int(monster_frame), 128, w, h));
					monster_frame += 0.005 * time;
					if (monster_frame > 3) {
				        monster_frame -= 3;
				    }
					update(time, game, player);
				}
				if (x >= player->getX()) {
					speed = 0.1; dir = 1;
					game.current_other_sprites[static_sprite].setTextureRect(IntRect(52 * int(monster_frame), 64, w, h));
					monster_frame += 0.005 * time;
					if (monster_frame > 3) {
				        monster_frame -= 3;
				    }
					update(time, game, player);
				}
			}
		}
		else {
			if (!stun) {
				switch (random_generated_dir) {
				    case 0:
					    speed = 0.1;
						dir = 0;
						update(time, game, player);
						break;
				    case 1:
					    speed = 0.1;
						dir = 1;
						update(time, game, player);
						break;
				    case 2:
					    speed = 0.1;
						dir = 2;
						update(time, game, player);
						break;
				    case 3:
					    speed = 0.1;
						dir = 3;
						update(time, game, player);
						break;
				}
			}
		}
	}
	void checkBuff(auto& time, auto& player) {
		stun = false;
		for (int v = 0; v < buffs.size(); v++) {
			defineBuff(v, player);
			buffTimers(v, time);
			if (timers[v] <= 0) {
				buffs.erase(buffs.begin() + v);
		        timers.erase(timers.begin() + v);
			}
		}
	}
	void giveBuff(auto buff, auto time) {
	    buffs.push_back(buff);
		timers.push_back(time);
	}
	void hitMonster(int local_dmg, auto& time, auto& player) {
		hp -= local_dmg;
		dealt = true;
		checkBuff(time, player);
		dealt = false;
	}
	void dropMonster(auto& game) {
		for (int r = 0; r < drop_chance.size(); r++) {
			int random_drop = rand() % 100;
			random_drop++;
			if (random_drop <= drop_chance[r]) {
				game.createItem(drop[r], x, y);
			}
		}
	}
	void reduceSprite() {
		static_sprite--;
	}
	void addX(bool get_operation) {
		if (get_operation) {
			x++;
		}
		else {
			x--;
		}
	}
	void addY(bool get_operation) {
		if (get_operation) {
			y++;
		}
		else {
			y--;
		}
	}
	int getSprite() {
		return static_sprite;
	}
	int getXP() {
		return xp;
	}
	float getDX() {
        return dx;
    }
	float getDY() {
        return dy;
    }
	float getX() {
        return x;
    }
    float getY() {
	    return y;
    }
	float getWidth() {
        return w;
    }
    float getHeight() {
	    return h;
    }
	int getHP() {
        return hp;
    }
	int getMP() {
		return mp;
	}
	int getLVL() {
		return lvl;
	}
	std::string getName() {
		return name;
	}
};
