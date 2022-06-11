class Keys: public PlayerVars {
private:
	bool key_a = false, key_d = false, key_w = false, key_s = false;
	bool key_e = false, key_g = false;
	bool key_m1 = false, key_m2 = false;
	bool key_1 = false, key_2 = false, key_3 = false, key_4 = false;
	bool key_5 = false, key_6 = false, key_7 = false, key_8 = false, key_9 = false;
	bool key_shift = false, key_space = false;
	bool is_info = false;
	bool break4items = false;
protected:
	void keys(auto &time, auto &sprite, auto &v_monsters, auto &v_NPC, auto &items_dropped_id) {
		keysMove(time, sprite);
		keyShift();
		keySpace();
		keyE(v_monsters, v_NPC, items_dropped_id);
		keyG();
		keyI();
		keyO();
		keyEscape();
	}
	void keysMove(auto &time, auto &sprite) {
		if (Keyboard::isKeyPressed(Keyboard::D) && !key_a && !key_w && !key_s && attack_animation == 0) {
			key_d = true;
			speed = 0.15;
			dir = 0;
			sprite.setTextureRect(IntRect(52 * int(current_frame), 128, 50, 62));
		} else { key_d = false; }
		if (Keyboard::isKeyPressed(Keyboard::A) && !key_d && !key_w && !key_s && attack_animation == 0) {
			key_a = true;
			speed = 0.15;
			dir = 1;
			sprite.setTextureRect(IntRect(52 * int(current_frame), 64, 50, 62));
		} else { key_a = false; }
		if (Keyboard::isKeyPressed(Keyboard::W) && !key_d && !key_a && !key_s && attack_animation == 0) {
			key_w = true;
			speed = 0.15;
			dir = 2;
			sprite.setTextureRect(IntRect(52 * int(current_frame), 192, 50, 62));
		} else { key_w = false; }
		if (Keyboard::isKeyPressed(Keyboard::S) && !key_d && !key_w && !key_a && attack_animation == 0) {
			key_s = true;
			speed = 0.15;
			dir = 3;
			sprite.setTextureRect(IntRect(52 * int(current_frame), 0, 50, 62));
		} else { key_s = false; }
        moveCurrentFrame(time);
	}
	void keyShift() {
		if (Keyboard::isKeyPressed(Keyboard::LShift) && attack_animation == 0) {
			key_shift = true;
			speed *= 0.5;
			defence = true;
		} else { key_shift = false; defence = false; }
	}
	void keySpace() {
		if (Keyboard::isKeyPressed(Keyboard::Space) && attack_animation == 0) {
			key_space = true;
			space_timer = 1000;
		} else { key_space = false; }
	}
	void keyE(auto &v_monsters, auto &v_NPC, auto &items_dropped_id) {
		if (Keyboard::isKeyPressed(Keyboard::E) && items_dropped_id.size() != 0 && !key_g) {
			key_e = true;
			//eventNPCDialog(v_NPC);
			eventPickItem(v_monsters);
		} else { key_e = false; }
	}
	void keyG() {
		if (Keyboard::isKeyPressed(Keyboard::G) && !key_e) {
			key_g = true;
			eventDropItem();
		} else { key_g = false; }
	}
	void keyI() {
		if (Keyboard::isKeyPressed(Keyboard::I)) {
			if (!is_inventory_open && !is_spells_inventory_open) {
				is_inventory_open = true;
			}
		}
	}
	void keyO() {
		if (Keyboard::isKeyPressed(Keyboard::O)) {
			if (!is_inventory_open && !is_spells_inventory_open) {
				is_spells_inventory_open = true;
			}
		}
	}
	void keyEscape() {
		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			if (is_inventory_open) {
				is_inventory_open = false;
			}
			if (is_spells_inventory_open) {
				is_spells_inventory_open = false;
			}
		}
	}
	void eventNPCDialog(auto &v_NPC) {
		/*for (int l = 0; l < v_NPC.size(); l++) {
			if (x < v_NPC[l].getX() + 64 &&
				x + 64 > v_NPC[l].getX() &&
				y < v_NPC[l].getY() + 64 &&
				y + 64 > v_NPC[l].getY())
			{
				v_NPC[l].startDialog();
				is_dialog = true;
			}
		}*/
	}
	void eventPickItem(auto &v_monsters) { //todo: complete
		/*for (int i = 0; i < items_dropped_id.size(); i++) {
			float condx_m = items_dropped_x[i]/1 - range*64;
			float condx_p = items_dropped_x[i]/1 + range*64;
			float condy_m = items_dropped_y[i]/1 - range*64;
			float condy_p = items_dropped_y[i]/1 + range*64;
			if (condx_m <= x && x <= condx_p && condy_m <= y && y <= condy_p) {
				for (int j = 0; j < 24; j++) {
					if (inv_items[j] == 0) {
						inv_items[j] = items_dropped_id[i];
						inv_types[j] = items_dropped_type[i];
						InventoryItemsSprite[j] = other_sprites[items_dropped_sprites[i]];
						InventoryItemsSprite[j].setTextureRect(IntRect(0, 0, 56, 56));
						InventoryItemsSprite[j].setScale(1.5, 1.5);
						items_dropped_id.erase(items_dropped_id.begin() + i);
						items_dropped_x.erase(items_dropped_x.begin() + i);
						items_dropped_y.erase(items_dropped_y.begin() + i);
						items_dropped_type.erase(items_dropped_type.begin() + i);
						for (int k = 0; k < items_dropped_sprites.size(); k++) {
							if (k > i) {
								items_dropped_sprites[k] = items_dropped_sprites[k] - 1;
							}
						}
						for (int k = 0; k < v_monsters.size(); k++) {
							if (v_monsters[k].getMonsterSprite() > items_dropped_sprites[i]) {
								v_monsters[k].reduceMonsterSprite();
							}
						}
						other_sprites.erase(other_sprites.begin() + items_dropped_sprites[i]);
						items_dropped_sprites.erase(items_dropped_sprites.begin() + i);
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
		}*/
	}
	void eventDropItem() { //todo: complete
		/*text_item_info.setString("");
		int out = x - (962 - Mouse::getPosition().x);
		int outy = y - (544 - Mouse::getPosition().y);
		int vx = view.getCenter().x + 261;
		int vy = view.getCenter().y - 343;
		if (is_inventory_open) {
			for (int i = 0; i < 6; i++) {
				vx = view.getCenter().x + 261;
				for (int j = 0; j < 4; j++) {
					if (inv_items[i * 4 + j] != 0) {
						if (vx/1 <= out && out <= vx/1 + 56 && vy/1 <= outy && outy <= vy/1 + 56) {
							InventoryItemsSprite[i * 4 + j] = InventoryItemEmptySprite;
							createItem(inv_items[i * 4 + j], x, y);
							inv_items[i * 4 + j] = 0;
							inv_types[i * 4 + j] = 0;
						}
					}
					vx += 112;
				}
				vy += 112;
			}
		}*/
	}
	void moveCurrentFrame(auto &time) {
        current_frame += 0.005 * time;
        if (current_frame > 3) {
            current_frame -= 3;
        }
    }
};
