class Player {
public:
	float x, y;
    float w, h, dx, dy, speed;
    int dir = 0;
    Image image;
    Texture texture;

    Player(float X, float Y, float W, float H) {
		dx=0;dy=0;speed=0;
		w = W; h = H;
		image.loadFromFile("../images/hero.png");
		texture.loadFromImage(image);
		herosprite.setTexture(texture);
		x = X; y = Y;
		herosprite.setTextureRect(IntRect(0, 0, w, h));
	}

    void interactionWithMap() {
	    for (int i = y / 64; i < (y + h) / 64; i++) {
	        for (int j = x / 64; j < (x + w) / 64; j++) {
		        if (TileMap[i][j] == 1 || TileMap[i][j] >= 3 && TileMap[i][j] <= 31) {
			        if (dy>0) y = i * 64 - h;
			        if (dy<0) y = i * 64 + 64;
			        if (dx>0) x = j * 64 - w;
			        if (dx<0) x = j * 64 + 64;
		        }
		        if (TileMap[i][j] == 2) {
			        x = 300; y = 300;
			        TileMap[i][j] = 0;
			        //TODO: make createMonster() available to call from here
		        }
	        }
	    }
    }

    void update(float time) {
		switch (dir) {
			case 0: dx = speed; dy = 0; break;
			case 1: dx = -speed; dy = 0; break;
			case 2: dx = 0; dy = -speed; break;
			case 3: dx = 0; dy = speed; break;
		}

		x += dx*time;
		y += dy*time;
		speed = 0;
		interactionWithMap();
		player_x = x/1;
		player_y = y/1;
		player_dir = dir;
		herosprite.setPosition(x, y);
		setWeaponStats();
		setShieldStats();
		setHelmetStats();
		setChestplateStats();
		setPantsStats();
		setBootsStats();
		armor = armor_shield + armor_helmet + armor_chestplate + armor_pants + armor_boots;
		setOtherStats();
		if (armor_helmet == armor_chestplate && armor_chestplate == armor_pants && armor_pants == armor_boots && armor_boots != 0) {
			armor += armor_helmet;
		}
	}
    float getPlayerCoordinateX() {
        return x;
    }
    float getPlayerCoordinateY() {
	    return y;
    }
};

class Monster {
public:
	float x, y;
	float w, h, dx, dy, speed;
	int dir = 0;
	int random_generated_dir = 0;
	int dmg, hp, mp, lvl, as, xp;
	float as_cd;
	float monster_frame;
	int static_sprite = sprite_counter;
	std::string name;
	std::vector<std::string> buffs;
	std::vector<int> drop;
	std::vector<int> drop_chance;
	std::vector<int> timers; //spells timers
	Image image;
	Texture texture;
	Sprite sprite;
	bool dealt = false;
	bool stun = false;

	Monster(float X, float Y, float W, float H, std::string NAME) {
		dx=0;dy=0;speed=0;
		w = W; h = H;
		name = NAME;
		#include "monsters.h"
		as_cd = as;
		other_sprites.push_back(sprite);
		x = X; y = Y;
		other_sprites[static_sprite].setTextureRect(IntRect(0, 0, w, h));
		sprite_counter++;
	}

	void interactionWithMap(float get_time) {
	    for (int i = y / 64; i < (y + h) / 64; i++) {
	        for (int j = x / 64; j < (x + w) / 64; j++) {
		        if (TileMap[i][j] == 1) {
			        if (dy>0) y = i * 64 - h;
			        if (dy<0) y = i * 64 + 64;
			        if (dx>0) x = j * 64 - w;
			        if (dx<0) x = j * 64 + 64;
		        }
		        if (TileMap[i][j] == 2) {
			        x = 300; y = 300;
			        TileMap[i][j] = 0;
		        }
	        }
	    }
		float condx0 = pow(pow((x - player_x), 2), 0.5);
		float condy0 = pow(pow((y - player_y), 2), 0.5);
		if (condx0 <= 52 && condy0 <= 64 && !stun) { //collision with player
			if (as_cd > 0) {
	            as_cd -= get_time;
				if (as_cd <= (as - 300)) {
					switch (dir) {
					    case 0: other_sprites[static_sprite].setTextureRect(IntRect(52 * int(monster_frame), 128, w, h)); break;
					    case 1: other_sprites[static_sprite].setTextureRect(IntRect(52 * int(monster_frame), 64, w, h)); break;
					    case 2: other_sprites[static_sprite].setTextureRect(IntRect(52 * int(monster_frame), 192, w, h)); break;
					    case 3: other_sprites[static_sprite].setTextureRect(IntRect(52 * int(monster_frame), 0, w, h)); break;
					}
				}
	        } else {
				float a = armor / 5;
				float aa = dmg - (dmg * (physical_resistance / 100));
				int b = static_cast<int>(aa) - static_cast<int>(a);
				if (b >= 0) {
					if (defence && defence_counter < 2) {
						defence_counter++;
					}
					else {
					    player_hp -= b;
				    }
				}
				switch (dir) {
					case 0: other_sprites[static_sprite].setTextureRect(IntRect(52 * 3, 128, w, h)); break;
					case 1: other_sprites[static_sprite].setTextureRect(IntRect(52 * 3, 64, w, h)); break;
					case 2: other_sprites[static_sprite].setTextureRect(IntRect(52 * 3, 192, w, h)); break;
					case 3: other_sprites[static_sprite].setTextureRect(IntRect(52 * 3, 0, w, h)); break;
				}
	            as_cd = as;
	        }
		} else { as_cd = as; }
    }

