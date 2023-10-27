class Dash: virtual public Initializer {
protected:
    void keyDash() {
		if (dash_timer->isRunning()) {
			speed *= 10;
		}
		if (key_critical && Keyboard::isKeyPressed(Keyboard::LShift) && std::accumulate(is_movement_keys.begin(), is_movement_keys.end(), 0) && dash_cd->isOver()) {
			dash_timer->run(200);
			dash_cd->run(5000);
		}
	}
};
