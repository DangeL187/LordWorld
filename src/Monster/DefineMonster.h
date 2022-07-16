class DefineNPC {
protected:
    void defineNPC(int id, auto &game, auto &sprite, auto &dialog) {
        switch (id) {
			case 1:
                sprite = game.NPC_sprites[0]; //Trader
                dialog.push_back("I'm gay!");
                dialog.push_back("I'm not kidding!");
                dialog.push_back("And you?");
                break; //replace this shit with returning array [sprite, int]
            //case 2:
                //break;
		}
    }
};
