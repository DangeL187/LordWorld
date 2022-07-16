class PlayerVars {
protected:
    Sprite sprite;
    int attack_animation = 0;
	int dir = 0;
    int range = 1; //*64
	int inv_items[33]; //items inventory
	int inv_types[24]; //item types invenory
    float p_cords[2] {300, 300};
    float w, h, dx, dy;
    float current_frame = 0;
    float speed = 0;
    float space_timer = 0;
	bool defence = false;
    bool is_inventory_open = false;
    bool is_spells_inventory_open = false;
};
