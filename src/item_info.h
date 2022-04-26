void setItemInfo(int get_id) {
    if (get_id == 1) {
        std::string name = "       Wooden Sword\n";
        std::string stats = " + 1 Damage\n";
        std::string lore = "\n An ordinary homemade\n sword";
        text_item_info.setString(name + stats + lore);
    }
    else if (get_id == 2) {
        std::string name = "      Iron Chestplate\n";
        std::string stats = " + 1 Armor\n";
        std::string lore = "\n Chestplate forged from\n high-quality iron";
        text_item_info.setString(name + stats + lore);
    }
    else if (get_id == 3) {
        std::string name = "       Iron Shield\n";
        std::string stats = " + 1 Armor\n";
        std::string lore = "\n Shield forged from\n high-quality iron";
        text_item_info.setString(name + stats + lore);
    }
    else if (get_id == 4) {
        std::string name = "       Iron Helmet\n";
        std::string stats = " + 1 Armor\n";
        std::string lore = "\n Helmet forged from\n high-quality iron";
        text_item_info.setString(name + stats + lore);
    }
    else if (get_id == 5) {
        std::string name = "       Iron Pants\n";
        std::string stats = " + 1 Armor\n";
        std::string lore = "\n Pants forged from\n high-quality iron";
        text_item_info.setString(name + stats + lore);
    }
    else if (get_id == 6) {
        std::string name = "       Iron Boots\n";
        std::string stats = " + 1 Armor\n";
        std::string lore = "\n Boots forged from\n high-quality iron";
        text_item_info.setString(name + stats + lore);
    }
    else if (get_id == 7) {
        std::string name = "        Iron Ring\n";
        std::string stats = " + 1 Armor\n";
        std::string lore = "\n Ring forged from\n high-quality iron";
        text_item_info.setString(name + stats + lore);
    }
}
