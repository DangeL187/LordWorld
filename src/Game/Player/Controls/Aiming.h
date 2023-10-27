class Aiming: virtual public Initializer {
private:
    std::vector<bool> is_keys {false, false, false, false, false, false, false, false, false};
    std::vector<bool> is_keys_kid {false, false, false, false, false, false, false, false, false};

    std::vector<Keyboard::Key> keys {
        Keyboard::Num1,
        Keyboard::Num2,
        Keyboard::Num3,
        Keyboard::Num4,
        Keyboard::Num5,
        Keyboard::Num6,
        Keyboard::Num7,
        Keyboard::Num8,
        Keyboard::Num9
    };
protected:
    void keysAiming() {
        for (int i = 0; i < 9; i++) {
            is_keys[i] = isOnlyOneIsTrue(is_keys, keys, i);
            if (is_keys[i]) {
                is_keys_kid[i] = is_keys[i];
            }

            if (!is_keys[i] && is_keys_kid[i]) {
                //spell_id = hotbar_spells[i];
                spell_slot = i;
                is_aiming = true;
                is_keys_kid[i] = false;
            }
        }
	}
};
