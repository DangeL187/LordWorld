class Enter: virtual public Initializer {
protected:
    void keyEnter() {
		if (Keyboard::isKeyPressed(Keyboard::Enter) && key_enter) {
			key_enter_go = true;
		}
		if (!Keyboard::isKeyPressed(Keyboard::Enter)) {
			key_enter = true;
			if (key_enter_go) {
				if (is_dialog) {
					dialog_phase++;
				}
				key_enter = false;
				key_enter_go = false;
			}
		}
	}
};
