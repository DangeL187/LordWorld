class Inventory: virtual public Initializer {
private:
    void keyOpenInventory() {
		if (Keyboard::isKeyPressed(Keyboard::Tab)) {
			if (!is_inventory_spells_open) {
				is_inventory_open = true;
			}
		} else { is_inventory_open = false; }
	}
	void keyOpenSpells() {
		if (Keyboard::isKeyPressed(Keyboard::Tilde)) {
			if (!is_inventory_open) {
				is_inventory_spells_open = true;
			}
		} else { is_inventory_spells_open = false; }
	}
protected:
    void keysInventory() {
        keyOpenInventory();
        keyOpenSpells();
    }
};
