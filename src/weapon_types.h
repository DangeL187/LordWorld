bool checkWeaponsRange(float x, float y) {
    if (weapon == "Wooden Sword") {
        damage = 1;
        if (x/1 - range*64 <= player_x && player_x <= x/1 + range*64 && y/1 - range*64 <= player_y && player_y <= y/1 + range*64) {
            return true;
        }
        else {
            return false;
        }
    }
}
