int createItem(int ID, float get_x, float get_y) {
    items_dropped_id.push_back(ID);
    items_dropped_x.push_back(get_x);
    items_dropped_y.push_back(get_y);
    items_dropped_sprites.push_back(sprite_counter);
    #include "item_types.h"

    other_sprites[sprite_counter].setTextureRect(IntRect(0, 0, 56, 56));
    other_sprites[sprite_counter].setScale(0.75, 0.75);
    other_sprites[sprite_counter].setPosition(get_x, get_y);
    sprite_counter++;

    return ID;
}