    void update(float time) {
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
		other_sprites[static_sprite].setPosition(x, y);
		checkBuff(time);
	}

	void moveMonster(float get_time) {
		if (move_monster_timer > 0) {
            move_monster_timer -= get_time;
        } else {
            random_generated_dir = rand() % 5;
            move_monster_timer = 1000;
        }
		float condx = pow(pow((x - player_x), 2), 0.5);
		float condy = pow(pow((y - player_y), 2), 0.5);
		if (condx <= 300 && condy <= 300 && !stun) {
			if (condx <= 52 && condy <= 64) {} //collision with player
			else {
				if (y <= player_y) {
					speed = 0.1; dir = 3;
					other_sprites[static_sprite].setTextureRect(IntRect(52 * int(monster_frame), 0, w, h));
					monster_frame += 0.005 * get_time;
					if (monster_frame > 3) {
				        monster_frame -= 3;
				    }
					update(get_time);
				}
				if (y >= player_y) {
					speed = 0.1; dir = 2;
					other_sprites[static_sprite].setTextureRect(IntRect(52 * int(monster_frame), 192, w, h));
					monster_frame += 0.005 * get_time;
					if (monster_frame > 3) {
				        monster_frame -= 3;
				    }
					update(get_time);
				}
				if (x <= player_x) {
					speed = 0.1; dir = 0;
					other_sprites[static_sprite].setTextureRect(IntRect(52 * int(monster_frame), 128, w, h));
					monster_frame += 0.005 * get_time;
					if (monster_frame > 3) {
				        monster_frame -= 3;
				    }
					update(get_time);
				}
				if (x >= player_x) {
					speed = 0.1; dir = 1;
					other_sprites[static_sprite].setTextureRect(IntRect(52 * int(monster_frame), 64, w, h));
					monster_frame += 0.005 * get_time;
					if (monster_frame > 3) {
				        monster_frame -= 3;
				    }
					update(get_time);
				}
			}
		}
		else {
			if (!stun) {
				switch (random_generated_dir) {
				    case 0: speed = 0.1; dir = 0; update(get_time); break;
				    case 1: speed = 0.1; dir = 1; update(get_time); break;
				    case 2: speed = 0.1; dir = 2; update(get_time); break;
				    case 3: speed = 0.1; dir = 3; update(get_time); break;
				}
			}
		}
	}
	void checkBuff(float globaltime) {
		stun = false;
		for (int v = 0; v < buffs.size(); v++) {
			#include "buffs.h"
			#include "timers.h"
			if (timers[v] <= 0) {
				buffs.erase(buffs.begin() + v);
		        timers.erase(timers.begin() + v);
			}
		}
	}
	void hitMonster(int local_dmg, float hittime) {
		hp -= local_dmg;
		dealt = true;
		checkBuff(hittime);
		dealt = false;
	}
	void dropMonster() {
		for (int r = 0; r < drop_chance.size(); r++) {
			int random_drop = rand() % 100;
			random_drop++;
			if (random_drop <= drop_chance[r]) {
				createItem(drop[r], x, y);
			}
		}
	}
	void giveBuff(std::string somebuff, int sometime) {
		timers.push_back(sometime);
		buffs.push_back(somebuff);
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
