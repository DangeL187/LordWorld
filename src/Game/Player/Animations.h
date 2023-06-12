class Animations {
protected:
    void animations(auto& game) {
        attackAnimation(game);
        shieldAnimation(game);
        dashAnimation(game);
    }

    void attackAnimation(auto& game) {
        auto& pam = game.player->attack_animation;
        auto& pw = game.player->w;
        auto& ph = game.player->h;
        auto& pdir = game.player->dir;
        if (pam == 5) {
            auto cf = int(game.player->current_frame); if (cf == 3) { cf = 1; }
			game.player->sprite.setTextureRect(IntRect(pw * cf + cf + 1, ph * pdir + pdir + 1, pw, ph));
            game.AnimationWeaponSprite.setTextureRect(IntRect(0, 0, 1, 1));
            game.AnimationWeaponSprite.setPosition(game.player->getX() - 20, game.player->getY());
            pam = 0;
        } else if (game.player->attack_animation != 0)  {
            int n = ((pam % 2) - 1) * ((pam % 2) - 1) + 3;
            game.player->sprite.setTextureRect(IntRect(pw * n + n + 1, ph * pdir + pdir + 1, pw, ph));
            game.AnimationWeaponSprite.setTextureRect(IntRect(80 * (pam - 1) + pam, 76 * pdir + pdir + 1, 80, 76)); //80, 76 - width, height
            game.AnimationWeaponSprite.setPosition(game.player->getX() - 16, game.player->getY() - 4);
        }
    }

    void shieldAnimation(auto& game) {
        auto& pdir = game.player->dir;
        int n = pdir / 2 * (pdir - 1);
        game.AnimationShieldSprite.setTextureRect(IntRect(47 * n + n + 1, 1, 47, 28));
        game.AnimationShieldSprite.setPosition(game.player->getX(), game.player->getY() + 30);
    }

    void dashAnimation(auto& game) {
        auto& pw = game.player->w;
        auto& ph = game.player->h;
        auto& pdir = game.player->dir;
        if (game.player->dash_timer > 0) {
            game.player->sprite.setTextureRect(IntRect(pw * 5 + 6, ph * pdir + pdir + 1, pw, ph));
            game.AnimationDashSprite.setTextureRect(IntRect(94 * pdir + pdir + 1, 1, 94, 108));
            game.AnimationDashSprite.setPosition(game.player->getX() - 26, game.player->getY() - 22);
        }
    }
};