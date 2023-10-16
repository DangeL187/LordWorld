class Keys: public PlayerBase, public Equipment {
private:
	bool key_a = false, key_d = false, key_w = false, key_s = false;
	bool key_e = false, key_g = false;
	bool key_m1 = false, key_m2 = false;
	bool key_m1_go = false, key_m2_go = false;
	bool key_1 = false, key_2 = false, key_3 = false, key_4 = false;
	bool key_5 = false, key_6 = false, key_7 = false, key_8 = false, key_9 = false;
	bool aiming_kid1 = false, aiming_kid2 = false, aiming_kid3 = false;
	bool aiming_kid4 = false, aiming_kid5 = false, aiming_kid6 = false;
	bool aiming_kid7 = false, aiming_kid8 = false, aiming_kid9 = false;
	bool key_shift = false, key_space = false;
	bool key_enter = false, key_enter_go = false;
	bool is_info = false;
	bool break4items = false;
	bool defence_go = false;
protected:
	void keys(auto& time, auto& game) {
		is_info = false;
		//TODO: rename ALL!
		keysMove(time);
		keyShift(game);
		keySpace();
		dash(time);
		keyE(game);
		keyG(game);
		keyI();
		keyO();
		keyEscape();
		keyEnter(game);
		keysAiming();
		keysTargeting(game);
		spellAiming();
		mouseLeft(time, game);
		mouseRight(game);
		ifs(game);
	}
	void keysMove(auto& time) {
		if (Keyboard::isKeyPressed(Keyboard::D) && !key_a && !key_w && !key_s) {
			key_d = true;
			dir = 0;
		} else { key_d = false; }
		if (Keyboard::isKeyPressed(Keyboard::A) && !key_d && !key_w && !key_s) {
			key_a = true;
			dir = 1;
		} else { key_a = false; }
		if (Keyboard::isKeyPressed(Keyboard::W) && !key_d && !key_a && !key_s) {
			key_w = true;
			dir = 2;
		} else { key_w = false; }
		if (Keyboard::isKeyPressed(Keyboard::S) && !key_d && !key_w && !key_a) {
			key_s = true;
			dir = 3;
		} else { key_s = false; }
		if (key_d || key_a || key_w || key_s) {
			speed = 0.15;
			auto cf = int(current_frame); if (cf == 3) { cf = 1; }
			sprite.setTextureRect(IntRect(w * cf + cf + 1, h * dir + dir + 1, w, h));
		}
        moveCurrentFrame(time);
	}
	void keyShift(auto& game) {
		if (Keyboard::isKeyPressed(Keyboard::LShift) && attack_animation == 0 && attack == 0) {
			key_shift = true;
			speed *= 0.5;
			if (shield_cd == 0 && defence_timer == 0 && defence_go) {
				defence_timer = 1000;
				shield_cd = 5000;
				defence_go = false;
			} else {
				game.renderer->text_dynamic_shield_cd->start(500);
			}
		} else { key_shift = false; defence = false; defence_go = true;}
	}
	void keySpace() {
		if (Keyboard::isKeyPressed(Keyboard::Space) && attack_animation == 0) {
			key_space = true;
			space_timer = 1000;
		} else { key_space = false; }
	}
	void dash(auto& time) {
		if (dash_timer > 0) {
			dash_timer -= time;
			speed *= 10;
		}
		if (key_space && key_shift && (key_d || key_a || key_w || key_s) && dash_cd <= 0) {
			dash_timer = 200;
			dash_cd = 5000;
		}
	}
	void keyE(auto& game) {
		if (Keyboard::isKeyPressed(Keyboard::E) && !key_g) {
			key_e = true;
			if (game.entity_manager->v_items.size() != 0) {
				eventPickItem(game);
			}
			eventNPCDialog(game);
		} else { key_e = false; }
	}
	void keyG(auto& game) {
		if (Keyboard::isKeyPressed(Keyboard::G) && !key_e) {
			key_g = true;
			eventDropItem(game);
		} else { key_g = false; }
	}
	void keyI() {
		if (Keyboard::isKeyPressed(Keyboard::Tab)) {
			if (!is_spells_inventory_open) {
				is_inventory_open = true;
			}
		} else { is_inventory_open = false; }
	}
	void keyO() {
		if (Keyboard::isKeyPressed(Keyboard::Tilde)) {
			if (!is_inventory_open) {
				is_spells_inventory_open = true;
			}
		} else { is_spells_inventory_open = false; }
	}
	void keyEscape() {
		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			if (is_dialog) {
				dialog_phase = 0;
				is_dialog = false;
			}
		}
	}
	void keyEnter(auto& game) {
		if (Keyboard::isKeyPressed(Keyboard::Enter) && key_enter) {
			key_enter_go = true;
		}
		if (!Keyboard::isKeyPressed(Keyboard::Enter)) {
			key_enter = true;
			if (key_enter_go) {
				if (is_dialog) {
					dialog_phase++;
				}
				key_enter = false;
				key_enter_go = false;
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
		if (Keyboard::isKeyPressed(Keyboard::LControl) && key_m2_go) {
			game.targeting(game);
			attack = 0;
		}
	}
	void mouseLeft(auto& time, auto& game) {
		if (Mouse::isButtonPressed(Mouse::Left) && key_m1) {
			key_m1_go = true;
		}
		if (!Mouse::isButtonPressed(Mouse::Left)) {
			key_m1 = true;
			if (key_m1_go && !Mouse::isButtonPressed(Mouse::Right)) {
				if (!is_inventory_open && !is_spells_inventory_open && attack_animation == 0 && !aiming && attack1_cd == 0) {
					attack = 1; //first type of attack
				} else {
					attack = 0;
				}
				if (aiming) {
					aiming = false;
					key_m1 = false;
					spells(time, game);
				}
				key_m1_go = false;
			}
		}
	}
	void mouseRight(auto& game) {
		if (Mouse::isButtonPressed(Mouse::Right) && key_m2) {
			key_m2_go = true;
		}
		if (!Mouse::isButtonPressed(Mouse::Right)) {
			key_m2 = true;
			if (key_m2_go && !Mouse::isButtonPressed(Mouse::Left)) {
				bool is_ctrl = Keyboard::isKeyPressed(Keyboard::LControl);
				if (!is_inventory_open && !is_spells_inventory_open && attack_animation == 0 && attack2_cd == 0 && !is_ctrl) {
					attack = 2; //second type of attack
				} else {
					attack = 0;
				}
				if (aiming) {
					aiming = false;
					key_m2 = false;
				}
				mouseInventory(game);
				key_m2_go = false;
			}
		}
	}

	void eventNPCDialog(auto& game) {
		for (int l = 0; l < game.v_NPC.size(); l++) {
			if (x < game.v_NPC[l].getX() + 64 &&
				x + 64 > game.v_NPC[l].getX() &&
				y < game.v_NPC[l].getY() + 64 &&
				y + 64 > game.v_NPC[l].getY() && !game.player->is_dialog)
			{
				dialog_phase = game.v_NPC[l].getStartDialogPhase();
				is_dialog = true;
				break;
			}
		}
	}
	void eventPickItem(auto& game) {
		auto& items = game.entity_manager->v_items;
		auto& cis = game.renderer->sprite_manager->current_item_sprites;
		auto& sprites = game.renderer->sprite_manager->InventoryItemsSprite;
		for (int i = 0; i < items.size(); i++) {
			float x_m = items[i].getX()/1 - range*64;
			float x_p = items[i].getX()/1 + range*64;
			float y_m = items[i].getY()/1 - range*64;
			float y_p = items[i].getY()/1 + range*64;
			if (x_m <= game.player->getX() && game.player->getX() <= x_p &&
				y_m <= game.player->getY() && game.player->getY() <= y_p) {
				for (int j = 0; j < 24; j++) {
					if (inv_items[j] == 0) {
						inv_items[j] = items[i].getID();
						inv_types[j] = items[i].getType();
						sprites[j] = cis[items[i].getSprite()];
						sprites[j].setTextureRect(IntRect(0, 0, 56, 56));
						sprites[j].setScale(1.5, 1.5);
						for (int k = 0; k < items.size(); k++) {
							if (k > i) {
								items[k].setSprite(items[k].getID() - 1);
							}
						}
						cis.erase(cis.begin() + items[i].getSprite());
						items.erase(items.begin() + i);
						game.renderer->sprite_manager->item_sprite_counter--;
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
		game.renderer->text_info.setString("");
		float out = game.player->getX() - (962 - Mouse::getPosition().x);
		float outy = game.player->getY() - (544 - Mouse::getPosition().y);
		float vx = game.window_manager->viewGetCenterX() + 261;
		float vy = game.window_manager->viewGetCenterY() - 343;
		if (is_inventory_open) {
			for (int i = 0; i < 6; i++) {
				vx = game.window_manager->viewGetCenterX() + 261;
				for (int j = 0; j < 4; j++) {
					if (inv_items[i * 4 + j] != 0) {
						if (vx/1 <= out && out <= vx/1 + 56 && vy/1 <= outy && outy <= vy/1 + 56) {
							auto& sprites = game.renderer->sprite_manager->InventoryItemsSprite;
							auto& empty = game.renderer->sprite_manager->InventoryItemEmptySprite;
							auto px = game.player->getX();
							auto py = game.player->getY();
							sprites[i * 4 + j] = empty;
							game.entity_manager->createItem(px, py, inv_items[i * 4 + j], game);
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
	void mouseInventory(auto& game) {
		float out = game.player->getX() - (962 - Mouse::getPosition().x);
		float outy = game.player->getY() - (544 - Mouse::getPosition().y);
		float vx = game.window_manager->viewGetCenterX() + 261;
		float vy = game.window_manager->viewGetCenterY() - 343;
		if (is_inventory_open) {
			auto& sprites = game.renderer->sprite_manager->InventoryItemsSprite;
			auto& eq_sprites = game.renderer->sprite_manager->GuiEquipmentSprites;
			auto& empty = game.renderer->sprite_manager->InventoryItemEmptySprite;
			game.renderer->text_info.setString("");
			for (int i = 0; i < 6; i++) {
				vx = game.window_manager->viewGetCenterX() + 261;
				for (int j = 0; j < 4; j++) {
					if (vx/1 <= out && out <= vx/1 + 56 && vy/1 <= outy && outy <= vy/1 + 56) {
						if (inv_types[i * 4 + j] == 7 && inv_items[24] == 0) { //other1
							sprites[24] = sprites[i * 4 + j];
							sprites[i * 4 + j] = empty;
							inv_items[24] = inv_items[i * 4 + j];
							inv_items[i * 4 + j] = 0;
							inv_types[i * 4 + j] = 0;
						}
						if (inv_types[i * 4 + j] == 7 && inv_items[25] == 0) { //other2
							sprites[25] = sprites[i * 4 + j];
							sprites[i * 4 + j] = empty;
							inv_items[25] = inv_items[i * 4 + j];
							inv_items[i * 4 + j] = 0;
							inv_types[i * 4 + j] = 0;
						}
						if (inv_types[i * 4 + j] == 7 && inv_items[26] == 0) { //other3
							sprites[26] = sprites[i * 4 + j];
							sprites[i * 4 + j] = empty;
							inv_items[26] = inv_items[i * 4 + j];
							inv_items[i * 4 + j] = 0;
							inv_types[i * 4 + j] = 0;
						}
							if (inv_types[i * 4 + j] == 1 && inv_items[27] == 0) { //weapon
							eq_sprites[0] = sprites[i * 4 + j];
							sprites[i * 4 + j] = empty;
							inv_items[27] = inv_items[i * 4 + j];
							inv_items[i * 4 + j] = 0;
							inv_types[i * 4 + j] = 0;
							setWeaponStats(game.renderer->sprite_manager, inv_items);
						}
						if (inv_types[i * 4 + j] == 2 && inv_items[28] == 0) { //shield
							eq_sprites[1] = sprites[i * 4 + j];
							sprites[i * 4 + j] = empty;
							inv_items[28] = inv_items[i * 4 + j];
							inv_items[i * 4 + j] = 0;
							inv_types[i * 4 + j] = 0;
						}
						if (inv_types[i * 4 + j] == 3 && inv_items[29] == 0) { //helmet
							eq_sprites[2] = sprites[i * 4 + j];
							sprites[i * 4 + j] = empty;
							inv_items[29] = inv_items[i * 4 + j];
							inv_items[i * 4 + j] = 0;
							inv_types[i * 4 + j] = 0;
						}
						if (inv_types[i * 4 + j] == 4 && inv_items[30] == 0) { //chestplate
							eq_sprites[3] = sprites[i * 4 + j];
							sprites[i * 4 + j] = empty;
							inv_items[30] = inv_items[i * 4 + j];
							inv_items[i * 4 + j] = 0;
							inv_types[i * 4 + j] = 0;
						}
						if (inv_types[i * 4 + j] == 5 && inv_items[31] == 0) { //pants
							eq_sprites[4] = sprites[i * 4 + j];
							sprites[i * 4 + j] = empty;
							inv_items[31] = inv_items[i * 4 + j];
							inv_items[i * 4 + j] = 0;
							inv_types[i * 4 + j] = 0;
						}
						if (inv_types[i * 4 + j] == 6 && inv_items[32] == 0) { //boots
							eq_sprites[5] = sprites[i * 4 + j];
							sprites[i * 4 + j] = empty;
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
				vx = game.window_manager->viewGetCenterX() - 203;
				vy = game.window_manager->viewGetCenterY() + 185;
				if (vx/1 <= out && out <= vx/1 + 56 && vy/1 <= outy && outy <= vy/1 + 56) {
					for (int j = 0; j < 24; j++) {
						if (inv_items[j] == 0) {
							sprites[j] = sprites[24];
							sprites[24] = empty;
							inv_items[j] = inv_items[24];
							inv_types[j] = 7;
							inv_items[24] = 0;
						}
					}
				}
			}
			if (inv_items[25] != 0) {
				vx = game.window_manager->viewGetCenterX() - 71;
				vy = game.window_manager->viewGetCenterY() + 185;
				if (vx/1 <= out && out <= vx/1 + 56 && vy/1 <= outy && outy <= vy/1 + 56) {
					for (int j = 0; j < 24; j++) {
						if (inv_items[j] == 0) {
							sprites[j] = sprites[25];
							sprites[25] = empty;
							inv_items[j] = inv_items[25];
							inv_types[j] = 7;
							inv_items[25] = 0;
						}
					}
				}
			}
			if (inv_items[26] != 0) {
				vx = game.window_manager->viewGetCenterX() + 61;
				vy = game.window_manager->viewGetCenterY() + 185;
				if (vx/1 <= out && out <= vx/1 + 56 && vy/1 <= outy && outy <= vy/1 + 56) {
					for (int j = 0; j < 24; j++) {
						if (inv_items[j] == 0) {
							sprites[j] = sprites[26];
							sprites[26] = empty;
							inv_items[j] = inv_items[26];
							inv_types[j] = 7;
							inv_items[26] = 0;
						}
					}
				}
			}
			if (inv_items[27] != 0) {
				vx = game.window_manager->viewGetCenterX() - 231;
				vy = game.window_manager->viewGetCenterY() - 227;
				if (vx/1 <= out && out <= vx/1 + 56 && vy/1 <= outy && outy <= vy/1 + 56) {
					for (int j = 0; j < 24; j++) {
						if (inv_items[j] == 0) {
							sprites[j] = sprites[0];
							sprites[0] = empty;
							inv_items[j] = inv_items[27];
							inv_types[j] = 1;
							inv_items[27] = 0;
							eq_sprites[0] = createSprite("GuiSlotWeapon.png");
							eq_sprites[0].setTextureRect(IntRect(0, 0, 116, 116));
							break;
						}
					}
				}
				setWeaponStats(game.renderer->sprite_manager, inv_items);
			}
			if (inv_items[28] != 0) {
				vx = game.window_manager->viewGetCenterX() + 89;
				vy = game.window_manager->viewGetCenterY() - 227;
				if (vx/1 <= out && out <= vx/1 + 56 && vy/1 <= outy && outy <= vy/1 + 56) {
					for (int j = 0; j < 24; j++) {
						if (inv_items[j] == 0) {
							sprites[j] = eq_sprites[1];
							eq_sprites[1] = empty;
							inv_items[j] = inv_items[28];
							inv_types[j] = 2;
							inv_items[28] = 0;
							eq_sprites[1] = createSprite("GuiSlotShield.png");
							eq_sprites[1].setTextureRect(IntRect(0, 0, 116, 116));
							break;
						}
					}
				}
			}
			if (inv_items[29] != 0) {
				vx = game.window_manager->viewGetCenterX() - 71;
				vy = game.window_manager->viewGetCenterY() - 351;
				if (vx/1 <= out && out <= vx/1 + 56 && vy/1 <= outy && outy <= vy/1 + 56) {
					for (int j = 0; j < 24; j++) {
						if (inv_items[j] == 0) {
							sprites[j] = eq_sprites[2];
							eq_sprites[2] = empty;
							inv_items[j] = inv_items[29];
							inv_types[j] = 3;
							inv_items[29] = 0;
							eq_sprites[2] = createSprite("GuiSlotHelm.png");
							eq_sprites[2].setTextureRect(IntRect(0, 0, 116, 116));
							break;
						}
					}
				}
			}
			if (inv_items[30] != 0) {
				vx = game.window_manager->viewGetCenterX() - 71;
				vy = game.window_manager->viewGetCenterY() - 227;
				if (vx/1 <= out && out <= vx/1 + 56 && vy/1 <= outy && outy <= vy/1 + 56) {
					for (int j = 0; j < 24; j++) {
						if (inv_items[j] == 0) {
							sprites[j] = eq_sprites[3];
							eq_sprites[3] = empty;
							inv_items[j] = inv_items[30];
							inv_types[j] = 4;
							inv_items[30] = 0;
							eq_sprites[3] = createSprite("GuiSlotChest.png");
							eq_sprites[3].setTextureRect(IntRect(0, 0, 116, 116));
							break;
						}
					}
				}
			}
			if (inv_items[31] != 0) {
				vx = game.window_manager->viewGetCenterX() - 71;
				vy = game.window_manager->viewGetCenterY() - 103;
				if (vx/1 <= out && out <= vx/1 + 56 && vy/1 <= outy && outy <= vy/1 + 56) {
					for (int j = 0; j < 24; j++) {
						if (inv_items[j] == 0) {
							sprites[j] = eq_sprites[4];
							eq_sprites[4] = empty;
							inv_items[j] = inv_items[31];
							inv_types[j] = 5;
							inv_items[31] = 0;
							eq_sprites[4] = createSprite("GuiSlotPants.png");
							eq_sprites[4].setTextureRect(IntRect(0, 0, 116, 116));
							break;
						}
					}
				}
			}
			if (inv_items[32] != 0) {
				vx = game.window_manager->viewGetCenterX() - 71;
				vy = game.window_manager->viewGetCenterY() + 21;
				if (vx/1 <= out && out <= vx/1 + 56 && vy/1 <= outy && outy <= vy/1 + 56) {
					for (int j = 0; j < 24; j++) {
						if (inv_items[j] == 0) {
							sprites[j] = eq_sprites[5];
							eq_sprites[5] = empty;
							inv_items[j] = inv_items[32];
							inv_types[j] = 6;
							inv_items[32] = 0;
							eq_sprites[5] = createSprite("GuiSlotBoots.png");
							eq_sprites[5].setTextureRect(IntRect(0, 0, 116, 116));
							break;
						}
					}
				}
			}
		}
		if (is_spells_inventory_open) {
			float vx = game.window_manager->viewGetCenterX() + 231 + 15;
			float vy = game.window_manager->viewGetCenterY() - 373 + 30;
			for (int i = 0; i < 6; i++) {
				vx = game.window_manager->viewGetCenterX() + 231 + 15;
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
			vy = game.window_manager->viewGetCenterY() + 384 + 15;
			for (int i = 0; i < 9; i++) {
				vx = game.window_manager->viewGetCenterX() - 536 + 15 + 112 * i;
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
	}
	void ifs(auto& game) { //split into several methods
		float out = game.player->getX() - (962 - Mouse::getPosition().x);
		float outy = game.player->getY() - (544 - Mouse::getPosition().y);
		if (is_inventory_open) {
			float vx = game.window_manager->viewGetCenterX() + 261;
			float vy = game.window_manager->viewGetCenterY() - 343;
			for (int i = 0; i < 6; i++) {
				vx = game.window_manager->viewGetCenterX() + 261;
				for (int j = 0; j < 4; j++) {
					if (vx/1 - 25 <= out && out <= vx/1 + 80 && vy/1 - 25 <= outy && outy <= vy/1 + 80) {
						setInfo(true, inv_items[i * 4 + j], game.renderer->text_info);
						game.renderer->sprite_manager->GuiInfoSprite.setPosition(out - 10, outy);
						game.renderer->text_info.setPosition(out, outy + 15);
						is_info = true;
					}
					vx += 112;
				}
				vy += 112;
			}
		}
		if (is_spells_inventory_open) {
			float vx = game.window_manager->viewGetCenterX() + 261;
			float vy = game.window_manager->viewGetCenterY() - 343;
		    for (int i = 0; i < 6; i++) {
		    	vx = game.window_manager->viewGetCenterX() + 261;
			    for (int j = 0; j < 4; j++) {
					if (vx/1 - 25 <= out && out <= vx/1 + 80 && vy/1 - 25 <= outy && outy <= vy/1 + 80) {
						setInfo(false, inv_spells[i * 4 + j], game.renderer->text_info);
						game.renderer->sprite_manager->GuiInfoSprite.setPosition(out - 10, outy);
						game.renderer->text_info.setPosition(out, outy + 15);
						is_info = true;
					}
				    vx += 112;
		    	}
			    vy += 112;
		    }
		}

		float vx = game.window_manager->viewGetCenterX() - 506;
		float vy = game.window_manager->viewGetCenterY() + 414;
		for (int i = 0; i < 9; i++) {
			if (vx/1 - 30 <= out && out <= vx/1 + 80 && vy/1 - 30 <= outy && outy <= vy/1 + 80 && hotbar_spells[i] != 0) {
				setInfo(false, hotbar_spells[i], game.renderer->text_info);
				game.renderer->sprite_manager->GuiInfoSprite.setPosition(vx - 34, vy - 270);
				game.renderer->text_info.setPosition(vx - 24, vy - 270 + 15);
				is_info = true;
			}
			vx += 112;
		}

		vx = game.window_manager->viewGetCenterX() - 940;
		vy = game.window_manager->viewGetCenterY() - 480;
		if (vx/1 <= out && out <= vx/1 + 170 && vy/1 <= outy && outy <= vy/1 + 100) {
			game.renderer->text_strength.setString("Strength: " + std::to_string(game.player->strength));
			game.renderer->text_damage.setString("Damage: " + std::to_string(game.player->damage));
			game.renderer->text_armor.setString("Armor: " + std::to_string(game.player->armor));
			game.renderer->text_magic.setString("Magic: " + std::to_string(game.player->magic));
			game.renderer->text_critical_chance.setString("Critical Chance: " + std::to_string(static_cast<int>(game.player->critical_chance)) + "%");
			game.renderer->text_magic_resistance.setString("Magic Resistance: " + std::to_string(static_cast<int>(game.player->magic_resistance)) + "%");
			game.renderer->text_physical_resistance.setString("Physical Resistance: " + std::to_string(static_cast<int>(game.player->physical_resistance)) + "%");
			game.renderer->text_magic_ice.setString("Magic Ice: " + std::to_string(game.player->magic_ice));
			game.renderer->text_magic_fire.setString("Magic Fire: " + std::to_string(game.player->magic_fire));
			game.renderer->text_magic_earth.setString("Magic Earth: " + std::to_string(game.player->magic_earth));
			game.renderer->text_magic_wind.setString("Magic Wind: " + std::to_string(game.player->magic_wind));
			game.renderer->text_magic_dark.setString("Magic Dark: " + std::to_string(game.player->magic_dark));
			game.renderer->text_magic_light.setString("Magic Light: " + std::to_string(game.player->magic_light));
			game.renderer->text_melee_weapon.setString("Melee Weapon: " + std::to_string(game.player->melee_weapon));
			game.renderer->text_range_weapon.setString("Range Weapon: " + std::to_string(game.player->range_weapon));
			is_stats_open = true;
		} else {
			game.renderer->text_strength.setString("");
			game.renderer->text_damage.setString("");
			game.renderer->text_armor.setString("");
			game.renderer->text_magic.setString("");
			game.renderer->text_critical_chance.setString("");
			game.renderer->text_magic_resistance.setString("");
			game.renderer->text_physical_resistance.setString("");
			game.renderer->text_magic_ice.setString("");
			game.renderer->text_magic_fire.setString("");
			game.renderer->text_magic_earth.setString("");
			game.renderer->text_magic_wind.setString("");
			game.renderer->text_magic_dark.setString("");
			game.renderer->text_magic_light.setString("");
			game.renderer->text_melee_weapon.setString("");
			game.renderer->text_range_weapon.setString("");
			is_stats_open = false;
		}

		if (!is_info) {
			game.renderer->text_info.setString("");
		}
	}
	void moveCurrentFrame(auto& time) {
        current_frame += 0.005 * time;
        if (current_frame > 4) {
            current_frame -= 4;
        }
    }
};
