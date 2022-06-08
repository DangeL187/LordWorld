class Player {
private:
	std::pair<float, float> p_pos{300, 300};
    float w, h, dx, dy, speed;
    float current_frame = 0;
    int attack_animation = 0;
    int dir = 0;
    Sprite sprite;

	bool key_a = false, key_d = false, key_w = false, key_s = false;
	bool key_e = false, key_g = false;
	bool key_m1 = false, key_m2 = false;
	bool key_1 = false, key_2 = false, key_3 = false, key_4 = false;
	bool key_5 = false, key_6 = false, key_7 = false, key_8 = false, key_9 = false;
	bool key_shift = false, key_space = false;
	bool is_info = false;
	bool break4items = false;
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

    void update(float time, auto &map_manager, auto &v_NPC) {
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
        keys(time);
	}

    void moveCurrentFrame(float time) {
        current_frame += 0.005 * time;
        if (current_frame > 3) {
            current_frame -= 3;
        }
    }
	void keysMove(auto time) {
		if (Keyboard::isKeyPressed(Keyboard::D) && !key_a && !key_w && !key_s && attack_animation == 0) {
			key_d = true;
			speed = 0.15;
			dir = 0;
			sprite.setTextureRect(IntRect(52 * int(current_frame), 128, 50, 62));
		} else { key_d = false; }
		if (Keyboard::isKeyPressed(Keyboard::A) && !key_d && !key_w && !key_s && attack_animation == 0) {
			key_a = true;
			speed = 0.15;
			dir = 1;
			sprite.setTextureRect(IntRect(52 * int(current_frame), 64, 50, 62));
		} else { key_a = false; }
		if (Keyboard::isKeyPressed(Keyboard::W) && !key_d && !key_a && !key_s && attack_animation == 0) {
			key_w = true;
			speed = 0.15;
			dir = 2;
			sprite.setTextureRect(IntRect(52 * int(current_frame), 192, 50, 62));
		} else { key_w = false; }
		if (Keyboard::isKeyPressed(Keyboard::S) && !key_d && !key_w && !key_a && attack_animation == 0) {
			key_s = true;
			speed = 0.15;
			dir = 3;
			sprite.setTextureRect(IntRect(52 * int(current_frame), 0, 50, 62));
		} else { key_s = false; }
        moveCurrentFrame(time);
	}
	void keys(auto time) {
		keysMove(time);
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
