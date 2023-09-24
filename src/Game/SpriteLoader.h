class SpriteLoader {
public:
    SpriteLoader() = default;

    int loadItemSprite(float x, float y, unsigned int id, std::shared_ptr<Renderer>& renderer) {
        renderer->current_item_sprites.push_back(renderer->item_sprites[id-1]);
        renderer->current_item_sprites[renderer->item_sprite_counter].setTextureRect(IntRect(0, 0, 56, 56));
        renderer->current_item_sprites[renderer->item_sprite_counter].setScale(0.75, 0.75);
        renderer->current_item_sprites[renderer->item_sprite_counter].setPosition(x, y);
        renderer->item_sprite_counter++;
        return renderer->item_sprite_counter - 1;
    }

    int loadMonsterSprite(float x, float y, float w, float h, unsigned int id, std::shared_ptr<Renderer>& renderer) {
        renderer->current_other_sprites.push_back(renderer->monster_sprites[id-1]);
        renderer->current_other_sprites[renderer->other_sprite_counter].setTextureRect(IntRect(0, 0, w, h));
        renderer->current_other_sprites[renderer->other_sprite_counter].setPosition(x, y);
        renderer->other_sprite_counter++;
        return renderer->other_sprite_counter - 1;
    }
};
