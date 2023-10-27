class Events: virtual public Initializer {
protected:
    void keysEvents(auto& entity_manager, auto& window_manager) {
        keyEvent(entity_manager);
        keyDropItem(entity_manager, window_manager);
    }
private:
    void keyEvent(auto& entity_manager) {
        if (Keyboard::isKeyPressed(Keyboard::E) && !key_drop_item) {
            key_event = true;
            if (entity_manager->v_items.size() != 0) {
                eventPickUpItem(entity_manager->v_items);
            }
            eventNPCDialog(entity_manager->v_NPC);
        } else { key_event = false; }
    }
    void keyDropItem(auto& entity_manager, auto& window_manager) {
        if (Keyboard::isKeyPressed(Keyboard::G) && !key_event) {
            key_drop_item = true;
            eventDropItem(entity_manager, window_manager);
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
	void eventPickUpItem(auto& items) {
		for (int i = 0; i < items.size(); i++) {
			float item_x = items[i].getX();
			float item_y = items[i].getY();
			if (isCollision(x, y, w, h, item_x, item_y, 56, 56)) {
				for (int j = 0; j < 24; j++) {
					if (inv_items[j].getID() == 0) {
						inv_items[j] = items[i];
						inv_items[j].getSprite().setTextureRect(IntRect(0, 0, 56, 56));
						inv_items[j].getSprite().setScale(1.5, 1.5);
						items.erase(items.begin() + i);
                        break;
					}
				}
			}
		}
	}
	void eventDropItem(auto& entity_manager, auto& window_manager) {
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
							entity_manager->createItem(x, y, inv_items[i * 4 + j].getID());
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
