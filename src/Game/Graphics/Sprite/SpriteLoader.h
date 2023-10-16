class SpriteLoader: virtual public SpriteInitializer {
private:
    int loadAliveEntitySprite(float x, float y, float w, float h, unsigned int id, std::vector<Sprite> sprites) {
        current_other_sprites.push_back(sprites[id-1]);
        current_other_sprites[other_sprite_counter].setTextureRect(IntRect(0, 0, w, h));
        current_other_sprites[other_sprite_counter].setPosition(x, y);
        other_sprite_counter++;
        return other_sprite_counter - 1;
    }
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
        return loadAliveEntitySprite(x, y, w, h, id, monster_sprites);
    }

    int loadNPCSprite(float x, float y, float w, float h, unsigned int id) {
        return loadAliveEntitySprite(x, y, w, h, id, NPC_sprites);
    }

    Sprite loadSpellSprite(int spell_id) { //temp method?
        switch (spell_id) {
			case 1: return ColdSnapSprite; break;
			case 2: return ColdSnap2Sprite; break;
		}
        return InventoryItemEmptySprite;
    }
};
