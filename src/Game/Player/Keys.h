class Keys {
private:
	bool key_a = false, key_d = false, key_w = false, key_s = false;
	bool key_e = false, key_g = false;
	bool key_m1 = false, key_m2 = false;
	bool key_1 = false, key_2 = false, key_3 = false, key_4 = false;
	bool key_5 = false, key_6 = false, key_7 = false, key_8 = false, key_9 = false;
	bool key_shift = false, key_space = false;
	bool is_info = false;
	bool break4items = false;
	float current_frame = 0;
protected:
	void moveCurrentFrame(auto &time) {
        current_frame += 0.005 * time;
        if (current_frame > 3) {
            current_frame -= 3;
        }
    }
	void keysMove(auto &time, auto &attack_animation, auto &speed, auto &dir, auto &sprite) {
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
	void keys(auto &time, auto &attack_animation, auto &speed, auto &dir, auto &sprite) {
		keysMove(time, attack_animation, speed, dir, sprite);
	}
};
