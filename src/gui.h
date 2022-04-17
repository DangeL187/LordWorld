void gui() {
    std::stringstream ss; std::stringstream ss2; std::stringstream ss3;
    std::string p_lvl; std::string p_hp; std::string p_mp;
    ss<<player_lvl;
    ss>>p_lvl;
    ss2<<player_hp;
    ss2>>p_hp;
    ss3<<player_mp;
    ss3>>p_mp;
    player_stats_hp.setString(p_hp);
    player_stats_mp.setString(p_mp);
    player_stats_lvl.setString(p_lvl);
    player_stats_hp.setPosition(view.getCenter().x - 690, view.getCenter().y - 518);
    player_stats_mp.setPosition(view.getCenter().x - 690, view.getCenter().y - 450);
    player_stats_lvl.setPosition(view.getCenter().x - 690, view.getCenter().y - 382);
    text.setPosition(view.getCenter().x + 700, view.getCenter().y - 500);

    GuiBarSprite.setPosition(view.getCenter().x - 960, view.getCenter().y - 540);
    GuiInventorySprite.setPosition(view.getCenter().x - 300, view.getCenter().y - 400);

    InventoryItemWeaponSprite.setPosition(view.getCenter().x - 260, view.getCenter().y - 256);
    InventoryItemShieldSprite.setPosition(view.getCenter().x + 60, view.getCenter().y - 256);
    InventoryItemChestSprite.setPosition(view.getCenter().x - 100, view.getCenter().y - 256);
    InventoryItemHelmSprite.setPosition(view.getCenter().x - 100, view.getCenter().y - 380);
    InventoryItemPantsSprite.setPosition(view.getCenter().x - 100, view.getCenter().y - 132);
    InventoryItemBootsSprite.setPosition(view.getCenter().x - 100, view.getCenter().y - 8);
    InventoryItemsSprite[24].setPosition(view.getCenter().x - 232, view.getCenter().y + 156);
    InventoryItemsSprite[25].setPosition(view.getCenter().x - 100, view.getCenter().y + 156);
    InventoryItemsSprite[26].setPosition(view.getCenter().x + 32, view.getCenter().y + 156);
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            InventoryItemsSprite[i * 4 + j].setPosition(view.getCenter().x + 261 + 112 * j, view.getCenter().y - 343 + 112 * i);
        }
    }
}
