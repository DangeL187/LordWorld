class SpriteLoader: virtual public SpriteInitializer {
public:
    int loadItemSprite(float x, float y, unsigned int id) {
        current_item_sprites.push_back(item_sprites[id-1]);
        current_item_sprites[item_sprite_counter].setTextureRect(IntRect(0, 0, 56, 56));
        current_item_sprites[item_sprite_counter].setScale(0.75, 0.75);
        current_item_sprites[item_sprite_counter].setPosition(x, y);
        item_sprite_counter++;
        return item_sprite_counter - 1;
    }

    int loadMonsterSprite(float x, float y, float w, float h, unsigned int id) {
        current_other_sprites.push_back(monster_sprites[id-1]);
        current_other_sprites[other_sprite_counter].setTextureRect(IntRect(0, 0, w, h));
        current_other_sprites[other_sprite_counter].setPosition(x, y);
        other_sprite_counter++;
        return other_sprite_counter - 1;
    }
};
