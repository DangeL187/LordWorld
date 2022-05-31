void animations(Player& p, float time1) {
    if (animation_timer > 0) {
        animation_timer -= time1;
    } else {
        animation_timer = 150;
        if (attack_animation == 1) {
            if (p.dir == 0) { //D
                AnimationWoodenSwordSprite.setTextureRect(IntRect(1, 131, 72, 64));
                AnimationWoodenSwordSprite.setPosition(player_x, player_y);
                herosprite.setTextureRect(IntRect(52 * 2, 64 * 2, 50, 62));
            }
            if (p.dir == 1) { //A
                AnimationWoodenSwordSprite.setTextureRect(IntRect(1, 66, 72, 64));
                AnimationWoodenSwordSprite.setPosition(player_x - 20, player_y);
                herosprite.setTextureRect(IntRect(0, 64, 50, 62));
            }
            if (p.dir == 2) { //W
                AnimationWoodenSwordSprite.setTextureRect(IntRect(1, 196, 72, 64));
                AnimationWoodenSwordSprite.setPosition(player_x - 10, player_y - 4);
                herosprite.setTextureRect(IntRect(52 * 3, 64 * 3, 50, 62));
            }
            if (p.dir == 3) { //S
                AnimationWoodenSwordSprite.setTextureRect(IntRect(1, 1, 72, 64));
                AnimationWoodenSwordSprite.setPosition(player_x - 20, player_y);
                herosprite.setTextureRect(IntRect(52 * 3, 0, 50, 62));
            }
            attack_animation++;
        }
        else if (attack_animation == 2) {
            if (p.dir == 0) {
                AnimationWoodenSwordSprite.setTextureRect(IntRect(74, 131, 72, 64));
                AnimationWoodenSwordSprite.setPosition(player_x, player_y);
                herosprite.setTextureRect(IntRect(52 * 3, 64 * 2, 50, 62));
            }
            if (p.dir == 1) {
                AnimationWoodenSwordSprite.setTextureRect(IntRect(74, 66, 72, 64));
                AnimationWoodenSwordSprite.setPosition(player_x - 20, player_y);
                herosprite.setTextureRect(IntRect(52 * 3, 64, 50, 62));
            }
            if (p.dir == 2) {
                AnimationWoodenSwordSprite.setTextureRect(IntRect(74, 196, 72, 64));
                AnimationWoodenSwordSprite.setPosition(player_x, player_y - 5);
                herosprite.setTextureRect(IntRect(52, 64 * 3, 50, 62));
            }
            if (p.dir == 3) {
                AnimationWoodenSwordSprite.setTextureRect(IntRect(74, 1, 72, 64));
                AnimationWoodenSwordSprite.setPosition(player_x - 20, player_y + 20);
                herosprite.setTextureRect(IntRect(52 * 4, 0, 50, 62));
            }
            attack_animation++;
        }
        else if (attack_animation == 3) {
            if (p.dir == 0) {
                AnimationWoodenSwordSprite.setTextureRect(IntRect(147, 131, 72, 64));
                AnimationWoodenSwordSprite.setPosition(player_x, player_y + 30);
                herosprite.setTextureRect(IntRect(52 * 4, 64 * 2, 50, 62));
            }
            if (p.dir == 1) {
                AnimationWoodenSwordSprite.setTextureRect(IntRect(147, 66, 72, 64));
                AnimationWoodenSwordSprite.setPosition(player_x - 20, player_y + 30);
                herosprite.setTextureRect(IntRect(52 * 4, 64, 50, 62));
            }
            if (p.dir == 2) {
                AnimationWoodenSwordSprite.setTextureRect(IntRect(147, 196, 72, 64));
                AnimationWoodenSwordSprite.setPosition(player_x - 6, player_y + 2);
                herosprite.setTextureRect(IntRect(52 * 4, 64 * 3, 50, 62));
            }
            if (p.dir == 3) {
                AnimationWoodenSwordSprite.setTextureRect(IntRect(147, 1, 72, 64));
                AnimationWoodenSwordSprite.setPosition(player_x, player_y + 20);
                herosprite.setTextureRect(IntRect(52 * 3, 0, 50, 62));
            }
            attack_animation++;
        }
        else if (attack_animation == 4) {
            if (p.dir == 0) {
                AnimationWoodenSwordSprite.setTextureRect(IntRect(220, 131, 72, 64));
                AnimationWoodenSwordSprite.setPosition(player_x - 10, player_y + 27);
                herosprite.setTextureRect(IntRect(0, 128, 50, 62));
            }
            if (p.dir == 1) {
                AnimationWoodenSwordSprite.setTextureRect(IntRect(220, 66, 72, 64));
                AnimationWoodenSwordSprite.setPosition(player_x - 10, player_y + 27);
                herosprite.setTextureRect(IntRect(0, 64, 50, 62));
            }
            if (p.dir == 3) {
                AnimationWoodenSwordSprite.setTextureRect(IntRect(220, 1, 72, 64));
                AnimationWoodenSwordSprite.setPosition(player_x, player_y);
                herosprite.setTextureRect(IntRect(52 * 4, 0, 50, 62));
            }
            attack_animation++;
        }
        else if (attack_animation == 5) {
            if (p.dir == 0) {
                AnimationWoodenSwordSprite.setTextureRect(IntRect(1, 1, 72, 64));
                herosprite.setTextureRect(IntRect(52 * int(current_frame), 128, 50, 62));
            }
            if (p.dir == 1) {
                AnimationWoodenSwordSprite.setTextureRect(IntRect(1, 66, 72, 64));
                herosprite.setTextureRect(IntRect(52 * int(current_frame), 64, 50, 62));
            }
            if (p.dir == 2) {
                AnimationWoodenSwordSprite.setTextureRect(IntRect(1, 1, 72, 64));
                herosprite.setTextureRect(IntRect(52 * int(current_frame), 192, 50, 62));
            }
            if (p.dir == 3) {
                AnimationWoodenSwordSprite.setTextureRect(IntRect(1, 1, 72, 64));
                herosprite.setTextureRect(IntRect(52 * int(current_frame), 0, 50, 62));
            }
            AnimationWoodenSwordSprite.setPosition(player_x - 20, player_y);
            attack_animation = 0;
        }
    }
}
