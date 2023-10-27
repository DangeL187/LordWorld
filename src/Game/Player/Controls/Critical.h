class Critical: virtual public Initializer {
protected:
    void keyCritical() {
        is_space_hit = (500 <= critical_timer->getTime() && critical_timer->getTime() <= 750);

        if (Keyboard::isKeyPressed(Keyboard::Space) && attack_animation == 0) {
            key_critical = true;
            critical_timer->run(1000);
        } else {
            key_critical = false;
        }
    }
};
