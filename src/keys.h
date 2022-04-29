bool key_a = false, key_d = false, key_w = false, key_s = false;
bool key_e = false, key_g = false;
bool key_m1 = false, key_m2 = false;
bool key_1 = false, key_2 = false, key_3 = false, key_4 = false;
bool key_i = false;
bool is_info = false;
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
	text_item_info.setString("");
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
	if (!is_inventory_open && !is_spells_inventory_open) {
		is_inventory_open = true;
	}
}
if (Keyboard::isKeyPressed(Keyboard::O)) {
	if (!is_inventory_open && !is_spells_inventory_open) {
		is_spells_inventory_open = true;
	}
}
if (Keyboard::isKeyPressed(Keyboard::Escape)) {
	if (is_inventory_open) {
		is_inventory_open = false;
	}
	if (is_spells_inventory_open) {
		is_spells_inventory_open = false;
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
		text_item_info.setString("");
		for (int i = 0; i < 6; i++) {
			vx = view.getCenter().x + 261;
			for (int j = 0; j < 4; j++) {
				if (vx/1 <= out && out <= vx/1 + 56 && vy/1 <= outy && outy <= vy/1 + 56) {
					if (inv_types[i * 4 + j] == 7 && inv_items[24] == 0) { //other1
						InventoryItemsSprite[24] = InventoryItemsSprite[i * 4 + j];
			            InventoryItemsSprite[i * 4 + j] = InventoryItemEmptySprite;
						inv_items[24] = inv_items[i * 4 + j];
						inv_items[i * 4 + j] = 0;
						inv_types[i * 4 + j] = 0;
				    }
					if (inv_types[i * 4 + j] == 7 && inv_items[25] == 0) { //other2
						InventoryItemsSprite[25] = InventoryItemsSprite[i * 4 + j];
			            InventoryItemsSprite[i * 4 + j] = InventoryItemEmptySprite;
						inv_items[25] = inv_items[i * 4 + j];
						inv_items[i * 4 + j] = 0;
						inv_types[i * 4 + j] = 0;
				    }
					if (inv_types[i * 4 + j] == 7 && inv_items[26] == 0) { //other3
						InventoryItemsSprite[26] = InventoryItemsSprite[i * 4 + j];
			            InventoryItemsSprite[i * 4 + j] = InventoryItemEmptySprite;
						inv_items[26] = inv_items[i * 4 + j];
						inv_items[i * 4 + j] = 0;
						inv_types[i * 4 + j] = 0;
				    }
				    if (inv_types[i * 4 + j] == 1 && inv_items[27] == 0) { //weapon
						InventoryItemWeaponSprite = InventoryItemsSprite[i * 4 + j];
			            InventoryItemsSprite[i * 4 + j] = InventoryItemEmptySprite;
						inv_items[27] = inv_items[i * 4 + j];
						inv_items[i * 4 + j] = 0;
						inv_types[i * 4 + j] = 0;
				    }
					if (inv_types[i * 4 + j] == 2 && inv_items[28] == 0) { //shield
						InventoryItemShieldSprite = InventoryItemsSprite[i * 4 + j];
			            InventoryItemsSprite[i * 4 + j] = InventoryItemEmptySprite;
						inv_items[28] = inv_items[i * 4 + j];
						inv_items[i * 4 + j] = 0;
						inv_types[i * 4 + j] = 0;
					}
					if (inv_types[i * 4 + j] == 3 && inv_items[29] == 0) { //helmet
						InventoryItemHelmSprite = InventoryItemsSprite[i * 4 + j];
			            InventoryItemsSprite[i * 4 + j] = InventoryItemEmptySprite;
						inv_items[29] = inv_items[i * 4 + j];
						inv_items[i * 4 + j] = 0;
						inv_types[i * 4 + j] = 0;
					}
					if (inv_types[i * 4 + j] == 4 && inv_items[30] == 0) { //chestplate
						InventoryItemChestSprite = InventoryItemsSprite[i * 4 + j];
			            InventoryItemsSprite[i * 4 + j] = InventoryItemEmptySprite;
						inv_items[30] = inv_items[i * 4 + j];
						inv_items[i * 4 + j] = 0;
						inv_types[i * 4 + j] = 0;
					}
					if (inv_types[i * 4 + j] == 5 && inv_items[31] == 0) { //pants
						InventoryItemPantsSprite = InventoryItemsSprite[i * 4 + j];
			            InventoryItemsSprite[i * 4 + j] = InventoryItemEmptySprite;
						inv_items[31] = inv_items[i * 4 + j];
						inv_items[i * 4 + j] = 0;
						inv_types[i * 4 + j] = 0;
					}
					if (inv_types[i * 4 + j] == 6 && inv_items[32] == 0) { //boots
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

if (is_inventory_open) {
    int out = player_x - (962 - Mouse::getPosition().x);
    int outy = player_y - (544 - Mouse::getPosition().y);
	int vx = view.getCenter().x + 261;
	int vy = view.getCenter().y - 343;
    for (int i = 0; i < 6; i++) {
    	vx = view.getCenter().x + 261;
	    for (int j = 0; j < 4; j++) {
			if (vx/1 <= out && out <= vx/1 + 56 && vy/1 <= outy && outy <= vy/1 + 56) {
				setItemInfo(inv_items[i * 4 + j]);
				GuiInfoSprite.setPosition(out - 10, outy);
				text_item_info.setPosition(out, outy + 15);
				is_info = true;
			}
		    vx += 112;
    	}
	    vy += 112;
    }
}

int out = player_x - (962 - Mouse::getPosition().x);
int outy = player_y - (544 - Mouse::getPosition().y);
int vx = view.getCenter().x - 940;
int vy = view.getCenter().y - 480;
if (vx/1 <= out && out <= vx/1 + 170 && vy/1 <= outy && outy <= vy/1 + 100) {
	text_strength.setString("Strength: " + std::to_string(strength));
	text_damage.setString("Damage: " + std::to_string(damage));
	text_armor.setString("Armor: " + std::to_string(armor));
	text_magic.setString("Magic: " + std::to_string(magic));
	text_critical_chance.setString("Critical Chance: " + std::to_string(critical_chance) + "%");
	text_magic_resistance.setString("Magic Resistance: " + std::to_string(magic_resistance) + "%");
	text_physical_resistance.setString("Physical Resistance: " + std::to_string(physical_resistance) + "%");
	text_magic_ice.setString("Magic Ice: " + std::to_string(magic_ice));
	text_magic_fire.setString("Magic Fire: " + std::to_string(magic_fire));
	text_magic_earth.setString("Magic Earth: " + std::to_string(magic_earth));
	text_magic_wind.setString("Magic Wind: " + std::to_string(magic_wind));
	text_magic_dark.setString("Magic Dark: " + std::to_string(magic_dark));
	text_magic_light.setString("Magic Light: " + std::to_string(magic_light));
	text_melee_weapon.setString("Melee Weapon: " + std::to_string(melee_weapon));
	text_range_weapon.setString("Range Weapon: " + std::to_string(range_weapon));
	is_stats_open = true;
} else {
	is_stats_open = false;
	text_strength.setString("");
	text_damage.setString("");
	text_armor.setString("");
	text_magic.setString("");
	text_critical_chance.setString("");
	text_magic_resistance.setString("");
	text_physical_resistance.setString("");
	text_magic_ice.setString("");
	text_magic_fire.setString("");
	text_magic_earth.setString("");
	text_magic_wind.setString("");
	text_magic_dark.setString("");
	text_magic_light.setString("");
	text_melee_weapon.setString("");
	text_range_weapon.setString("");
}

if (!is_info) {
	text_item_info.setString("");
}
