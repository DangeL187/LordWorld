class Escape: virtual public Initializer {
protected:
    void keyEscape() {
		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			if (is_dialog) {
				dialog_phase = 0;
				is_dialog = false;
			}
		}
	}
};
