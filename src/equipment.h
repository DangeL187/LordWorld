void setArmorStats()
{
    // Weapon stats
    switch (inv_items[27]) {
        case 1:
            weapon_type = 1;
            player_damage = 2 * strength;
            break;
        default:
            weapon_type = 1;
            player_damage = 1 * strength;
    }

    // Shield stats
    switch (inv_items[28]) {
        case 3:
            EquipedShieldSprite = AnimationIronShieldSprite;
            armor_shield = 1;
            break;
        default:
            EquipedShieldSprite = InventoryItemEmptySprite;
            EquipedShieldSprite.setTextureRect(IntRect(0, 0, 1, 1));
            armor_shield = 0;
    }

    // Helmet stats
    switch (inv_items[29]) {
        case 4:
            armor_helmet = 1;
            break;
        default:
            armor_helmet = 0;
    }

    // Chestplate stats
    switch (inv_items[30]) {
        case 2:
            armor_chestplate = 1;
            break;
        default:
            armor_chestplate = 0;
    }

    // Pants stats
    switch (inv_items[31]) {
        case 5:
            armor_pants = 1;
            break;
        default:
            armor_pants = 0;
    }

    // Boots stats
    switch (inv_items[32]) {
        case 6:
            armor_boots = 1;
            break;
        default:
            armor_boots = 0;
    }
}

void setOtherStats() {
    if (inv_items[24] == 7) { //Iron Ring
        armor += 1;
    }
    if (inv_items[25] == 7) { //Iron Ring
        armor += 1;
    }
    if (inv_items[26] == 7) { //Iron Ring
        armor += 1;
    }
}
