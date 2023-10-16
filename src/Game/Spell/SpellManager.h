#include "Spells.h"

class SpellManager {
private:
    float callSpellMethod(auto& game, auto& spell, int method) {
        switch (method) {
            case 0: {
                spell.cast(game);
                break;
            }
            case 1: {
                return spell.getManacost();
                break;
            }
        }
        return 0;
    }
public:
    SpellManager() = default;

    float defineSpell(auto& game, int method=0) {
        switch (game.player->spell_id) {
            case 1: {
                ColdSnap spell(game);
                return callSpellMethod(game, spell, method);
                break;
            }
            case 2: {
                ColdSnap2 spell(game);
                return callSpellMethod(game, spell, method);
                break;
            }
        }
        return 0;
    }

    void castSpell(auto& game) {
        if (game.player->cooldowns[game.player->spell_slot] == 0) {
            defineSpell(game);
        }
    }
    float getSpellManacost(auto& game) {
        return defineSpell(game, 1);
    }
};
