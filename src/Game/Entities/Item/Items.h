class RatTail: public Item {
public:
    RatTail(float x, float y):
    Item(x, y, 8, createSprite("Rat Tail.png")) {
        type = 8; //item
        name = "Rat Tail";
        createDescription(" Stinking rat tail\n\n Can be used for some\n potions", true);
    }
};
