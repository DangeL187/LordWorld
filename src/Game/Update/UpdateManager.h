#include "TimeUpdater.h"
#include "MonsterUpdater.h"
#include "SpriteUpdater.h"

class UpdateManager: public TimeUpdater, public MonsterUpdater, protected SpriteUpdater {
private:
    void updateLVL(auto& game) {
        if (game.player->xp >= game.player->lvl * 100) {
            game.player->xp -= game.player->lvl * 100;
            game.player->lvl++;
        }
    }
    void updateNPCs(auto& time, auto& game) {
        for (auto& i: game.v_NPC) {
            i.update(time, game);
        }
    }
public:
    UpdateManager() = default;

    void update(auto& game) {
        time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time/800;
        updateTimers(game);
        updateLVL(game);
        setImages(game, 27, game.player->inv_spells, game.renderer->sprite_manager->SpellsInventorySprite);
        setImages(game, 9, game.player->hotbar_spells, game.renderer->sprite_manager->SpellsHotbarSprites);
        game.renderer->updateText(time, game);
        game.player->update(time, game);
        updateSprites(game);
        updateMonsters(time, game);
        updateNPCs(time, game);
        game.renderer->guiTarget(game);
        game.window_manager->viewSetCenter(game.player->getX(), game.player->getY());
    }

    float getTime() {
        return time;
    }
};
