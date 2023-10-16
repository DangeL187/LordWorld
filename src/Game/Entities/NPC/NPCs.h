#include "NPC.h"

class Trader: public NPC {
public:
    Trader(float& x_, float& y_, float& w_, float& h_, unsigned int& id_, int& sprite):
    NPC(x_, y_, w_, h_, 1, sprite) {
        name = "Trader";
        start_dialog_phases.push_back(0);
        start_dialog_phases.push_back(3);
        start_dialog_phases.push_back(4);
        end_dialog_phases.push_back(3);
        end_dialog_phases.push_back(4);
        end_dialog_phases.push_back(5);
        dialog.push_back("I'm gay!");
        dialog.push_back("I'm not kidding!");
        dialog.push_back("And you?");
        dialog.push_back("Get the fuck away, man!");
        dialog.push_back("Why are you gay?");
    }
};
