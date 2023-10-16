#include "TimeUpdater.h"
#include "MonsterUpdater.h"
#include "NPCUpdater.h"
#include "TextUpdater.h"
#include "SpriteUpdater.h"

class UpdateManager: public TimeUpdater, protected MonsterUpdater, protected NPCUpdater, protected TextUpdater, protected SpriteUpdater {
public:
    UpdateManager() = default;

    void update(auto& game) {
        time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 800;

        updateTimers(game);
        updateText(time, game);
        game.player->update(time, game);
        updateSprites(game);
        updateMonsters(time, game);
        updateNPCs(time, game);
        game.window_manager->viewSetCenter(game.player->getX(), game.player->getY());
    }

    float getTime() {
        return time;
    }
};
