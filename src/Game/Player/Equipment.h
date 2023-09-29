class Equipment {
public:
	int armor = 0;
	int armor_shield = 0;
	int armor_helmet = 0;
	int armor_chestplate = 0;
	int armor_pants = 0;
	int armor_boots = 0;
	int damage = 0;
	int strength = 1;
    int magic = 1;
    int critical_chance = 1; //%
    int magic_resistance = 1;
    int physical_resistance = 1;
    int magic_ice = 1;
    int magic_fire = 1;
    int magic_earth = 1;
    int magic_wind = 1;
    int magic_dark = 1;
    int magic_light = 1;
    int melee_weapon = 1; //*64
    int range_weapon = 1; //*64
	int weapon_type = 1; //1-circle attack; 2-straight; 3-conus; 4-vertical line;
protected:
	void setEquipmentStats(auto& sprite_manager, auto& inv_items) {
	    setArmorStats(sprite_manager, inv_items);
		armor = armor_shield + armor_helmet + armor_chestplate + armor_pants + armor_boots;
		setOtherStats(inv_items);
		if (armor_helmet == armor_chestplate &&
			armor_chestplate == armor_pants &&
			armor_pants == armor_boots &&
			armor_boots != 0)
		{
				armor += armor_helmet;
		}
	}
	void setWeaponStats(auto& sprite_manager, auto& inv_items) {
		switch (inv_items[27]) { //Weapon stats
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
	void setArmorStats(auto& sprite_manager, auto& inv_items) {
        switch (inv_items[28]) { //Shield stats
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

        switch (inv_items[29]) { //Helmet stats
            case 3:
                armor_helmet = 1;
              	break;
            default:
                armor_helmet = 0;
        }

        switch (inv_items[30]) { //Chestplate stats
            case 4:
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

public:
    bool checkWeaponsRange(auto& game, float mx, float my) {
		switch (weapon_type) {
            case 1: //Wooden Sword
				float condxm = mx/1 - melee_weapon*64;
	        	float condxp = mx/1 + melee_weapon*64;
		        float condyp = my/1 + melee_weapon*64;
				float condym = my/1 - melee_weapon*64;
				float px = game.player->getX();
				float py = game.player->getY();
	       		return (condxm <= px && px <= condxp && condym <= py && py <= condyp);
                break;
        }
		return false;
	}
};
