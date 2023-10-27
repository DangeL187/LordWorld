#include "MonsterUpdater.h"
#include "NPCUpdater.h"

class UpdateManager: protected MonsterUpdater, protected NPCUpdater {
private:
    float time = 0;
    Clock clock;
public:
    void update(auto& game) {
        time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 800;

        game.player->update(time, game);
        game.renderer->interface_manager->update(game.window_manager, game.player);
        updateMonsters(time, game);
        updateNPCs(time, game);
        game.window_manager->viewSetCenter(game.player->getX(), game.player->getY());
    }

    float getTime() {
        return time;
    }
};
