class Monster {
protected:
	float x, y;
	float w, h, dx, dy, speed;
    unsigned int id;
    int damage, hp, mp, lvl, xp;
	int dir = 0;
	int random_generated_dir = 0;
	float attack_speed;
	float monster_frame;
    float move_monster_timer = 0;
	std::string name;
    std::vector<int> drop;
	std::vector<int> drop_chance;
	std::shared_ptr<BuffManager> buff_manager;
	std::shared_ptr<Timer> attack_speed_timer;
	bool dealt = false;
	bool stun = false;
	Sprite sprite;
public:
	Monster(float x_, float y_, float w_, float h_, unsigned int id_) {
		buff_manager = std::make_shared<BuffManager>();
		attack_speed_timer = std::make_shared<Timer>();
		dx=0; dy=0; speed=0;
		x = x_; y = y_;
		w = w_; h = h_;
		id = id_;
	}

	void interactionWithMap(float time, auto& game, auto& player) {
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
		float px = player->getX() - 3;
		float py = player->getY() - 3;
		float pw = player->getWidth() + 6;
		float ph = player->getHeight() + 6;
		if (isCollision(x, y, w, h, px, py, pw, ph) && !stun) {
			if (attack_speed_timer->isRunning()) {
	            int frame = int(monster_frame);
				if (attack_speed_timer->getTime() <= 500) {
					frame = 3;
				}
				switch (dir) {
					case 0: sprite.setTextureRect(IntRect(52 * frame, 128, w, h)); break;
					case 1: sprite.setTextureRect(IntRect(52 * frame, 64, w, h)); break;
					case 2: sprite.setTextureRect(IntRect(52 * frame, 192, w, h)); break;
					case 3: sprite.setTextureRect(IntRect(52 * frame, 0, w, h)); break;
				}
	        } else {
				int dmg = damage - player->armor / 5;
				if (dmg > 0 && !player->is_defence) {
					player->hp -= dmg;
	                game.renderer->interface_manager->interface_dynamic_text.createDynamicText(18, 500, std::to_string(0-dmg), px + int(pw / 2), py + 20, true);
				}
	            attack_speed_timer->run(attack_speed);
	        }
		} else {
			attack_speed_timer->run(attack_speed);
		}
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
		sprite.setPosition(x, y);
		stun = false;
		buff_manager->update(*this);
	}

	void moveMonster(auto& time, auto& game, auto& player) { //TODO: UPDATE!
		if (move_monster_timer > 0) {
            move_monster_timer -= time;
        } else {
            random_generated_dir = rand() % 5;
            move_monster_timer = 1000;
        }
		float px = player->getX();
		float py = player->getY();
		float pw = player->getWidth();
		float ph = player->getHeight();
		float monster_center_x = x + w / 2;
		float monster_center_y = y + h / 2;
		float player_center_x = px + pw / 2;
		float player_center_y = py + ph / 2;
		if (getDistanceBetween(monster_center_x, monster_center_y, player_center_x, player_center_y) <= 300 && !stun) {
			if (!isCollision(x, y, w, h, px, py, pw, ph)) {
				if (y <= player->getY()) {
					speed = 0.1; dir = 3;
					sprite.setTextureRect(IntRect(52 * int(monster_frame), 0, w, h));
					monster_frame += 0.005 * time;
					if (monster_frame > 3) {
				        monster_frame -= 3;
				    }
					update(time, game, player);
				}
				if (y >= player->getY()) {
					speed = 0.1; dir = 2;
					sprite.setTextureRect(IntRect(52 * int(monster_frame), 192, w, h));
					monster_frame += 0.005 * time;
					if (monster_frame > 3) {
				        monster_frame -= 3;
				    }
					update(time, game, player);
				}
				if (x <= player->getX()) {
					speed = 0.1; dir = 0;
					sprite.setTextureRect(IntRect(52 * int(monster_frame), 128, w, h));
					monster_frame += 0.005 * time;
					if (monster_frame > 3) {
				        monster_frame -= 3;
				    }
					update(time, game, player);
				}
				if (x >= player->getX()) {
					speed = 0.1; dir = 1;
					sprite.setTextureRect(IntRect(52 * int(monster_frame), 64, w, h));
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
	void giveBuff(int id, float duration) {
		buff_manager->giveBuff(id, duration);
	}
	void hitMonster(int dmg, bool update_buffs=true) {
		hp -= dmg;
		if (update_buffs) {
			dealt = true;
			buff_manager->update(*this);
			dealt = false;
		}
	}
	void stunMonster(bool enable) {
		if (enable) {
			stun = true;
		} else {
			stun = false;
		}
	}
	void dropMonster(auto& game) {
		for (int r = 0; r < drop_chance.size(); r++) {
			int random_drop = rand() % 100;
			random_drop++;
			if (random_drop <= drop_chance[r]) {
				game.entity_manager->createItem(x, y, drop[r]);
			}
		}
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
	void setHP(int hp_) {
		hp = hp_;
	}
	Sprite getSprite() {
		return sprite;
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
	int& getHP(bool get_reference) {
        return hp;
    }
	int getMP() {
		return mp;
	}
	int getLVL() {
		return lvl;
	}
	bool isDealt() {
		return dealt;
	}
	std::string getName() {
		return name;
	}
};
