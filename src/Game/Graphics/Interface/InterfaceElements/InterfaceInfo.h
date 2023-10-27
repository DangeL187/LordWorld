class InterfaceInfo: public InterfaceElement {
private:
    bool is_info = false;
    float mouse_x = 0;
    float mouse_y = 0;
    Font font;
    Text text_info;
    Sprite InfoSprite;
public:
    InterfaceInfo():
    InterfaceElement() {
        font.loadFromFile("../font/font.ttf");
        setText(text_info, font, 18);
        InfoSprite = createSprite("GuiInfo.png");
    }

    void update(InterfaceHotbar& interface_hotbar, InterfaceInventory& interface_inventory, std::shared_ptr<Player>& player) {
        is_info = false;
        mouse_x = player->getX() - (962 - Mouse::getPosition().x);
        mouse_y = player->getY() - (544 - Mouse::getPosition().y);
        setHotbarInfo(interface_hotbar, player);
        if (player->is_inventory_open) {
            setItemInfo(interface_inventory, player);
        }
        if (!is_info) {
            text_info.setString("");
        }
    }

    void draw(std::shared_ptr<WindowManager>& window_manager) {
        if (is_info) {
            window_manager->windowDraw(InfoSprite);
        }
        window_manager->windowDraw(text_info);
    }
private:
    void setItemInfo(InterfaceInventory& interface_inventory, std::shared_ptr<Player>& player) {
        Vector2f interface_pos(interface_inventory.getX() - 10, interface_inventory.getY() - 10);
        for (int i = 0; i < 24; i++) {
            Vector2f item_pos = interface_pos + interface_inventory.getInvItemsPos(i);
            if (isInsideRectangle(mouse_x, mouse_y, item_pos, 105, 105) && player->inv_items[i].getID() != 0) {
                text_info.setString(player->inv_items[i].getDescription());
                InfoSprite.setPosition(item_pos + Vector2f(116, -56));
                text_info.setPosition(item_pos + Vector2f(116 + 10, -56 + 15));
                is_info = true;
                break;
            }
        }
    }
    void setHotbarInfo(InterfaceHotbar& interface_hotbar, std::shared_ptr<Player>& player) {
        float spell_x = interface_hotbar.getX() + 4;
        float spell_y = interface_hotbar.getY() + 4;
        for (int i = 0; i < 9; i++) {
            if (isInsideRectangle(mouse_x, mouse_y, spell_x, spell_y, 105, 105) && player->hotbar_spells[i]->getID() != 0) {
                text_info.setString(player->hotbar_spells[i]->getDescription());
                InfoSprite.setPosition(spell_x, spell_y - 240);
                text_info.setPosition(spell_x + 10, spell_y - 240 + 15);
                is_info = true;
                break;
            }
            spell_x += 112;
        }
    }
};
