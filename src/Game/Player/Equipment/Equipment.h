class Equipment: virtual public Initializer {
protected:
	void updateEquipmentStats() {
		attack_speed = 1000 - agility * 10;
		armor = strength;
		damage = agility;
		magic_resistance = intelligence;
		for (int i = 24; i <= 32; i++) {
			armor += inv_items[i].getArmor();
			damage += inv_items[i].getDamage();
		}
	}
};
