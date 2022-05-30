void gainLVL() {
    if (player_xp >= player_lvl * 100) {
        player_xp -= player_lvl * 100;
        player_lvl++;
    }
}