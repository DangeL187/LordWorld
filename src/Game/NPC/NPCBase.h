class NPCBase {
protected:
    void defineNPC(std::string name, auto& NPC_sprites_, auto& sprite, auto& dialog) {
        if (name == "Trader") {
            sprite = NPC_sprites_[0]; //Trader
            dialog.push_back("I'm gay!");
            dialog.push_back("I'm not kidding!");
            dialog.push_back("And you?");
		}
    }
};
