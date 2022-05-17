void setWeaponStats() { //TODO: unite in one function
    if (inv_items[27] == 1) { //Wooden Sword
        weapon_type = 1;
        player_damage = 2 * strength; //gives +2 attack damage
    }
    else {
        weapon_type = 1;
        player_damage = 1 * strength; //nothing gives +1 attack damage
    }
}
void setShieldStats() {
    if (inv_items[28] == 3) { //Iron Shield
        EquipedShieldSprite = AnimationIronShieldSprite;
        armor_shield = 1; //gives +1 armor
    }
    else {
        EquipedShieldSprite = InventoryItemEmptySprite;
        EquipedShieldSprite.setTextureRect(IntRect(0, 0, 1, 1));
        armor_shield = 0; //nothing gives +1 armor
    }
}
void setHelmetStats() {
    if (inv_items[29] == 4) { //Iron Helmet
        armor_helmet = 1; //gives +1 armor
    }
    else {
        armor_helmet = 0; //nothing gives +1 armor
    }
}
void setChestplateStats() {
    if (inv_items[30] == 2) { //Iron Chestplate
        armor_chestplate = 1; //gives +1 armor
    }
    else {
        armor_chestplate = 0; //nothing gives +1 armor
    }
}
void setPantsStats() {
    if (inv_items[31] == 5) { //Iron Pants
        armor_pants = 1; //gives +1 armor
    }
    else {
        armor_pants = 0; //nothing gives +1 armor
    }
}
void setBootsStats() {
    if (inv_items[32] == 6) { //Iron Pants
        armor_boots = 1; //gives +1 armor
    }
    else {
        armor_boots = 0; //nothing gives +1 armor
    }
}
void setOtherStats() {
    if (inv_items[24] == 7) { //Iron Ring
        armor += 1; //gives +1 armor
    }
    if (inv_items[25] == 7) { //Iron Ring
        armor += 1; //gives +1 armor
    }
    if (inv_items[26] == 7) { //Iron Ring
        armor += 1; //gives +1 armor
    }
}
