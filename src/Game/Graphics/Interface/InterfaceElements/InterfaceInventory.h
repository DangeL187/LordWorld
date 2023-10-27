class InterfaceInventory: public InterfaceElement {
private:
    Vector2f inv_items_pos[33];
    float mouse_x = 0; // TODO: replace x and y pairs with Vector2f
    float mouse_y = 0;
    Font font;
    Sprite InventorySprite;
    Sprite SlotSprites[6];
public:
    InterfaceInventory():
    InterfaceElement() {
        initRelativePositions();
        font.loadFromFile("../font/font.ttf");
        InventorySprite = createSprite("GuiInventory.png");
        SlotSprites[0] = createSprite("GuiSlotWeapon.png");
        SlotSprites[1] = createSprite("GuiSlotShield.png");
        SlotSprites[2] = createSprite("GuiSlotHelm.png");
        SlotSprites[3] = createSprite("GuiSlotChest.png");
        SlotSprites[4] = createSprite("GuiSlotPants.png");
        SlotSprites[5] = createSprite("GuiSlotBoots.png");
    }

    void update(std::shared_ptr<WindowManager>& window_manager, std::shared_ptr<Player>& player) {
        x = window_manager->viewGetCenterX() - 300;
        y = window_manager->viewGetCenterY() - 400;
        InventorySprite.setPosition(x, y);

        for (int i = 0; i <= 32; i++) {
            if (i >= 27) {
                float num = 15 + 14 * int(player->inv_items[i].getID() == 0); // if id == 0: num = 15; else: num = 29;
                player->inv_items[i].getSprite().setPosition(Vector2f(x - num, y - num) + inv_items_pos[i]);
            } else {
                player->inv_items[i].getSprite().setPosition(Vector2f(x, y) + inv_items_pos[i]);
            }
        }
    }

    void draw(std::shared_ptr<WindowManager>& window_manager, std::shared_ptr<Player>& player) {
        if (player->is_inventory_open) {
            window_manager->windowDraw(InventorySprite);
            for (auto& item: player->inv_items) {
                window_manager->windowDraw(item.getSprite());
            }
        }
    }

    void event(std::shared_ptr<Player>& player) {
        mouse_x = player->getX() - (962 - Mouse::getPosition().x);
		mouse_y = player->getY() - (544 - Mouse::getPosition().y);
        if (player->is_inventory_open) {
            eventEquipItem(player);
            eventUnequipItem(player);
        }
    }

    Vector2f getInvItemsPos(int index) {
        return inv_items_pos[index];
    }
private:
    void eventEquipItem(std::shared_ptr<Player>& player) {
        for (int i = 0; i < 24; i++) {
            if (isInsideRectangle(mouse_x, mouse_y, Vector2f(x - 10, y - 10) + inv_items_pos[i], 105, 105) && player->inv_items[i].getID() != 0) {
                for (int k = 24; k <= 32; k++) {
                    if (player->inv_items[i].getType() == player->inv_items[k].getType() && player->inv_items[k].getID() == 0) {
                        player->inv_items[k] = player->inv_items[i]; //eq item = inv_item
                        player->inv_items[i] = Item(); //delete item from inv
                        break;
                    }
                }
            }
        }
    }
    void eventUnequipItem(std::shared_ptr<Player>& player) {
        for (int k = 24; k <= 32; k++) {
            if (isInsideRectangle(mouse_x, mouse_y, Vector2f(x - 10, y - 10) + inv_items_pos[k], 105, 105) && player->inv_items[k].getID() != 0) {
                for (int i = 0; i < 24; i++) {
                    if (player->inv_items[i].getID() == 0) {
                        player->inv_items[i] = player->inv_items[k]; // inv_item = eq_item
                        player->inv_items[k] = Item(); // delete eq_item
                        player->inv_items[k].getType() = player->inv_items[i].getType(); // set empty eq_item's type back to it's type
                        if (k >= 27) {
                            player->inv_items[k].getSprite() = SlotSprites[k - 27];
                        } else {
                            player->inv_items[k].getSprite() = Sprite();
                        }
                        break;
                    }
                }
            }
        }
    }
    void initRelativePositions() {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 4; j++) {
                inv_items_pos[i * 4 + j] = Vector2f(561 - 15 + 112 * j, 57 - 15 + 112 * i);
            }
        }
        for (int i = 24; i <= 32; i++) {
            if (i < 27) {
                inv_items_pos[i] = Vector2f(97 - 15 + 132 * (i - 24), 585 - 15);
            } else {
                int ix = 1 - int(i-27 == 0) + int(i-27 == 1); // if i-27 == 0: ix = 0; if i-27 == 1: ix = 2;
                int iy = pow(i - 29, int(i-27 > 1)); // if i-27 < 1: iy = 1; else: iy = i-29;
                inv_items_pos[i] = Vector2f(69 + 160 * ix, 49 + 124 * iy);
            }
        }
    }
};
