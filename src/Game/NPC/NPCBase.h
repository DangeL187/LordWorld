class NPCBase {
protected:
    float x, y;
	float w, h, dx, dy, speed;
	int dir = 0;
	int static_sprite;
    int start_dialog_phase = 0;
    int end_dialog_phase = 0;
	std::vector<int> start_dialog_phases;
	std::vector<int> end_dialog_phases;
	std::vector<std::string> dialog;
	std::string name;
	Image image;
	Texture texture;
	Sprite sprite;
protected:
    void defineNPC(std::string name, auto& NPC_sprites_, auto& sprite, auto& dialog) {
        if (name == "Trader") {
            sprite = NPC_sprites_[0]; //Trader
            start_dialog_phases.push_back(0);
            start_dialog_phases.push_back(3);
            start_dialog_phases.push_back(4);
            end_dialog_phases.push_back(3);
            end_dialog_phases.push_back(4);
            end_dialog_phases.push_back(5);
            dialog.push_back("I'm gay!");
            dialog.push_back("I'm not kidding!");
            dialog.push_back("And you?");
            dialog.push_back("Get the fuck away, man!");
            dialog.push_back("Why are you gay?");
            /*dialog.push_back("1) I'm something of a gay myself\n2) I'm not gay!!!\n3) Why are you gay?");
            dialog.push_back("Cool!");
            dialog.push_back("Why you are not gay?");
            dialog.push_back("Who is gay?");*/
		}
    }
};
