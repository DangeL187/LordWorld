#include "DynamicText.h"
#include "DrawManager.h"
#include "Interface/InterfaceManager.h"

class Renderer: protected DrawManager {
public:
    std::shared_ptr<InterfaceManager> interface_manager;

    Renderer() {
        createInterfaceManager();
    }

    void draw(auto& game) {
        drawMap(game.window_manager, game.map);
        drawEntities(game.window_manager, game.entity_manager, game.player);
        drawAnimations(game.window_manager, game.player);

        interface_manager->draw(game.window_manager, game.player);
    }
private:
    void createInterfaceManager() {
        interface_manager = std::make_shared<InterfaceManager>();
    }
};
