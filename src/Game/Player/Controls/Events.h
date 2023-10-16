class Events: virtual public Initializer {
protected:
    void keysEvents(auto& entity_manager, auto& sprite_manager, auto& text_manager, auto& window_manager) {
        keyEvent(entity_manager, sprite_manager);
        keyDropItem(entity_manager, sprite_manager, window_manager, text_manager->text_info);
    }
private:
    void keyEvent(auto& entity_manager, auto& sprite_manager) {
        if (Keyboard::isKeyPressed(Keyboard::E) && !key_drop_item) {
            key_event = true;
            if (entity_manager->v_items.size() != 0) {
                eventPickUpItem(entity_manager->v_items, sprite_manager);
            }
            eventNPCDialog(entity_manager->v_NPC);
        } else { key_event = false; }
    }
    void keyDropItem(auto& entity_manager, auto& sprite_manager, auto& window_manager, auto& text_info) {
        if (Keyboard::isKeyPressed(Keyboard::G) && !key_event) {
            key_drop_item = true;
            eventDropItem(entity_manager, sprite_manager, window_manager, text_info);
        } else { key_drop_item = false; }
    }

    void eventNPCDialog(auto& npcs) {
		for (auto& npc: npcs) {
            float nx = npc.getX() - 5;
            float ny = npc.getY() - 5;
            float nw = npc.getWidth() + 10;
            float nh = npc.getHeight() + 10;
			if (isCollision(x, y, w, h, nx, ny, nw, nh) && !is_dialog) {
				dialog_phase = npc.getStartDialogPhase();
				is_dialog = true;
				break;
			}
		}
	}
	void eventPickUpItem(auto& items, auto& sprite_manager) {
        auto& current_item_sprites = sprite_manager->current_item_sprites;
        auto& inv_sprites = sprite_manager->InventoryItemsSprites;
        auto& item_sprite_counter = sprite_manager->item_sprite_counter;

		for (int i = 0; i < items.size(); i++) {
			float item_x = items[i].getX();
			float item_y = items[i].getY();
			if (isCollision(x, y, w, h, item_x, item_y, 56, 56)) {
				for (int j = 0; j < 24; j++) {
					if (inv_items[j].getID() == 0) {
						inv_items[j] = items[i];
						inv_sprites[j] = current_item_sprites[inv_items[j].getSprite()];
						inv_sprites[j].setTextureRect(IntRect(0, 0, 56, 56));
						inv_sprites[j].setScale(1.5, 1.5);
						for (int k = 0; k < items.size(); k++) {
							if (k > i) {
                                items[k].reduceSprite();
							}
						}
						current_item_sprites.erase(current_item_sprites.begin() + items[i].getSprite());
						items.erase(items.begin() + i);
						item_sprite_counter--;
                        break;
					}
				}
			}
		}
	}
	void eventDropItem(auto& entity_manager, auto& sprite_manager, auto& window_manager, auto& text_info) {
		text_info.setString("");
		float mouse_x = x - (962 - Mouse::getPosition().x);
		float mouse_y = y - (544 - Mouse::getPosition().y);
		float vx = window_manager->viewGetCenterX() + 261;
		float vy = window_manager->viewGetCenterY() - 343;
		if (is_inventory_open) {
			for (int i = 0; i < 6; i++) {
				vx = window_manager->viewGetCenterX() + 261;
				for (int j = 0; j < 4; j++) {
					if (inv_items[i * 4 + j].getID() != 0) {
						if (isInsideRectangle(mouse_x, mouse_y, vx - 25, vy - 25, 105, 105)) {
							auto& sprites = sprite_manager->InventoryItemsSprites;
							auto& empty = sprite_manager->InventoryItemEmptySprite;
							sprites[i * 4 + j] = empty;
							entity_manager->createItem(x, y, inv_items[i * 4 + j].getID(), sprite_manager);
							inv_items[i * 4 + j] = Item();
						}
					}
					vx += 112;
				}
				vy += 112;
			}
		}
	}
};
