class Animations: virtual public Initializer {
private:
    void attackAnimation() {
        if (animation_timer->isOver()) {
            if (attack_animation != 0 && attack_animation < 5) {
                attack_animation++;
            } else {
                attack_animation = 0;
            }
            animation_timer->run(100);
        }

        auto& am = attack_animation;
        if (am == 5) {
            auto cf = int(current_frame); if (cf == 3) { cf = 1; }
			sprite.setTextureRect(IntRect(w * cf + cf + 1, h * dir + dir + 1, w, h));
            inv_items[27].getAnimationSprite().setTextureRect(IntRect(0, 0, 1, 1));
            inv_items[27].getAnimationSprite().setPosition(x - 20, y);
            am = 0;
        } else if (am != 0)  {
            int n = ((am % 2) - 1) * ((am % 2) - 1) + 3;
            sprite.setTextureRect(IntRect(w * n + n + 1, h * dir + dir + 1, w, h));
            inv_items[27].getAnimationSprite().setTextureRect(IntRect(80 * (am - 1) + am, 76 * dir + dir + 1, 80, 76)); //80, 76 - width, height
            inv_items[27].getAnimationSprite().setPosition(x - 16, y - 4);
        }
    }

    void shieldAnimation() {
        int n = dir / 2 * (dir - 1);
        inv_items[28].getAnimationSprite().setTextureRect(IntRect(47 * n + n + 1, 1, 47, 28));
        inv_items[28].getAnimationSprite().setPosition(x, y + 30);
    }

    void dashAnimation(auto& game) {
        if (dash_timer->isRunning()) {
            sprite.setTextureRect(IntRect(w * 5 + 6, h * dir + dir + 1, w, h));
            AnimationDashSprite.setTextureRect(IntRect(94 * dir + dir + 1, 1, 94, 108));
            AnimationDashSprite.setPosition(x - 26, y - 22);
            dash_stop = true;
        } else if (dash_stop) {
            auto cf = int(current_frame); if (cf == 3) { cf = 1; }
			sprite.setTextureRect(IntRect(w * cf + cf + 1, h * dir + dir + 1, w, h));
            dash_stop = false;
        }
    }
protected:
    bool dash_stop = false;

    void animations(auto& game) {
        attackAnimation();
        shieldAnimation();
        dashAnimation(game);
    }
};
