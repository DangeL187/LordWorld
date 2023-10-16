class Defence: virtual public Initializer {
protected:
    void keyDefence(std::shared_ptr<DynamicText>& text_dynamic_shield_cd) {
        if (Keyboard::isKeyPressed(Keyboard::LShift) && attack_animation == 0 && attack_type == 0) {
            key_defence = true;
            speed *= 0.5;
            if (shield_cd == 0 && defence_timer == 0 && key_defence_go) {
                defence_timer = 1000;
                shield_cd = 5000;
                key_defence_go = false;
            } else {
                text_dynamic_shield_cd->start(500);
            }
        } else { key_defence = false; is_defence = false; key_defence_go = true;}
    }
};
