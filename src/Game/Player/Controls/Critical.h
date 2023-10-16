class Critical: virtual public Initializer {
protected:
    void keyCritical() {
        if (Keyboard::isKeyPressed(Keyboard::Space) && attack_animation == 0) {
            key_critical = true;
            critical_timer = 1000;
        } else { key_critical = false; }
    }
};
