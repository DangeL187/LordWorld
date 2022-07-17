#include "MonsterBase.h"

class Monster: public MonsterBase {
public:
	Monster(float x_, float y_, float w_, float h_, std::string name_, auto& game) {
		static_sprite = game.sprite_counter;
		dx=0; dy=0; speed=0;
		w = w_; h = h_;
		name = name_;
		defineMonster(name, game, sprite);
		as_cd = as;
		game.other_sprites.push_back(sprite);
		x = x_; y = y_;
		game.other_sprites[static_sprite].setTextureRect(IntRect(0, 0, w, h));
		game.sprite_counter++;
	}

	void interactionWithMap(auto& time, auto& map_manager, auto& game, auto& player) {
	    for (int i = y / 64; i < (y + h) / 64; i++) {
	        for (int j = x / 64; j < (x + w) / 64; j++) {
		        if (map_manager.TileMap[i][j] == 1) {
			        if (dy>0) y = i * 64 - h;
			        if (dy<0) y = i * 64 + 64;
			        if (dx>0) x = j * 64 - w;
			        if (dx<0) x = j * 64 + 64;
		        }
		        if (map_manager.TileMap[i][j] == 2) {
			        x = 300; y = 300;
			        map_manager.TileMap[i][j] = 0;
		        }
	        }
	    }
		float condx0 = pow(pow((x - player.p_cords[0]), 2), 0.5);
		float condy0 = pow(pow((y - player.p_cords[1]), 2), 0.5);
		if (condx0 <= 52 && condy0 <= 64 && !stun) { //collision with player
			if (as_cd > 0) {
	            as_cd -= time;
				if (as_cd <= (as - 300)) {
					switch (dir) {
					    case 0: game.other_sprites[static_sprite].setTextureRect(IntRect(52 * int(monster_frame), 128, w, h)); break;
					    case 1: game.other_sprites[static_sprite].setTextureRect(IntRect(52 * int(monster_frame), 64, w, h)); break;
					    case 2: game.other_sprites[static_sprite].setTextureRect(IntRect(52 * int(monster_frame), 192, w, h)); break;
					    case 3: game.other_sprites[static_sprite].setTextureRect(IntRect(52 * int(monster_frame), 0, w, h)); break;
					}
				}
	        } else {
				float a = player.armor / 5;
				float aa = dmg - (dmg * (player.physical_resistance / 100));
				int b = static_cast<int>(aa) - static_cast<int>(a);
				if (b >= 0) {
					if (game.defence && game.defence_counter < 2) {
						game.defence_counter++;
					}
					else {
					    player.hp -= b;
				    }
				}
				switch (dir) {
					case 0: game.other_sprites[static_sprite].setTextureRect(IntRect(52 * 3, 128, w, h)); break;
					case 1: game.other_sprites[static_sprite].setTextureRect(IntRect(52 * 3, 64, w, h)); break;
					case 2: game.other_sprites[static_sprite].setTextureRect(IntRect(52 * 3, 192, w, h)); break;
					case 3: game.other_sprites[static_sprite].setTextureRect(IntRect(52 * 3, 0, w, h)); break;
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
		interactionWithMap(time);
		game.other_sprites[static_sprite].setPosition(x, y);
		checkBuff(time, player);
	}

	void moveMonster(auto& time, auto& game, auto& player) {
		if (move_monster_timer > 0) {
            move_monster_timer -= time;
        } else {
            random_generated_dir = rand() % 5;
            move_monster_timer = 1000;
        }
		float condx = pow(pow((x - player.p_cords[0]), 2), 0.5);
		float condy = pow(pow((y - player.p_cords[1]), 2), 0.5);
		if (condx <= 300 && condy <= 300 && !stun) {
			if (condx <= 52 && condy <= 64) {} //collision with player
			else {
				if (y <= player.p_cords[1]) {
					speed = 0.1; dir = 3;
					game.other_sprites[static_sprite].setTextureRect(IntRect(52 * int(monster_frame), 0, w, h));
					monster_frame += 0.005 * time;
					if (monster_frame > 3) {
				        monster_frame -= 3;
				    }
					update(time);
				}
				if (y >= player.p_cords[1]) {
					speed = 0.1; dir = 2;
					game.other_sprites[static_sprite].setTextureRect(IntRect(52 * int(monster_frame), 192, w, h));
					monster_frame += 0.005 * time;
					if (monster_frame > 3) {
				        monster_frame -= 3;
				    }
					update(time);
				}
				if (x <= player.p_cords[0]) {
					speed = 0.1; dir = 0;
					game.other_sprites[static_sprite].setTextureRect(IntRect(52 * int(monster_frame), 128, w, h));
					monster_frame += 0.005 * time;
					if (monster_frame > 3) {
				        monster_frame -= 3;
				    }
					update(time);
				}
				if (x >= player.p_cords[0]) {
					speed = 0.1; dir = 1;
					game.other_sprites[static_sprite].setTextureRect(IntRect(52 * int(monster_frame), 64, w, h));
					monster_frame += 0.005 * time;
					if (monster_frame > 3) {
				        monster_frame -= 3;
				    }
					update(time);
				}
			}
		}
		else {
			if (!stun) {
				switch (random_generated_dir) {
				    case 0: speed = 0.1; dir = 0; update(time); break;
				    case 1: speed = 0.1; dir = 1; update(time); break;
				    case 2: speed = 0.1; dir = 2; update(time); break;
				    case 3: speed = 0.1; dir = 3; update(time); break;
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
	void hitMonster(int local_dmg, float hittime, auto& player) {
		hp -= local_dmg;
		dealt = true;
		checkBuff(hittime, player);
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
	void giveBuff(std::string somebuff, int sometime) {
	    buffs.push_back(somebuff);
		timers.push_back(sometime);
	}
	void reduceMonsterSprite() {
		static_sprite--;
	}
	void addMonsterX(bool get_operation) {
		if (get_operation) {
			x++;
		}
		else {
			x--;
		}
	}
	void addMonsterY(bool get_operation) {
		if (get_operation) {
			y++;
		}
		else {
			y--;
		}
	}
	int getMonsterSprite() {
		return static_sprite;
	}
	int getMonsterXP() {
		return xp;
	}
	float getMonsterDX() {
        return dx;
    }
	float getMonsterDY() {
        return dy;
    }
	float getMonsterCoordinateX() {
        return x;
    }
    float getMonsterCoordinateY() {
	    return y;
    }
	int getMonsterHP() {
        return hp;
    }
	int getMonsterMP() {
		return mp;
	}
	int getMonsterLVL() {
		return lvl;
	}
	std::string getMonsterName() {
		return name;
	}
};
