class NPC {
protected:
	float x, y;
	float w, h, dx, dy, speed;
	unsigned int id;
	int dir = 0;
	int static_sprite;
    int start_dialog_phase = 0;
    int end_dialog_phase = 0;
	std::vector<int> start_dialog_phases;
	std::vector<int> end_dialog_phases;
	std::string name;
	std::vector<std::string> dialog;
	Image image;
	Texture texture;
public:
	NPC(float x_, float y_, float w_, float h_, unsigned int id_, int sprite) {
		dx=0; dy=0; speed=0;
		x = x_; y = y_;
		w = w_; h = h_;
		id = id_;
    	static_sprite = sprite;
	}

	void interactionWithMap(auto& map) {
	    for (int i = y / 64; i < (y + h) / 64; i++) {
	        for (int j = x / 64; j < (x + w) / 64; j++) {
				auto t = map->getTileMapID(i, j);
		        if (t == 4) {
			        if (dy>0) y = i * 64 - h;
			        if (dy<0) y = i * 64 + 64;
			        if (dx>0) x = j * 64 - w;
			        if (dx<0) x = j * 64 + 64;
		        }
		        if (t == 5) {
			        x = 300; y = 300;
					map->setTileMapID(i, j, 0);
		        }
	        }
		}
    }

    void update(auto& time, auto& game) {
		switch (dir) {
		    case 0: dx = speed; dy = 0; break;
		    case 1: dx = -speed; dy = 0; break;
		    case 2: dx = 0; dy = -speed; break;
		    case 3: dx = 0; dy = speed; break;
		}

		x += dx*time;
		y += dy*time;

		speed = 0;
		interactionWithMap(game.map);
		updateDialog(game);
		game.renderer->sprite_manager->current_other_sprites[static_sprite].setPosition(x, y);
	}

    void updateDialog(auto& game) {
		if (game.player->is_dialog) {
			if (game.player->dialog_phase == end_dialog_phases[end_dialog_phase]) {
				if (end_dialog_phase + 1 != end_dialog_phases.size()) {
					start_dialog_phase++;
					end_dialog_phase++;
				}
				game.renderer->text_manager->text_NPC_talk.setString("");
				game.player->is_dialog = false;
			} else {
				game.renderer->text_manager->text_NPC_talk.setString(dialog[game.player->dialog_phase]);
			}
		} else {
			game.renderer->text_manager->text_NPC_talk.setString("");
		}
	}
	int getStartDialogPhase() {
		return start_dialog_phases[start_dialog_phase];
	}
	int getSprite() {
		return static_sprite;
	}
	float getX() {
        return x;
    }
    float getY() {
	    return y;
    }
	float getWidth() {
		return w;
	}
	float getHeight() {
		return h;
	}
	std::string getName() {
		return name;
	}
};
