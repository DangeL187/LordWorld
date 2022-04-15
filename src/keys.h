bool key_a = false, key_d = false, key_w = false, key_s = false;
bool key_e = false, key_g = false;
bool key_m1 = false, key_m2 = false;
bool key_1 = false, key_2 = false, key_3 = false, key_4 = false;
bool key_i = false;
bool nums = false;
bool tempstop = true;
bool tempstop2 = true;
bool break4items = false;

if (Keyboard::isKeyPressed(Keyboard::D) && !key_a && !key_w && !key_s) {
	key_d = true;
	player.speed = 0.15;
	player.dir = 0;
	herosprite.setTextureRect(IntRect(52 * int(current_frame), 128, 50, 62));
	getPlayerCoordinateForView(player.getPlayerCoordinateX(), player.getPlayerCoordinateY());
	moveCurrentFrame(time);
} else { key_d = false; }
if (Keyboard::isKeyPressed(Keyboard::A) && !key_d && !key_w && !key_s) {
	key_a = true;
	player.speed = 0.15;
	player.dir = 1;
	herosprite.setTextureRect(IntRect(52 * int(current_frame), 64, 50, 62));
	getPlayerCoordinateForView(player.getPlayerCoordinateX(), player.getPlayerCoordinateY());
	moveCurrentFrame(time);
} else { key_a = false; }
if (Keyboard::isKeyPressed(Keyboard::W) && !key_d && !key_a && !key_s) {
	key_w = true;
	player.speed = 0.15;
	player.dir = 2;
	herosprite.setTextureRect(IntRect(52 * int(current_frame), 192, 50, 62));
	getPlayerCoordinateForView(player.getPlayerCoordinateX(), player.getPlayerCoordinateY());
	moveCurrentFrame(time);
} else { key_w = false; }
if (Keyboard::isKeyPressed(Keyboard::S) && !key_d && !key_w && !key_a) {
	key_s = true;
	player.speed = 0.15;
	player.dir = 3;
	herosprite.setTextureRect(IntRect(52 * int(current_frame), 0, 50, 62));
	getPlayerCoordinateForView(player.getPlayerCoordinateX(), player.getPlayerCoordinateY());
	moveCurrentFrame(time);
} else { key_s = false; }
if (Keyboard::isKeyPressed(Keyboard::LShift)) {
	player.speed = 0.3;
	getPlayerCoordinateForView(player.getPlayerCoordinateX(), player.getPlayerCoordinateY());
}

if (Keyboard::isKeyPressed(Keyboard::E) && items_floor.size() != 0 && !key_g) {
	key_e = true;
	for (int i = 0; i < items_floor.size(); i++) {
	    float condx_m = items_floor_x[i]/1 - range*64;
	    float condx_p = items_floor_x[i]/1 + range*64;
		float condy_m = items_floor_y[i]/1 - range*64;
		float condy_p = items_floor_y[i]/1 + range*64;
	    if (condx_m <= player_x && player_x <= condx_p && condy_m <= player_y && player_y <= condy_p) {
            for (int j = 0; j <= 33; j++) {
                if (inv_items[j] == 0) {
				    inv_items[j] = items_floor[i];
					std::cout << "!!! " << inv_items[j] << std::endl; //TEMP, TODO: DELETE
				    items_floor.erase(items_floor.begin() + i);
					items_floor_x.erase(items_floor_x.begin() + i);
					items_floor_y.erase(items_floor_y.begin() + i);
					for (int k = 0; k < items_floor_sprites.size(); k++) {
	                    if (k > i) {
	                        items_floor_sprites[k] = items_floor_sprites[k] - 1;
	                    }
	                }
					for (int k = 0; k < v_monsters.size(); k++) {
						if (v_monsters[k].getMonsterSprite() > items_floor_sprites[i]) {
						    v_monsters[k].reduceMonsterSprite();
						}
	                }
					other_sprites.erase(other_sprites.begin() + items_floor_sprites[i]);
                    items_floor_sprites.erase(items_floor_sprites.begin() + i);
					sprite_counter--;
				    break4items = true;
			    	break;
			    }
            }
        }
		if (break4items) {
		    break4items = false;
			break;
		}
	}
} else { key_e = false; }
if (Keyboard::isKeyPressed(Keyboard::G) && !key_e) {
	key_g = true;
	int out = player_x - (960 - Mouse::getPosition().x);
	int outy = player_y - (570 - Mouse::getPosition().y);
	int vx = view.getCenter().x + 232;
	int vy = view.getCenter().y - 352;
	if (is_inventory_open && vx/1 <= out && out <= vx/1 + 115 && vy/1 <= outy && outy <= vy/1 + 106) {
		if (inv_items[0] != 0) {
			std::cout << "DROP\n";
			createItem(inv_items[0], player_x, player_y);
		    inv_items[0] = 0;
	    }
	}
} else { key_g = false; }
if (Keyboard::isKeyPressed(Keyboard::I)) {
	if (!is_inventory_open) {
		is_inventory_open = true;
	}
}
if (Keyboard::isKeyPressed(Keyboard::Escape)) {
	if (is_inventory_open) {
		is_inventory_open = false;
	}
}
//
if (Keyboard::isKeyPressed(Keyboard::Num1) && !key_2 && !key_3 && !key_4) {
	key_1 = true;
} else { key_1 = false; }
//
if (Mouse::isButtonPressed(Mouse::Left)) {
	key_m1 = true;
	if (aiming) {
		aiming = false;
		spells(time);
	}
	attack = 1; //first type of attack
} else { key_m1 = false; }
if (Mouse::isButtonPressed(Mouse::Right)) {
	key_m2 = true;
	aiming = false;
} else { key_m2 = false; }
//
if (!key_m1 && !key_m2) {
	attack = 0;
}
if (key_1) {
	aiming_kid = true;
}
if (!key_1 && aiming_kid) {
	spell_name = hotbar_spells[0];
	spell_slot = 0;
	aiming = true;
	aiming_kid = false;
}
if (Keyboard::isKeyPressed(Keyboard::LControl) && key_m2) {
	targeting();
}
