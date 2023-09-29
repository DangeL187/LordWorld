#include "NewSprite.h"
#include "SpriteInitializer.h"
#include "SpriteLoader.h"
#include "SpriteDrawer.h"

class SpriteManager: virtual public SpriteInitializer, virtual public SpriteLoader, public SpriteDrawer {
private:
    void createMapSprite(std::shared_ptr<Map>& map) {
        map->setSprite(createSprite("map.png"));
    }
    void createItemSprites() {
        item_sprites.push_back(createSprite("Wooden Sword.png")); //TODO: take names from file
        item_sprites.push_back(createSprite("Iron Shield.png"));
        item_sprites.push_back(createSprite("Iron Helmet.png"));
        item_sprites.push_back(createSprite("Iron Chestplate.png"));
        item_sprites.push_back(createSprite("Iron Pants.png"));
        item_sprites.push_back(createSprite("Iron Boots.png"));
        item_sprites.push_back(createSprite("Iron Ring.png"));
        item_sprites.push_back(createSprite("Rat Tail.png"));
    }
    void createMonsterSprites() {
        monster_sprites.push_back(createSprite("Rat.png"));
        monster_sprites.push_back(createSprite("Rat2.png"));
    }
    void createNPCSprites() {
        NPC_sprites.push_back(createSprite("hero.png"));
    }
    void createGuiSprites() {
        gui_sprites.push_back(createSprite("GuiBar.png"));
        gui_sprites.push_back(createSprite("GuiInventory.png"));
        gui_sprites.push_back(createSprite("GuiSpellsInventory.png"));
        gui_sprites.push_back(createSprite("GuiSpellsHotbar.png"));
        gui_sprites.push_back(createSprite("GuiStats.png"));
        gui_sprites.push_back(createSprite("NPCTalk.png"));
        GuiIndicatorSprite = createSprite("GuiIndicator.png");
        GuiInfoSprite = createSprite("GuiInfo.png");
        GuiPickedSpellSprite = createSprite("GuiPickedSpell.png");
        for (auto& i: GuiNoManaSprites) {
            i = createSprite("GuiNoMana.png");
        }
    }
public:
    SpriteManager(std::shared_ptr<Map>& map) {
        AnimationWeaponSprite.setTextureRect(IntRect(0, 0, 1, 1));
        createMapSprite(map);
        createItemSprites();
        createMonsterSprites();
        createNPCSprites();
        createGuiSprites();
        initImages();
    }
};
