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
	void keys(auto& time, auto& v_monsters, auto& v_NPC, auto& game) {
		keysMove(time);
		keyShift();
		keySpace();
		keyE(v_monsters, v_NPC, game);
		keyG(game);
		keyI();
		keyO();
		keyEscape();
	}
	void keysMove(auto& time) {
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
	void keyE(auto& v_monsters, auto& v_NPC, auto& game) {
		if (Keyboard::isKeyPressed(Keyboard::E) && game.items_dropped.size() != 0 && !key_g) {
			key_e = true;
			//eventNPCDialog(v_NPC);
			eventPickItem(v_monsters, game);
		} else { key_e = false; }
	}
	void keyG(auto& game) {
		if (Keyboard::isKeyPressed(Keyboard::G) && !key_e) {
			key_g = true;
			eventDropItem(game);
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
	void eventNPCDialog(auto& v_NPC) {
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
	void eventPickItem(auto& v_monsters, auto& game) { //todo: complete
		for (int i = 0; i < game.items_dropped[0].size(); i++) {
			float x_m = game.items_dropped[1][i]/1 - range*64;
			float x_p = game.items_dropped[1][i]/1 + range*64;
			float y_m = game.items_dropped[2][i]/1 - range*64;
			float y_p = game.items_dropped[2][i]/1 + range*64;
			if (x_m <= p_cords[0] && p_cords[0] <= x_p &&
				y_m <= p_cords[1] && p_cords[1] <= y_p) {
				for (int j = 0; j < 24; j++) {
					if (inv_items[j] == 0) {
						inv_items[j] = game.items_dropped[0][i];
						inv_types[j] = game.items_dropped[4][i];
						game.InventoryItemsSprite[j] = game.other_sprites[game.items_dropped[3][i]];
						game.InventoryItemsSprite[j].setTextureRect(IntRect(0, 0, 56, 56));
						game.InventoryItemsSprite[j].setScale(1.5, 1.5);
						for (int k = 0; k < game.items_dropped[3].size(); k++) {
							if (k > i) {
								game.items_dropped[3][k] = game.items_dropped[3][k] - 1;
							}
						}
						/*for (int k = 0; k < v_monsters.size(); k++) {
							if (v_monsters[k].getMonsterSprite() > items_dropped_sprites[i]) {
								v_monsters[k].reduceMonsterSprite();
							}
						}*/
						game.other_sprites.erase(game.other_sprites.begin() + game.items_dropped[3][i]);
						for (auto& e: game.items_dropped) {
							e.erase(e.begin() + i);
						}
						game.sprite_counter--;
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
	}
	void eventDropItem(auto& game) {
		game.text_item_info.get()->setString("");
		int out = p_cords[0] - (962 - Mouse::getPosition().x);
		int outy = p_cords[1] - (544 - Mouse::getPosition().y);
		int vx = game.viewGetCenterX() + 261;
		int vy = game.viewGetCenterY() - 343;
		if (is_inventory_open) {
			for (int i = 0; i < 6; i++) {
				vx = game.viewGetCenterX() + 261;
				for (int j = 0; j < 4; j++) {
					if (inv_items[i * 4 + j] != 0) {
						if (vx/1 <= out && out <= vx/1 + 56 && vy/1 <= outy && outy <= vy/1 + 56) {
							game.InventoryItemsSprite[i * 4 + j] = game.InventoryItemEmptySprite;
							game.createItem(inv_items[i * 4 + j], p_cords[0], p_cords[1]);
							inv_items[i * 4 + j] = 0;
							inv_types[i * 4 + j] = 0;
						}
					}
					vx += 112;
				}
				vy += 112;
			}
		}
	}
	void moveCurrentFrame(auto& time) {
        current_frame += 0.005 * time;
        if (current_frame > 3) {
            current_frame -= 3;
        }
    }
};
