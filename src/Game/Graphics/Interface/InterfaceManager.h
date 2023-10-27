#include "InterfaceElement.h"
#include "InterfaceElements/InterfaceBar.h"
#include "InterfaceElements/InterfaceHotbar.h"
#include "InterfaceElements/InterfaceInventory.h"
#include "InterfaceElements/InterfaceInfo.h"
#include "InterfaceElements/InterfaceStats.h"
#include "InterfaceElements/InterfaceDialog.h"
#include "InterfaceElements/InterfaceDynamicText.h"
#include "InterfaceElements/InterfaceIndicator.h"
#include "InterfaceElements/InterfaceTarget.h"

class InterfaceManager {
public:
    InterfaceBar         interface_bar;
    InterfaceDialog      interface_dialog;
    InterfaceDynamicText interface_dynamic_text;
    InterfaceHotbar      interface_hotbar;
    InterfaceIndicator   interface_indicator;
    InterfaceInfo        interface_info;
    InterfaceInventory   interface_inventory;
    InterfaceStats       interface_stats;
    InterfaceTarget      interface_target;

    void update(std::shared_ptr<WindowManager>& window_manager, std::shared_ptr<Player>& player) {
        interface_bar.update(window_manager, player);
        interface_hotbar.update(window_manager, player);
        interface_indicator.update(player->getX(), player->getY());
        interface_inventory.update(window_manager, player);
        interface_info.update(interface_hotbar, interface_inventory, player);
        interface_stats.update(window_manager, player);
        interface_dialog.update(window_manager);
        interface_dynamic_text.update();
        interface_target.update(window_manager);
    }

    void draw(std::shared_ptr<WindowManager>& window_manager, std::shared_ptr<Player>& player) {
        interface_bar.draw(window_manager);
        interface_hotbar.draw(window_manager, player->is_aiming);
        interface_indicator.draw(window_manager, player->critical_timer);
        interface_inventory.draw(window_manager, player);
        interface_info.draw(window_manager);
        interface_stats.draw(window_manager);
        interface_dialog.draw(window_manager, player);
        interface_dynamic_text.draw(window_manager);
        interface_target.draw(window_manager);
    }
};
