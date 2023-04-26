void defineItemType(int id, auto& current_item_sprites, auto& item_sprites, auto& items_dropped) {
    switch (id) {
        case 1:
            current_item_sprites.push_back(item_sprites[0]); //Wooden Sword
            items_dropped[4].push_back(1); //weapon
            break; //replace this shit with returning array [sprite, int]
        case 2:
            current_item_sprites.push_back(item_sprites[1]);
            items_dropped[4].push_back(2); //shield
            break;
        case 3:
            current_item_sprites.push_back(item_sprites[2]);
            items_dropped[4].push_back(3); //helmet
            break;
        case 4:
            current_item_sprites.push_back(item_sprites[3]);
            items_dropped[4].push_back(4); //chestplate
            break;
        case 5:
            current_item_sprites.push_back(item_sprites[4]);
            items_dropped[4].push_back(5); //pants
            break;
        case 6:
            current_item_sprites.push_back(item_sprites[5]);
            items_dropped[4].push_back(6); //boots
            break;
        case 7:
            current_item_sprites.push_back(item_sprites[6]);
            items_dropped[4].push_back(7); //ring
            break;
        case 8:
            current_item_sprites.push_back(item_sprites[7]);
            items_dropped[4].push_back(8); //item
            break;
    }
}
