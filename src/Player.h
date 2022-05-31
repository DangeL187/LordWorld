class Player {
public:
	float x, y;
    float w, h, dx, dy, speed;
    int dir = 0;
    Image image;
    Texture texture;

	bool key_a = false, key_d = false, key_w = false, key_s = false;
	bool key_e = false, key_g = false;
	bool key_m1 = false, key_m2 = false;
	bool key_1 = false, key_2 = false, key_3 = false, key_4 = false;
	bool key_5 = false, key_6 = false, key_7 = false, key_8 = false, key_9 = false;
	bool key_shift = false, key_space = false;
	bool is_info = false;
	bool break4items = false;

    Player(float X, float Y, float W, float H) {
		dx=0;dy=0;speed=0;
		w = W; h = H;
		image.loadFromFile("../images/hero.png");
		texture.loadFromImage(image);
		herosprite.setTexture(texture);
		x = X; y = Y;
		herosprite.setTextureRect(IntRect(0, 0, w, h));
	}

    void interactionWithMap(auto get_v2) {
	    for (int i = y / 64; i < (y + h) / 64; i++) {
	        for (int j = x / 64; j < (x + w) / 64; j++) {
				for (int l = 0; l < get_v2.size(); l++) {
					if (x < get_v2[l].getX() + 54 &&
					    x + 50 > get_v2[l].getX() &&
					    y < get_v2[l].getY() + 62 &&
					    y + 62 > get_v2[l].getY())
					{
						if (dy>0) y = i * 64 + 4;
				        if (dy<0) y = i * 64 + 64;
				        if (dx>0) x = j * 64 + 22;
				        if (dx<0) x = j * 64 + 15;
					}
				}
		        if (TileMap[i][j] == 1 || TileMap[i][j] >= 3 && TileMap[i][j] <= 31) {
			        if (dy>0) y = i * 64 - h;
			        if (dy<0) y = i * 64 + 64;
			        if (dx>0) x = j * 64 - w;
			        if (dx<0) x = j * 64 + 64;
		        }
		        if (TileMap[i][j] == 2) {
			        x = 300; y = 300;
			        TileMap[i][j] = 0;
			        //TODO: make createMonster() available to call from here
		        }
	        }
	    }
    }

    void update(float time, auto get_v) {
		switch (dir) {
			case 0: dx = speed; dy = 0; break;
			case 1: dx = -speed; dy = 0; break;
			case 2: dx = 0; dy = -speed; break;
			case 3: dx = 0; dy = speed; break;
		}

		x += dx*time;
		y += dy*time;
		speed = 0;
		interactionWithMap(get_v);
		player_x = x/1;
		player_y = y/1;
		player_dir = dir;
		herosprite.setPosition(x, y);
		setWeaponStats();
		setShieldStats();
		setHelmetStats();
		setChestplateStats();
		setPantsStats();
		setBootsStats();
		armor = armor_shield + armor_helmet + armor_chestplate + armor_pants + armor_boots;
		setOtherStats();
		if (armor_helmet == armor_chestplate && armor_chestplate == armor_pants && armor_pants == armor_boots && armor_boots != 0) {
			armor += armor_helmet;
		}
	}

	void eventNPCDialog(auto get_NPC) {
		for (int l = 0; l < get_NPC.size(); l++) {
			if (x < get_NPC[l].getX() + 64 &&
				x + 64 > get_NPC[l].getX() &&
				y < get_NPC[l].getY() + 64 &&
				y + 64 > get_NPC[l].getY())
			{
				get_NPC[l].startDialog();
				is_dialog = true;
			}
		}
	}
	void eventPickItem(auto get_monsters) {
		for (int i = 0; i < items_dropped_id.size(); i++) {
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
						for (int k = 0; k < get_monsters.size(); k++) {
							if (get_monsters[k].getMonsterSprite() > items_dropped_sprites[i]) {
								get_monsters[k].reduceMonsterSprite();
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
	}
	void eventDropItem(auto get_time) {
		text_item_info.setString("");
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
		}
	}

	void keysMove(auto get_time) {
		if (Keyboard::isKeyPressed(Keyboard::D) && !key_a && !key_w && !key_s && attack_animation == 0) {
			key_d = true;
			speed = 0.15;
			dir = 0;
			herosprite.setTextureRect(IntRect(52 * int(current_frame), 128, 50, 62));
			getPlayerCoordinateForView(x, y);
			moveCurrentFrame(get_time);
		} else { key_d = false; }
		if (Keyboard::isKeyPressed(Keyboard::A) && !key_d && !key_w && !key_s && attack_animation == 0) {
			key_a = true;
			speed = 0.15;
			dir = 1;
			herosprite.setTextureRect(IntRect(52 * int(current_frame), 64, 50, 62));
			getPlayerCoordinateForView(x, y);
			moveCurrentFrame(get_time);
		} else { key_a = false; }
		if (Keyboard::isKeyPressed(Keyboard::W) && !key_d && !key_a && !key_s && attack_animation == 0) {
			key_w = true;
			speed = 0.15;
			dir = 2;
			herosprite.setTextureRect(IntRect(52 * int(current_frame), 192, 50, 62));
			getPlayerCoordinateForView(x, y);
			moveCurrentFrame(get_time);
		} else { key_w = false; }
		if (Keyboard::isKeyPressed(Keyboard::S) && !key_d && !key_w && !key_a && attack_animation == 0) {
			key_s = true;
			speed = 0.15;
			dir = 3;
			herosprite.setTextureRect(IntRect(52 * int(current_frame), 0, 50, 62));
			getPlayerCoordinateForView(x, y);
			moveCurrentFrame(get_time);
		} else { key_s = false; }
	}
	void keyShift(auto get_time) {
		if (Keyboard::isKeyPressed(Keyboard::LShift) && attack_animation == 0) {
			key_shift = true;
			speed *= 0.5;
			defence = true;
		} else { key_shift = false; defence = false; }
	}
	void keySpace(auto get_time) {
		if (Keyboard::isKeyPressed(Keyboard::Space) && attack_animation == 0) {
			key_space = true;
			space_timer = 1000;
		} else { key_space = false; }
	}
	void keyE(auto get_time, auto get_monsters, auto get_NPC) {
		if (Keyboard::isKeyPressed(Keyboard::E) && items_dropped_id.size() != 0 && !key_g) {
			key_e = true;
			eventNPCDialog(get_NPC);
			eventPickItem(get_monsters);
		} else { key_e = false; }
	}
	void keyG(auto get_time) {
		if (Keyboard::isKeyPressed(Keyboard::G) && !key_e) {
			key_g = true;
			eventDropItem(get_time);
		} else { key_g = false; }
	}
	void keyI(auto get_time) {
		if (Keyboard::isKeyPressed(Keyboard::I)) {
			if (!is_inventory_open && !is_spells_inventory_open) {
				is_inventory_open = true;
			}
		}
	}
	void keyO(auto get_time) {
		if (Keyboard::isKeyPressed(Keyboard::O)) {
			if (!is_inventory_open && !is_spells_inventory_open) {
				is_spells_inventory_open = true;
			}
		}
	}
	void keyEscape(auto get_time) {
		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			if (is_inventory_open) {
				is_inventory_open = false;
			}
			if (is_spells_inventory_open) {
				is_spells_inventory_open = false;
			}
		}
	}

	void keys(auto get_time, auto get_monsters, auto get_NPC) {
		keysMove(get_time);
		keyShift(get_time);
		keySpace(get_time);
		keyE(get_time, get_monsters, get_NPC);
		keyG(get_time);
		keyI(get_time);
		keyO(get_time);
		keyEscape(get_time);
	}

    float getPlayerCoordinateX() {
        return x;
    }
    float getPlayerCoordinateY() {
	    return y;
    }
};
