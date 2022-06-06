class Player {
private:
	std::pair<float, float> player_cords{300, 300};
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
		player_cords.first = X; player_cords.second = Y;
        NewSprite *new_player_sprite = new NewSprite("../images/hero.png");
        sprite = new_player_sprite->getSprite();
		sprite.setTextureRect(IntRect(0, 0, w, h));
	}

    void update(float time) {
		switch (dir) {
			case 0: dx = speed; dy = 0; break;
			case 1: dx = -speed; dy = 0; break;
			case 2: dx = 0; dy = -speed; break;
			case 3: dx = 0; dy = speed; break;
		}

		player_cords.first += dx*time;
		player_cords.second += dy*time;
		speed = 0;
		sprite.setPosition(player_cords.first, player_cords.second);
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
        return player_cords.first;
    }
    float getY() {
	    return player_cords.second;
    }
};
