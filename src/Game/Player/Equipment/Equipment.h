class Equipment: virtual public Initializer {
protected:
	void setEquipmentStats(auto& sprite_manager) {
	    setArmorStats(sprite_manager);
		setOtherStats();
		armor = armor_shield + armor_helmet + armor_chestplate + armor_pants + armor_boots;
		if (armor_helmet == armor_chestplate &&
			armor_chestplate == armor_pants &&
			armor_pants == armor_boots &&
			armor_boots != 0)
		{
			armor += armor_helmet;
		}
	}
	void setWeaponStats(auto& sprite_manager) {
		switch (inv_items[27].getID()) { //Weapon stats
        	case 1:
			    sprite_manager->AnimationWeaponSprite = sprite_manager->AnimationWoodenSwordSprite;
                weapon_type = 1;
                damage = 1 * strength;
                break;
            default:
		    	sprite_manager->AnimationWeaponSprite = sprite_manager->InventoryItemEmptySprite;
			    sprite_manager->AnimationWeaponSprite.setTextureRect(IntRect(0, 0, 1, 1));
                weapon_type = 1;
                damage = 0;
        }
	}
	void setArmorStats(auto& sprite_manager) {
        switch (inv_items[28].getID()) { //Shield stats
            case 2:
                sprite_manager->AnimationShieldSprite = sprite_manager->AnimationIronShieldSprite;
				sprite_manager->AnimationShieldSprite.setTextureRect(IntRect(0, 0, 1, 1));
              	armor_shield = 1;
              	break;
            default:
                sprite_manager->AnimationShieldSprite = sprite_manager->InventoryItemEmptySprite;
                sprite_manager->AnimationShieldSprite.setTextureRect(IntRect(0, 0, 1, 1));
                armor_shield = 0;
        }

        switch (inv_items[29].getID()) { //Helmet stats
            case 3:
                armor_helmet = 1;
              	break;
            default:
                armor_helmet = 0;
        }

        switch (inv_items[30].getID()) { //Chestplate stats
            case 4:
                armor_chestplate = 1;
                break;
            default:
                armor_chestplate = 0;
        }

        switch (inv_items[31].getID()) { //Pants stats
            case 5:
                armor_pants = 1;
              	break;
            default:
                armor_pants = 0;
        }

        switch (inv_items[32].getID()) { //Boots stats
            case 6:
                armor_boots = 1;
                break;
            default:
                armor_boots = 0;
        }
	}

	void setOtherStats() {
		switch (inv_items[24].getID()) { //Other1
        	case 7: //Iron Ring
                armor += 1;
                break;
        }
		switch (inv_items[25].getID()) { //Other2
            case 7: //Iron Ring
                armor += 1;
                break;
        }
		switch (inv_items[26].getID()) { //Other3
            case 7: //Iron Ring
                armor += 1;
                break;
        }
	}
};
