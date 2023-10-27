class Movement: virtual public Initializer {
private:
    std::vector<Keyboard::Key> keys {
        Keyboard::D,
        Keyboard::A,
        Keyboard::W,
        Keyboard::S,
    };

    void moveCurrentFrame(auto& time) {
        current_frame += 0.005 * time;
        if (current_frame >= 4) {
            current_frame = 0;
        }
    }
protected:
    void keysMovement(auto& time) {
        for (int i = 0; i < 4; i++) {
            is_movement_keys[i] = isOnlyOneIsTrue(is_movement_keys, keys, i);
            if (is_movement_keys[i]) {
                dir = i;
            }
        }
		if (std::accumulate(is_movement_keys.begin(), is_movement_keys.end(), 0)) {
			speed = basic_speed;
			int cf = current_frame; if (cf == 3) { cf = 1; }
			sprite.setTextureRect(IntRect(w * cf + cf + 1, h * dir + dir + 1, w, h));
		}
        moveCurrentFrame(time);
	}
};
