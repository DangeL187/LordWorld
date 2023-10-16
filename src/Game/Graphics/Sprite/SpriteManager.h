#include "NewSprite.h"
#include "SpriteInitializer.h"
#include "SpriteLoader.h"
#include "SpriteDrawer.h"

class SpriteManager: virtual public SpriteInitializer, virtual public SpriteLoader, virtual public SpriteDrawer {
public:
    SpriteManager(std::shared_ptr<Map>& map) {
        initSprites(map);
    }
};
