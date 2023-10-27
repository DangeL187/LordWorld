#include "Artifact.h"

class IronRing: public Artifact {
public:
    IronRing(float x, float y):
    Artifact(x, y, 7, createSprite("Iron Ring.png")) {
        armor = 13;
        name = "Iron Ring";
        createDescription("Ring forged from high-quality iron");
    }
};
