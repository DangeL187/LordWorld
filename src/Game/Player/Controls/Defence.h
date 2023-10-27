class Defence: virtual public Initializer {
protected:
    void keyDefence() {
        if (Keyboard::isKeyPressed(Keyboard::LShift) && attack_animation == 0 && attack_type == 0) {
            is_defence = true;
            speed *= 0.5;
        } else {
            is_defence = false;
        }
    }
};
