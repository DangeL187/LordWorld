class Dash: virtual public Initializer {
protected:
    void keyDash(auto& time) {
		if (dash_timer > 0) {
			dash_timer -= time;
			speed *= 10;
		}
		if (key_critical && key_defence && std::accumulate(is_movement_keys.begin(), is_movement_keys.end(), 0) && dash_cd <= 0) {
			dash_timer = 200;
			dash_cd = 5000;
		}
	}
};
