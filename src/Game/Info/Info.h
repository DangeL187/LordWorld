void setInfo(bool is_item, int get_id, auto& text_info) {
    if (is_item) {
        if (get_id == 1) {
            std::string name = "       Wooden Sword\n";
            std::string stats = " + 1 Damage\n";
            std::string lore = "\n An ordinary homemade\n sword";
            text_info.setString(name + stats + lore);
        }
        else if (get_id == 2) {
            std::string name = "       Iron Shield\n";
            std::string stats = " + 1 Armor\n";
            std::string lore = "\n Shield forged from\n high-quality iron";
            text_info.setString(name + stats + lore);
        }
        else if (get_id == 3) {
            std::string name = "      Iron Chestplate\n";
            std::string stats = " + 1 Armor\n";
            std::string lore = "\n Chestplate forged from\n high-quality iron";
            text_info.setString(name + stats + lore);
        }
        else if (get_id == 4) {
            std::string name = "       Iron Helmet\n";
            std::string stats = " + 1 Armor\n";
            std::string lore = "\n Helmet forged from\n high-quality iron";
            text_info.setString(name + stats + lore);
        }
        else if (get_id == 5) {
            std::string name = "       Iron Pants\n";
            std::string stats = " + 1 Armor\n";
            std::string lore = "\n Pants forged from\n high-quality iron";
            text_info.setString(name + stats + lore);
        }
        else if (get_id == 6) {
            std::string name = "       Iron Boots\n";
            std::string stats = " + 1 Armor\n";
            std::string lore = "\n Boots forged from\n high-quality iron";
            text_info.setString(name + stats + lore);
        }
        else if (get_id == 7) {
            std::string name = "        Iron Ring\n";
            std::string stats = " + 1 Armor\n";
            std::string lore = "\n Ring forged from\n high-quality iron";
            text_info.setString(name + stats + lore);
        }
        else if (get_id == 8) {
            std::string name = "         Rat Tail\n";
            std::string stats = " Stinking rat tail\n";
            std::string lore = "\n Can be used for some\n potions";
            text_info.setString(name + stats + lore);
        }
    } else {
        if (get_id == 1) {
            std::string name = "        Cold Snap\n";
            std::string info = " If the enemy takes damage,\n he will get bonus damage\n";
            std::string lore = "\n The unknown power of cold";
            text_info.setString(name + info + lore);
        }
        else if (get_id == 2) {
            std::string name = "       Cold Snap2\n";
            std::string info = " If the enemy takes damage,\n he will get bonus damage\n";
            std::string lore = "\n The unknown power of cold";
            text_info.setString(name + info + lore);
        }
    }
}
