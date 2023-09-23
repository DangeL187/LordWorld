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
	void setEquipmentStats(auto& game, auto& inv_items) {
	    setArmorStats(game, inv_items);
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
	void setWeaponStats(auto& game, auto& inv_items) {
		switch (inv_items[27]) { //Weapon stats
        	case 1:
			    game.renderer->AnimationWeaponSprite = game.renderer->AnimationWoodenSwordSprite;
                weapon_type = 1;
                damage = 1 * strength;
                break;
            default:
		    	game.renderer->AnimationWeaponSprite = game.renderer->InventoryItemEmptySprite;
			    game.renderer->AnimationWeaponSprite.setTextureRect(IntRect(0, 0, 1, 1));
                weapon_type = 1;
                damage = 0 * strength;
        }
	}
	void setArmorStats(auto& game, auto& inv_items) {
        switch (inv_items[28]) { //Shield stats
            case 2:
                game.renderer->AnimationShieldSprite = game.renderer->AnimationIronShieldSprite;
				game.renderer->AnimationShieldSprite.setTextureRect(IntRect(0, 0, 1, 1));
              	armor_shield = 1;
              	break;
            default:
                game.renderer->AnimationShieldSprite = game.renderer->InventoryItemEmptySprite;
                game.renderer->AnimationShieldSprite.setTextureRect(IntRect(0, 0, 1, 1));
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
    bool checkWeaponsRange(auto& game, float get_x, float get_y) {
		switch (weapon_type) {
            case 1: //Wooden Sword
				float condxm = get_x/1 - melee_weapon*64;
	        	float condxp = get_x/1 + melee_weapon*64;
		        float condyp = get_y/1 + melee_weapon*64;
				float condym = get_y/1 - melee_weapon*64;
	       		return (condxm <= game.player->getX() && game.player->getX() <= condxp
					&& condym <= game.player->getY() && game.player->getY() <= condyp);
                break;
        }
		return false;
	}
};
