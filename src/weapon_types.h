bool checkWeaponsRange(float get_x, float get_y) {
    if (weapon == "Wooden Sword") {
        damage = 1;
        float condxm = get_x/1 - range*64;
        float condxp = get_x/1 + range*64;
        float condym = get_y/1 - range*64;
        float condyp = get_y/1 + range*64;
        return (condxm <= player_x && player_x <= condxp && condym <= player_y && player_y <= condyp);
    }
}
