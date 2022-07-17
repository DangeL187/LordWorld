class Equipment {
protected:
	int armor = 0;
	int armor_shield = 0;
	int armor_helmet = 0;
	int armor_chestplate = 0;
	int armor_pants = 0;
	int armor_boots = 0;
	int damage = 1;
	int strength = 1;
	int weapon_type = 1; //1-circle attack; 2-straight; 3-conus; 4-front-back line;
	int physical_resistance = 1;
	int magic_ice = 1;

	void setEquipmentStats(auto& inv_items) {
		setWeaponStats(inv_items);
		setArmorStats(inv_items);
		armor = armor_shield + armor_helmet + armor_chestplate + armor_pants + armor_boots;
		setOtherStats(inv_items);
		if (armor_helmet == armor_chestplate &&
			armor_chestplate == armor_pants &&
			armor_pants == armor_boots &&
			armor_boots != 0) {
			armor += armor_helmet;
		}
	}
	void setWeaponStats(auto& inv_items) {
		switch (inv_items[27]) { //Weapon stats
            case 1:
                weapon_type = 1;
                damage = 2 * strength;
                break;
            default:
                weapon_type = 1;
                damage = 1 * strength;
        }
	}
	void setArmorStats(auto& inv_items) {
        switch (inv_items[28]) { //Shield stats
            case 3:
                //EquipedShieldSprite = AnimationIronShieldSprite;
                armor_shield = 1;
                break;
            default:
                //EquipedShieldSprite = InventoryItemEmptySprite;
                //EquipedShieldSprite.setTextureRect(IntRect(0, 0, 1, 1));
                armor_shield = 0;
        }

        switch (inv_items[29]) { //Helmet stats
            case 4:
                armor_helmet = 1;
                break;
            default:
                armor_helmet = 0;
        }

        switch (inv_items[30]) { //Chestplate stats
            case 2:
                armor_chestplate = 1;
                break;
            default:
                armor_chestplate = 0;
        }

        switch (inv_items[31]) { //Pants stats
            case 5:
                armor_pants = 1;
                break;
            default:
                armor_pants = 0;
        }

        switch (inv_items[32]) { //Boots stats
            case 6:
                armor_boots = 1;
                break;
            default:
                armor_boots = 0;
        }
    }

	void setOtherStats(auto& inv_items) {
		switch (inv_items[24]) { //Other1
            case 7: //Iron Ring
                armor += 1;
                break;
        }
		switch (inv_items[25]) { //Other2
            case 7: //Iron Ring
                armor += 1;
                break;
        }
		switch (inv_items[26]) { //Other3
            case 7: //Iron Ring
                armor += 1;
                break;
        }
	}
};
