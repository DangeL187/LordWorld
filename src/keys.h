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

if (Keyboard::isKeyPressed(Keyboard::E) && items_dropped_id.size() != 0 && !key_g) {
	key_e = true;
	for (int i = 0; i < items_dropped_id.size(); i++) {
	    float condx_m = items_dropped_x[i]/1 - range*64;
	    float condx_p = items_dropped_x[i]/1 + range*64;
		float condy_m = items_dropped_y[i]/1 - range*64;
		float condy_p = items_dropped_y[i]/1 + range*64;
	    if (condx_m <= player_x && player_x <= condx_p && condy_m <= player_y && player_y <= condy_p) {
            for (int j = 0; j < 24; j++) {
                if (inv_items[j] == 0) {
				    inv_items[j] = items_dropped_id[i];
					inv_types[j] = items_dropped_type[i];
					InventoryItemsSprite[j] = other_sprites[items_dropped_sprites[i]];
					InventoryItemsSprite[j].setTextureRect(IntRect(0, 0, 56, 56));
					InventoryItemsSprite[j].setScale(1.5, 1.5);
					std::cout << "!!! " << inv_items[j] << std::endl; //TEMP, TODO: DELETE
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
	}
} else { key_e = false; }
if (Keyboard::isKeyPressed(Keyboard::G) && !key_e) {
	key_g = true;
	int out = player_x - (962 - Mouse::getPosition().x);
	int outy = player_y - (544 - Mouse::getPosition().y);
	int vx = view.getCenter().x + 261;
	int vy = view.getCenter().y - 343;
	if (is_inventory_open) {
		for (int i = 0; i < 6; i++) {
			vx = view.getCenter().x + 261;
			for (int j = 0; j < 4; j++) {
		        if (inv_items[i * 4 + j] != 0) {
					if (vx/1 <= out && out <= vx/1 + 56 && vy/1 <= outy && outy <= vy/1 + 56) {
			            std::cout << "DROP\n";
			            InventoryItemsSprite[i * 4 + j] = InventoryItemEmptySprite;
			            createItem(inv_items[i * 4 + j], player_x, player_y);
		                inv_items[i * 4 + j] = 0;
						inv_types[i * 4 + j] = 0;
				    }
	            }
				vx += 112;
	        }
			vy += 112;
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
	int out = player_x - (962 - Mouse::getPosition().x);
	int outy = player_y - (544 - Mouse::getPosition().y);
	int vx = view.getCenter().x + 261;
	int vy = view.getCenter().y - 343;
	if (is_inventory_open) {
		for (int i = 0; i < 6; i++) {
			vx = view.getCenter().x + 261;
			for (int j = 0; j < 4; j++) {
				if (vx/1 <= out && out <= vx/1 + 56 && vy/1 <= outy && outy <= vy/1 + 56) {
					if (inv_types[i * 4 + j] == 7 && inv_items[24] == 0) { //other1
			            std::cout << "EQUIP\n";
						InventoryItemsSprite[24] = InventoryItemsSprite[i * 4 + j];
			            InventoryItemsSprite[i * 4 + j] = InventoryItemEmptySprite;
						inv_items[24] = inv_items[i * 4 + j];
						inv_items[i * 4 + j] = 0;
						inv_types[i * 4 + j] = 0;
				    }
					if (inv_types[i * 4 + j] == 7 && inv_items[25] == 0) { //other2
			            std::cout << "EQUIP\n";
						InventoryItemsSprite[25] = InventoryItemsSprite[i * 4 + j];
			            InventoryItemsSprite[i * 4 + j] = InventoryItemEmptySprite;
						inv_items[25] = inv_items[i * 4 + j];
						inv_items[i * 4 + j] = 0;
						inv_types[i * 4 + j] = 0;
				    }
					if (inv_types[i * 4 + j] == 7 && inv_items[26] == 0) { //other3
			            std::cout << "EQUIP\n";
						InventoryItemsSprite[26] = InventoryItemsSprite[i * 4 + j];
			            InventoryItemsSprite[i * 4 + j] = InventoryItemEmptySprite;
						inv_items[26] = inv_items[i * 4 + j];
						inv_items[i * 4 + j] = 0;
						inv_types[i * 4 + j] = 0;
				    }
				    if (inv_types[i * 4 + j] == 1 && inv_items[27] == 0) { //weapon
			            std::cout << "EQUIP\n";
						InventoryItemWeaponSprite = InventoryItemsSprite[i * 4 + j];
			            InventoryItemsSprite[i * 4 + j] = InventoryItemEmptySprite;
						inv_items[27] = inv_items[i * 4 + j];
						inv_items[i * 4 + j] = 0;
						inv_types[i * 4 + j] = 0;
				    }
					if (inv_types[i * 4 + j] == 2 && inv_items[28] == 0) { //shield
						std::cout << "EQUIP\n";
						InventoryItemShieldSprite = InventoryItemsSprite[i * 4 + j];
			            InventoryItemsSprite[i * 4 + j] = InventoryItemEmptySprite;
						inv_items[28] = inv_items[i * 4 + j];
						inv_items[i * 4 + j] = 0;
						inv_types[i * 4 + j] = 0;
					}
					if (inv_types[i * 4 + j] == 3 && inv_items[29] == 0) { //helmet
						std::cout << "EQUIP\n";
						InventoryItemHelmSprite = InventoryItemsSprite[i * 4 + j];
			            InventoryItemsSprite[i * 4 + j] = InventoryItemEmptySprite;
						inv_items[29] = inv_items[i * 4 + j];
						inv_items[i * 4 + j] = 0;
						inv_types[i * 4 + j] = 0;
					}
					if (inv_types[i * 4 + j] == 4 && inv_items[30] == 0) { //chestplate
						std::cout << "EQUIP\n";
						InventoryItemChestSprite = InventoryItemsSprite[i * 4 + j];
			            InventoryItemsSprite[i * 4 + j] = InventoryItemEmptySprite;
						inv_items[30] = inv_items[i * 4 + j];
						inv_items[i * 4 + j] = 0;
						inv_types[i * 4 + j] = 0;
					}
					if (inv_types[i * 4 + j] == 5 && inv_items[31] == 0) { //pants
						std::cout << "EQUIP\n";
						InventoryItemPantsSprite = InventoryItemsSprite[i * 4 + j];
			            InventoryItemsSprite[i * 4 + j] = InventoryItemEmptySprite;
						inv_items[31] = inv_items[i * 4 + j];
						inv_items[i * 4 + j] = 0;
						inv_types[i * 4 + j] = 0;
					}
					if (inv_types[i * 4 + j] == 6 && inv_items[32] == 0) { //boots
						std::cout << "EQUIP\n";
						InventoryItemBootsSprite = InventoryItemsSprite[i * 4 + j];
			            InventoryItemsSprite[i * 4 + j] = InventoryItemEmptySprite;
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
			vx = view.getCenter().x - 203;
			vy = view.getCenter().y + 185;
			if (vx/1 <= out && out <= vx/1 + 56 && vy/1 <= outy && outy <= vy/1 + 56) {
				std::cout << "UNEQUIP\n";
				for (int j = 0; j < 24; j++) {
					if (inv_items[j] == 0) {
				        InventoryItemsSprite[j] = InventoryItemsSprite[24];
				        InventoryItemsSprite[24] = InventoryItemEmptySprite;
						inv_items[j] = inv_items[24];
						inv_types[j] = 7;
				        inv_items[24] = 0;
					}
				}
			}
		}
		if (inv_items[25] != 0) {
			vx = view.getCenter().x - 71;
			vy = view.getCenter().y + 185;
			if (vx/1 <= out && out <= vx/1 + 56 && vy/1 <= outy && outy <= vy/1 + 56) {
				std::cout << "UNEQUIP\n";
				for (int j = 0; j < 24; j++) {
					if (inv_items[j] == 0) {
				        InventoryItemsSprite[j] = InventoryItemsSprite[25];
				        InventoryItemsSprite[25] = InventoryItemEmptySprite;
						inv_items[j] = inv_items[25];
						inv_types[j] = 7;
				        inv_items[25] = 0;
					}
				}
			}
		}
		if (inv_items[26] != 0) {
			vx = view.getCenter().x + 61;
			vy = view.getCenter().y + 185;
			if (vx/1 <= out && out <= vx/1 + 56 && vy/1 <= outy && outy <= vy/1 + 56) {
				std::cout << "UNEQUIP\n";
				for (int j = 0; j < 24; j++) {
					if (inv_items[j] == 0) {
				        InventoryItemsSprite[j] = InventoryItemsSprite[26];
				        InventoryItemsSprite[26] = InventoryItemEmptySprite;
						inv_items[j] = inv_items[26];
						inv_types[j] = 7;
				        inv_items[26] = 0;
					}
				}
			}
		}
		if (inv_items[27] != 0) {
			vx = view.getCenter().x - 231;
			vy = view.getCenter().y - 227;
			if (vx/1 <= out && out <= vx/1 + 56 && vy/1 <= outy && outy <= vy/1 + 56) {
				std::cout << "UNEQUIP\n";
				for (int j = 0; j < 24; j++) {
					if (inv_items[j] == 0) {
				        InventoryItemsSprite[j] = InventoryItemWeaponSprite;
				        InventoryItemWeaponSprite = InventoryItemEmptySprite;
						inv_items[j] = inv_items[27];
						inv_types[j] = 1;
				        inv_items[27] = 0;
						InventoryItemWeaponSprite.setTexture(InventoryItemWeaponTexture);
						InventoryItemWeaponSprite.setTextureRect(IntRect(0, 0, 116, 115));
						break;
					}
				}
			}
		}
		if (inv_items[28] != 0) {
			vx = view.getCenter().x + 89;
			vy = view.getCenter().y - 227;
			if (vx/1 <= out && out <= vx/1 + 56 && vy/1 <= outy && outy <= vy/1 + 56) {
				std::cout << "UNEQUIP\n";
				for (int j = 0; j < 24; j++) {
					if (inv_items[j] == 0) {
				        InventoryItemsSprite[j] = InventoryItemShieldSprite;
				        InventoryItemShieldSprite = InventoryItemEmptySprite;
						inv_items[j] = inv_items[28];
						inv_types[j] = 2;
				        inv_items[28] = 0;
						InventoryItemShieldSprite.setTexture(InventoryItemShieldTexture);
						InventoryItemShieldSprite.setTextureRect(IntRect(0, 0, 116, 115));
						break;
					}
				}
			}
		}
		if (inv_items[29] != 0) {
			vx = view.getCenter().x - 71;
			vy = view.getCenter().y - 351;
			if (vx/1 <= out && out <= vx/1 + 56 && vy/1 <= outy && outy <= vy/1 + 56) {
				std::cout << "UNEQUIP\n";
				for (int j = 0; j < 24; j++) {
					if (inv_items[j] == 0) {
				        InventoryItemsSprite[j] = InventoryItemHelmSprite;
				        InventoryItemHelmSprite = InventoryItemEmptySprite;
						inv_items[j] = inv_items[29];
						inv_types[j] = 3;
				        inv_items[29] = 0;
						InventoryItemHelmSprite.setTexture(InventoryItemHelmTexture);
						InventoryItemHelmSprite.setTextureRect(IntRect(0, 0, 116, 115));
						break;
					}
				}
			}
		}
		if (inv_items[30] != 0) {
			vx = view.getCenter().x - 71;
			vy = view.getCenter().y - 227;
			if (vx/1 <= out && out <= vx/1 + 56 && vy/1 <= outy && outy <= vy/1 + 56) {
				std::cout << "UNEQUIP\n";
				for (int j = 0; j < 24; j++) {
					if (inv_items[j] == 0) {
				        InventoryItemsSprite[j] = InventoryItemChestSprite;
				        InventoryItemChestSprite = InventoryItemEmptySprite;
						inv_items[j] = inv_items[30];
						inv_types[j] = 4;
				        inv_items[30] = 0;
						InventoryItemChestSprite.setTexture(InventoryItemChestTexture);
						InventoryItemChestSprite.setTextureRect(IntRect(0, 0, 116, 115));
						break;
					}
				}
			}
		}
		if (inv_items[31] != 0) {
			vx = view.getCenter().x - 71;
			vy = view.getCenter().y - 103;
			if (vx/1 <= out && out <= vx/1 + 56 && vy/1 <= outy && outy <= vy/1 + 56) {
				std::cout << "UNEQUIP\n";
				for (int j = 0; j < 24; j++) {
					if (inv_items[j] == 0) {
				        InventoryItemsSprite[j] = InventoryItemPantsSprite;
				        InventoryItemPantsSprite = InventoryItemEmptySprite;
						inv_items[j] = inv_items[31];
						inv_types[j] = 5;
				        inv_items[31] = 0;
						InventoryItemPantsSprite.setTexture(InventoryItemPantsTexture);
						InventoryItemPantsSprite.setTextureRect(IntRect(0, 0, 116, 115));
						break;
					}
				}
			}
		}
		if (inv_items[32] != 0) {
			vx = view.getCenter().x - 71;
			vy = view.getCenter().y + 21;
			if (vx/1 <= out && out <= vx/1 + 56 && vy/1 <= outy && outy <= vy/1 + 56) {
				std::cout << "UNEQUIP\n";
				for (int j = 0; j < 24; j++) {
					if (inv_items[j] == 0) {
				        InventoryItemsSprite[j] = InventoryItemBootsSprite;
				        InventoryItemBootsSprite = InventoryItemEmptySprite;
						inv_items[j] = inv_items[32];
						inv_types[j] = 6;
				        inv_items[32] = 0;
						InventoryItemBootsSprite.setTexture(InventoryItemBootsTexture);
						InventoryItemBootsSprite.setTextureRect(IntRect(0, 0, 116, 115));
						break;
					}
				}
			}
		}
	}
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
