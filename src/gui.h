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
    InventorySlotWeaponSprite.setPosition(view.getCenter().x - 260, view.getCenter().y - 256);
    InventorySlotShieldSprite.setPosition(view.getCenter().x + 60, view.getCenter().y - 256);
    InventorySlotChestSprite.setPosition(view.getCenter().x - 100, view.getCenter().y - 256);
    InventorySlotHelmSprite.setPosition(view.getCenter().x - 100, view.getCenter().y - 380);
    InventorySlotPantsSprite.setPosition(view.getCenter().x - 100, view.getCenter().y - 132);
    InventorySlotBootsSprite.setPosition(view.getCenter().x - 100, view.getCenter().y - 8);
    InventorySlotsSprite[24].setPosition(view.getCenter().x - 232, view.getCenter().y + 156);
    InventorySlotsSprite[25].setPosition(view.getCenter().x - 100, view.getCenter().y + 156);
    InventorySlotsSprite[26].setPosition(view.getCenter().x + 32, view.getCenter().y + 156);
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            InventorySlotsSprite[i * 4 + j].setPosition(view.getCenter().x + 232 + 112 * j, view.getCenter().y - 372 + 112 * i);
        }
    }
}
