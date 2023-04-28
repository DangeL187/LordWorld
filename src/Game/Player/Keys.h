class Keys: public PlayerBase, public Equipment {
private:
	bool key_a = false, key_d = false, key_w = false, key_s = false;
	bool key_e = false, key_g = false;
	bool key_m1 = false, key_m2 = false;
	bool key_1 = false, key_2 = false, key_3 = false, key_4 = false;
	bool key_5 = false, key_6 = false, key_7 = false, key_8 = false, key_9 = false;
	bool aiming_kid1 = false, aiming_kid2 = false, aiming_kid3 = false;
	bool aiming_kid4 = false, aiming_kid5 = false, aiming_kid6 = false;
	bool aiming_kid7 = false, aiming_kid8 = false, aiming_kid9 = false;
	bool key_shift = false, key_space = false;
	bool is_info = false;
	bool break4items = false;
protected:
	void keys(auto& time, auto& game) {
		is_info = false;
		keysMove(time);
		keyShift();
		keySpace();
		keyE(game);
		keyG(game);
		keyI();
		keyO();
		keyEscape();
		keysAiming();
		keysTargeting(game);
		mouseLeft(time, game);
		mouseRight(game);
		spellAiming();
		ifs(game);
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
	void keyE(auto& game) {
		if (Keyboard::isKeyPressed(Keyboard::E) && game.items_dropped.size() != 0 && !key_g) {
			key_e = true;
			//eventNPCDialog(game);
			eventPickItem(game);
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
	void keysAiming() {
		if (Keyboard::isKeyPressed(Keyboard::Num1) && !key_2 && !key_3 && !key_4 && !key_5 && !key_6 && !key_7 && !key_8 && !key_9) {
			key_1 = true;
		} else { key_1 = false; }
		if (Keyboard::isKeyPressed(Keyboard::Num2) && !key_1 && !key_3 && !key_4 && !key_5 && !key_6 && !key_7 && !key_8 && !key_9) {
			key_2 = true;
		} else { key_2 = false; }
		if (Keyboard::isKeyPressed(Keyboard::Num3) && !key_2 && !key_1 && !key_4 && !key_5 && !key_6 && !key_7 && !key_8 && !key_9) {
			key_3 = true;
		} else { key_3 = false; }
		if (Keyboard::isKeyPressed(Keyboard::Num4) && !key_2 && !key_3 && !key_1 && !key_5 && !key_6 && !key_7 && !key_8 && !key_9) {
			key_4 = true;
		} else { key_4 = false; }
		if (Keyboard::isKeyPressed(Keyboard::Num5) && !key_2 && !key_3 && !key_4 && !key_1 && !key_6 && !key_7 && !key_8 && !key_9) {
			key_5 = true;
		} else { key_5 = false; }
		if (Keyboard::isKeyPressed(Keyboard::Num6) && !key_2 && !key_3 && !key_4 && !key_5 && !key_1 && !key_7 && !key_8 && !key_9) {
			key_6 = true;
		} else { key_6 = false; }
		if (Keyboard::isKeyPressed(Keyboard::Num7) && !key_2 && !key_3 && !key_4 && !key_5 && !key_6 && !key_1 && !key_8 && !key_9) {
			key_7 = true;
		} else { key_7 = false; }
		if (Keyboard::isKeyPressed(Keyboard::Num8) && !key_2 && !key_3 && !key_4 && !key_5 && !key_6 && !key_7 && !key_1 && !key_9) {
			key_8 = true;
		} else { key_8 = false; }
		if (Keyboard::isKeyPressed(Keyboard::Num9) && !key_2 && !key_3 && !key_4 && !key_5 && !key_6 && !key_7 && !key_8 && !key_1) {
			key_9 = true;
		} else { key_9 = false; }
	}
	void keysTargeting(auto& game) {
		if (Keyboard::isKeyPressed(Keyboard::LControl) && key_m2) {
			game.targeting(game);
			attack = 0;
		}
	}
	void mouseLeft(auto& time, auto& game) {
		if (Mouse::isButtonPressed(Mouse::Left)) {
			key_m1 = true;
			if (!is_inventory_open && !is_spells_inventory_open && !aiming) {
				attack = 1; //first type of attack
			}
			if (aiming) {
				aiming = false;
				spells(time, game);
			}
		} else { key_m1 = false; }
	}
	void mouseRight(auto& game) {
		if (Mouse::isButtonPressed(Mouse::Right)) {
			int out = p_cords[0] - (962 - Mouse::getPosition().x);
			int outy = p_cords[1] - (544 - Mouse::getPosition().y);
			int vx = game.view.getCenter().x + 261;
			int vy = game.view.getCenter().y - 343;
			if (!is_inventory_open && !is_spells_inventory_open && !Keyboard::isKeyPressed(Keyboard::LControl)) {
				attack = 2; //second type of attack
			}
			if (is_inventory_open) {
				game.text_info.setString("");
				for (int i = 0; i < 6; i++) {
					vx = game.view.getCenter().x + 261;
					for (int j = 0; j < 4; j++) {
						if (vx/1 <= out && out <= vx/1 + 56 && vy/1 <= outy && outy <= vy/1 + 56) {
							if (inv_types[i * 4 + j] == 7 && inv_items[24] == 0) { //other1
								game.InventoryItemsSprite[24] = game.InventoryItemsSprite[i * 4 + j];
					            game.InventoryItemsSprite[i * 4 + j] = game.InventoryItemEmptySprite;
								inv_items[24] = inv_items[i * 4 + j];
								inv_items[i * 4 + j] = 0;
								inv_types[i * 4 + j] = 0;
						    }
							if (inv_types[i * 4 + j] == 7 && inv_items[25] == 0) { //other2
								game.InventoryItemsSprite[25] = game.InventoryItemsSprite[i * 4 + j];
					            game.InventoryItemsSprite[i * 4 + j] = game.InventoryItemEmptySprite;
								inv_items[25] = inv_items[i * 4 + j];
								inv_items[i * 4 + j] = 0;
								inv_types[i * 4 + j] = 0;
						    }
							if (inv_types[i * 4 + j] == 7 && inv_items[26] == 0) { //other3
								game.InventoryItemsSprite[26] = game.InventoryItemsSprite[i * 4 + j];
					            game.InventoryItemsSprite[i * 4 + j] = game.InventoryItemEmptySprite;
								inv_items[26] = inv_items[i * 4 + j];
								inv_items[i * 4 + j] = 0;
								inv_types[i * 4 + j] = 0;
						    }
						    if (inv_types[i * 4 + j] == 1 && inv_items[27] == 0) { //weapon
								game.gui_equipment_sprites[0] = game.InventoryItemsSprite[i * 4 + j];
					            game.InventoryItemsSprite[i * 4 + j] = game.InventoryItemEmptySprite;
								inv_items[27] = inv_items[i * 4 + j];
								inv_items[i * 4 + j] = 0;
								inv_types[i * 4 + j] = 0;
								setWeaponStats(game, inv_items);
						    }
							if (inv_types[i * 4 + j] == 2 && inv_items[28] == 0) { //shield
								game.gui_equipment_sprites[1] = game.InventoryItemsSprite[i * 4 + j];
					            game.InventoryItemsSprite[i * 4 + j] = game.InventoryItemEmptySprite;
								inv_items[28] = inv_items[i * 4 + j];
								inv_items[i * 4 + j] = 0;
								inv_types[i * 4 + j] = 0;
							}
							if (inv_types[i * 4 + j] == 3 && inv_items[29] == 0) { //helmet
								game.gui_equipment_sprites[2] = game.InventoryItemsSprite[i * 4 + j];
					            game.InventoryItemsSprite[i * 4 + j] = game.InventoryItemEmptySprite;
								inv_items[29] = inv_items[i * 4 + j];
								inv_items[i * 4 + j] = 0;
								inv_types[i * 4 + j] = 0;
							}
							if (inv_types[i * 4 + j] == 4 && inv_items[30] == 0) { //chestplate
								game.gui_equipment_sprites[3] = game.InventoryItemsSprite[i * 4 + j];
					            game.InventoryItemsSprite[i * 4 + j] = game.InventoryItemEmptySprite;
								inv_items[30] = inv_items[i * 4 + j];
								inv_items[i * 4 + j] = 0;
								inv_types[i * 4 + j] = 0;
							}
							if (inv_types[i * 4 + j] == 5 && inv_items[31] == 0) { //pants
								game.gui_equipment_sprites[4] = game.InventoryItemsSprite[i * 4 + j];
					            game.InventoryItemsSprite[i * 4 + j] = game.InventoryItemEmptySprite;
								inv_items[31] = inv_items[i * 4 + j];
								inv_items[i * 4 + j] = 0;
								inv_types[i * 4 + j] = 0;
							}
							if (inv_types[i * 4 + j] == 6 && inv_items[32] == 0) { //boots
								game.gui_equipment_sprites[5] = game.InventoryItemsSprite[i * 4 + j];
					            game.InventoryItemsSprite[i * 4 + j] = game.InventoryItemEmptySprite;
								inv_items[32] = inv_items[i * 4 + j];
								inv_items[i * 4 + j] = 0;
								inv_types[i * 4 + j] = 0;
							}
						}
						vx += 112;
				    }
					vy += 112;
			    }
				if (inv_items[24] != 0) {
					vx = game.view.getCenter().x - 203;
					vy = game.view.getCenter().y + 185;
					if (vx/1 <= out && out <= vx/1 + 56 && vy/1 <= outy && outy <= vy/1 + 56) {
						for (int j = 0; j < 24; j++) {
							if (inv_items[j] == 0) {
						        game.InventoryItemsSprite[j] = game.InventoryItemsSprite[24];
						        game.InventoryItemsSprite[24] = game.InventoryItemEmptySprite;
								inv_items[j] = inv_items[24];
								inv_types[j] = 7;
						        inv_items[24] = 0;
							}
						}
					}
				}
				if (inv_items[25] != 0) {
					vx = game.view.getCenter().x - 71;
					vy = game.view.getCenter().y + 185;
					if (vx/1 <= out && out <= vx/1 + 56 && vy/1 <= outy && outy <= vy/1 + 56) {
						for (int j = 0; j < 24; j++) {
							if (inv_items[j] == 0) {
						        game.InventoryItemsSprite[j] = game.InventoryItemsSprite[25];
						        game.InventoryItemsSprite[25] = game.InventoryItemEmptySprite;
								inv_items[j] = inv_items[25];
								inv_types[j] = 7;
						        inv_items[25] = 0;
							}
						}
					}
				}
				if (inv_items[26] != 0) {
					vx = game.view.getCenter().x + 61;
					vy = game.view.getCenter().y + 185;
					if (vx/1 <= out && out <= vx/1 + 56 && vy/1 <= outy && outy <= vy/1 + 56) {
						for (int j = 0; j < 24; j++) {
							if (inv_items[j] == 0) {
						        game.InventoryItemsSprite[j] = game.InventoryItemsSprite[26];
						        game.InventoryItemsSprite[26] = game.InventoryItemEmptySprite;
								inv_items[j] = inv_items[26];
								inv_types[j] = 7;
						        inv_items[26] = 0;
							}
						}
					}
				}
				if (inv_items[27] != 0) {
					vx = game.view.getCenter().x - 231;
					vy = game.view.getCenter().y - 227;
					if (vx/1 <= out && out <= vx/1 + 56 && vy/1 <= outy && outy <= vy/1 + 56) {
						for (int j = 0; j < 24; j++) {
							if (inv_items[j] == 0) {
						        game.InventoryItemsSprite[j] = game.gui_equipment_sprites[0];
						        game.gui_equipment_sprites[0] = game.InventoryItemEmptySprite;
								inv_items[j] = inv_items[27];
								inv_types[j] = 1;
						        inv_items[27] = 0;
								game.gui_equipment_sprites[0] = createSprite("GuiSlotWeapon.png");
								game.gui_equipment_sprites[0].setTextureRect(IntRect(0, 0, 116, 116));
								break;
							}
						}
					}
					setWeaponStats(game, inv_items);
				}
				if (inv_items[28] != 0) {
					vx = game.view.getCenter().x + 89;
					vy = game.view.getCenter().y - 227;
					if (vx/1 <= out && out <= vx/1 + 56 && vy/1 <= outy && outy <= vy/1 + 56) {
						for (int j = 0; j < 24; j++) {
							if (inv_items[j] == 0) {
						        game.InventoryItemsSprite[j] = game.gui_equipment_sprites[1];
						        game.gui_equipment_sprites[1] = game.InventoryItemEmptySprite;
								inv_items[j] = inv_items[28];
								inv_types[j] = 2;
						        inv_items[28] = 0;
								game.gui_equipment_sprites[1] = createSprite("GuiSlotShield.png");
								game.gui_equipment_sprites[1].setTextureRect(IntRect(0, 0, 116, 116));
								break;
							}
						}
					}
				}
				if (inv_items[29] != 0) {
					vx = game.view.getCenter().x - 71;
					vy = game.view.getCenter().y - 351;
					if (vx/1 <= out && out <= vx/1 + 56 && vy/1 <= outy && outy <= vy/1 + 56) {
						for (int j = 0; j < 24; j++) {
							if (inv_items[j] == 0) {
						        game.InventoryItemsSprite[j] = game.gui_equipment_sprites[2];
						        game.gui_equipment_sprites[2] = game.InventoryItemEmptySprite;
								inv_items[j] = inv_items[29];
								inv_types[j] = 3;
						        inv_items[29] = 0;
								game.gui_equipment_sprites[2] = createSprite("GuiSlotHelm.png");
								game.gui_equipment_sprites[2].setTextureRect(IntRect(0, 0, 116, 116));
								break;
							}
						}
					}
				}
				if (inv_items[30] != 0) {
					vx = game.view.getCenter().x - 71;
					vy = game.view.getCenter().y - 227;
					if (vx/1 <= out && out <= vx/1 + 56 && vy/1 <= outy && outy <= vy/1 + 56) {
						for (int j = 0; j < 24; j++) {
							if (inv_items[j] == 0) {
						        game.InventoryItemsSprite[j] = game.gui_equipment_sprites[3];
						        game.gui_equipment_sprites[3] = game.InventoryItemEmptySprite;
								inv_items[j] = inv_items[30];
								inv_types[j] = 4;
						        inv_items[30] = 0;
								game.gui_equipment_sprites[3] = createSprite("GuiSlotChest.png");
								game.gui_equipment_sprites[3].setTextureRect(IntRect(0, 0, 116, 116));
								break;
							}
						}
					}
				}
				if (inv_items[31] != 0) {
					vx = game.view.getCenter().x - 71;
					vy = game.view.getCenter().y - 103;
					if (vx/1 <= out && out <= vx/1 + 56 && vy/1 <= outy && outy <= vy/1 + 56) {
						for (int j = 0; j < 24; j++) {
							if (inv_items[j] == 0) {
						        game.InventoryItemsSprite[j] = game.gui_equipment_sprites[4];
						        game.gui_equipment_sprites[4] = game.InventoryItemEmptySprite;
								inv_items[j] = inv_items[31];
								inv_types[j] = 5;
						        inv_items[31] = 0;
								game.gui_equipment_sprites[4] = createSprite("GuiSlotPants.png");
								game.gui_equipment_sprites[4].setTextureRect(IntRect(0, 0, 116, 116));
								break;
							}
						}
					}
				}
				if (inv_items[32] != 0) {
					vx = game.view.getCenter().x - 71;
					vy = game.view.getCenter().y + 21;
					if (vx/1 <= out && out <= vx/1 + 56 && vy/1 <= outy && outy <= vy/1 + 56) {
						for (int j = 0; j < 24; j++) {
							if (inv_items[j] == 0) {
						        game.InventoryItemsSprite[j] = game.gui_equipment_sprites[5];
						        game.gui_equipment_sprites[5] = game.InventoryItemEmptySprite;
								inv_items[j] = inv_items[32];
								inv_types[j] = 6;
						        inv_items[32] = 0;
								game.gui_equipment_sprites[5] = createSprite("GuiSlotBoots.png");
								game.gui_equipment_sprites[5].setTextureRect(IntRect(0, 0, 116, 116));
								break;
							}
						}
					}
				}
			}
			if (is_spells_inventory_open) {
				int vx = game.view.getCenter().x + 231 + 15;
				int vy = game.view.getCenter().y - 373 + 30;
				for (int i = 0; i < 6; i++) {
					vx = game.view.getCenter().x + 231 + 15;
					for (int j = 0; j < 4; j++) {
						if (vx/1 <= out && out <= vx/1 + 56 && vy/1 <= outy && outy <= vy/1 + 56) {
							if (inv_spells[i * 4 + j] != 0) {
								for (int k = 0; k < 9; k++) {
					                if (hotbar_spells[k] == 0) {
									    hotbar_spells[k] = inv_spells[i * 4 + j];
										inv_spells[i * 4 + j] = 0;
								    	break;
								    }
					            }
							}
						}
						vx += 112;
				    }
					vy += 112;
			    }
				vy = game.view.getCenter().y + 384 + 15;
				for (int i = 0; i < 9; i++) {
					vx = game.view.getCenter().x - 536 + 15 + 112 * i;
				    if (vx/1 <= out && out <= vx/1 + 56 && vy/1 <= outy && outy <= vy/1 + 56) {
						for (int j = 0; j < 24; j++) {
			                if (inv_spells[j] == 0 && cooldowns[i] <= 0) {
								inv_spells[j] = hotbar_spells[i];
								hotbar_spells[i] = 0;
								break;
							}
						}
					}
				}
			}
			key_m2 = true;
			aiming = false;
		} else { key_m2 = false; }
	}

	void eventNPCDialog(auto& game) {
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
	void eventPickItem(auto& game) { //todo: complete
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
						game.InventoryItemsSprite[j] = game.current_item_sprites[game.items_dropped[3][i]];
						game.InventoryItemsSprite[j].setTextureRect(IntRect(0, 0, 56, 56));
						game.InventoryItemsSprite[j].setScale(1.5, 1.5);
						for (int k = 0; k < game.items_dropped[3].size(); k++) {
							if (k > i) {
								game.items_dropped[3][k] = game.items_dropped[3][k] - 1;
							}
						}
						/*for (int k = 0; k < game.v_monsters.size(); k++) {
							if (game.v_monsters[k].getSprite() > game.items_dropped[3][k]) {
								game.v_monsters[k].reduceSprite();
							}
						}*/
						game.current_item_sprites.erase(game.current_item_sprites.begin() + game.items_dropped[3][i]);
						for (auto& e: game.items_dropped) {
							e.erase(e.begin() + i);
						}
						game.item_sprite_counter--;
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
		game.text_info.setString("");
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
	void spellAiming() {
		if (key_1) {
			aiming_kid1 = true;
		}
		if (key_2) {
			aiming_kid2 = true;
		}
		if (key_3) {
			aiming_kid3 = true;
		}
		if (key_4) {
			aiming_kid4 = true;
		}
		if (key_5) {
			aiming_kid5 = true;
		}
		if (key_6) {
			aiming_kid6 = true;
		}
		if (key_7) {
			aiming_kid7 = true;
		}
		if (key_8) {
			aiming_kid8 = true;
		}
		if (key_9) {
			aiming_kid9 = true;
		}
		if (!key_1 && aiming_kid1) {
			spell_name = hotbar_spells[0];
			spell_slot = 0;
			aiming = true;
			aiming_kid1 = false;
		}
		if (!key_2 && aiming_kid2) {
			spell_name = hotbar_spells[1];
			spell_slot = 1;
			aiming = true;
			aiming_kid2 = false;
		}
		if (!key_3 && aiming_kid3) {
			spell_name = hotbar_spells[2];
			spell_slot = 2;
			aiming = true;
			aiming_kid3 = false;
		}
		if (!key_4 && aiming_kid4) {
			spell_name = hotbar_spells[3];
			spell_slot = 3;
			aiming = true;
			aiming_kid4 = false;
		}
		if (!key_5 && aiming_kid5) {
			spell_name = hotbar_spells[4];
			spell_slot = 4;
			aiming = true;
			aiming_kid5 = false;
		}
		if (!key_6 && aiming_kid6) {
			spell_name = hotbar_spells[5];
			spell_slot = 5;
			aiming = true;
			aiming_kid6 = false;
		}
		if (!key_7 && aiming_kid7) {
			spell_name = hotbar_spells[6];
			spell_slot = 6;
			aiming = true;
			aiming_kid7 = false;
		}
		if (!key_8 && aiming_kid8) {
			spell_name = hotbar_spells[7];
			spell_slot = 7;
			aiming = true;
			aiming_kid8 = false;
		}
		if (!key_9 && aiming_kid9) {
			spell_name = hotbar_spells[8];
			spell_slot = 8;
			aiming = true;
			aiming_kid9 = false;
		}
	}
	void ifs(auto& game) { //split into several methods
		if (!key_m1 && !key_m2) {
			attack = 0;
		}

		if (is_inventory_open) {
			int out = game.player->getX() - (962 - Mouse::getPosition().x);
			int outy = game.player->getY() - (544 - Mouse::getPosition().y);
			int vx = game.view.getCenter().x + 261;
			int vy = game.view.getCenter().y - 343;
			for (int i = 0; i < 6; i++) {
				vx = game.view.getCenter().x + 261;
				for (int j = 0; j < 4; j++) {
					if (vx/1 <= out && out <= vx/1 + 56 && vy/1 <= outy && outy <= vy/1 + 56) {
						setInfo(true, inv_items[i * 4 + j], game.text_info);
						game.GuiInfoSprite.setPosition(out - 10, outy);
						game.text_info.setPosition(out, outy + 15);
						is_info = true;
					}
					vx += 112;
				}
				vy += 112;
			}
		}
		if (is_spells_inventory_open) {
		    int out = game.player->getX() - (962 - Mouse::getPosition().x);
		    int outy = game.player->getY() - (544 - Mouse::getPosition().y);
			int vx = game.view.getCenter().x + 261;
			int vy = game.view.getCenter().y - 343;
		    for (int i = 0; i < 6; i++) {
		    	vx = game.view.getCenter().x + 261;
			    for (int j = 0; j < 4; j++) {
					if (vx/1 <= out && out <= vx/1 + 56 && vy/1 <= outy && outy <= vy/1 + 56) {
						setInfo(false, inv_spells[i * 4 + j], game.text_info);
						game.GuiInfoSprite.setPosition(out - 10, outy);
						game.text_info.setPosition(out, outy + 15); //todo: rename to text_info
						is_info = true;
					}
				    vx += 112;
		    	}
			    vy += 112;
		    }
		}
		int out = game.player->getX() - (962 - Mouse::getPosition().x);
		int outy = game.player->getY() - (544 - Mouse::getPosition().y);
		int vx = game.view.getCenter().x - 940;
		int vy = game.view.getCenter().y - 480;
		if (vx/1 <= out && out <= vx/1 + 170 && vy/1 <= outy && outy <= vy/1 + 100) {
			game.text_strength.setString("Strength: " + std::to_string(game.player->strength));
			game.text_damage.setString("Damage: " + std::to_string(game.player->damage));
			game.text_armor.setString("Armor: " + std::to_string(game.player->armor));
			game.text_magic.setString("Magic: " + std::to_string(game.player->magic));
			game.text_critical_chance.setString("Critical Chance: " + std::to_string(static_cast<int>(game.player->critical_chance)) + "%");
			game.text_magic_resistance.setString("Magic Resistance: " + std::to_string(static_cast<int>(game.player->magic_resistance)) + "%");
			game.text_physical_resistance.setString("Physical Resistance: " + std::to_string(static_cast<int>(game.player->physical_resistance)) + "%");
			game.text_magic_ice.setString("Magic Ice: " + std::to_string(game.player->magic_ice));
			game.text_magic_fire.setString("Magic Fire: " + std::to_string(game.player->magic_fire));
			game.text_magic_earth.setString("Magic Earth: " + std::to_string(game.player->magic_earth));
			game.text_magic_wind.setString("Magic Wind: " + std::to_string(game.player->magic_wind));
			game.text_magic_dark.setString("Magic Dark: " + std::to_string(game.player->magic_dark));
			game.text_magic_light.setString("Magic Light: " + std::to_string(game.player->magic_light));
			game.text_melee_weapon.setString("Melee Weapon: " + std::to_string(game.player->melee_weapon));
			game.text_range_weapon.setString("Range Weapon: " + std::to_string(game.player->range_weapon));
			is_stats_open = true;
		} else {
			is_stats_open = false;
			game.text_strength.setString("");
			game.text_damage.setString("");
			game.text_armor.setString("");
			game.text_magic.setString("");
			game.text_critical_chance.setString("");
			game.text_magic_resistance.setString("");
			game.text_physical_resistance.setString("");
			game.text_magic_ice.setString("");
			game.text_magic_fire.setString("");
			game.text_magic_earth.setString("");
			game.text_magic_wind.setString("");
			game.text_magic_dark.setString("");
			game.text_magic_light.setString("");
			game.text_melee_weapon.setString("");
			game.text_range_weapon.setString("");
		}

		if (!is_info) {
			game.text_info.setString("");
		}
	}
	void moveCurrentFrame(auto& time) {
        current_frame += 0.005 * time;
        if (current_frame > 3) {
            current_frame -= 3;
        }
    }
};