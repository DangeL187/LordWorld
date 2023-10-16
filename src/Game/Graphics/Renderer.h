#include "Text/TextManager.h"
#include "Sprite/SpriteManager.h"

class Renderer {
private:
    void createSpriteManager(std::shared_ptr<Map>& map) {
        sprite_manager = std::make_shared<SpriteManager>(map);
    }
    void createTextManager() {
        text_manager = std::make_shared<TextManager>();
    }
public:
    std::shared_ptr<TextManager> text_manager;
    std::shared_ptr<SpriteManager> sprite_manager;

    Renderer(std::shared_ptr<Map>& map) {
        createSpriteManager(map);
        createTextManager();
    }

    void draw(auto& game) {
        sprite_manager->drawMap(game);
        sprite_manager->drawEntities(game);
        sprite_manager->drawAnimations(game);
        sprite_manager->drawInterface(game);
        text_manager->drawDialogText(game);
        sprite_manager->drawStats(game);
        text_manager->drawDynamicText(game);
        sprite_manager->drawInventory(game);
        sprite_manager->drawHotbar(game);
        sprite_manager->drawinfo(game);
        text_manager->drawStatsText(game);
    }
};
