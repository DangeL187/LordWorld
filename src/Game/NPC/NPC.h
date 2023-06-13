#include "NPCBase.h"

class NPC: public NPCBase {
public:
	NPC(float x_, float y_, float w_, float h_, std::string name_, auto& NPC_sprites_, auto& other_sprite_counter_, auto& current_other_sprites_) {
		dx=0; dy=0; speed=0;
		w = w_; h = h_;
		name = name_;
    	static_sprite = other_sprite_counter_;
		defineNPC(name, NPC_sprites_, sprite, dialog);
		current_other_sprites_.push_back(sprite);
		x = x_; y = y_;
		current_other_sprites_[static_sprite].setTextureRect(IntRect(1, 1, w, h));
		other_sprite_counter_++;
	}

	void interactionWithMap(auto& map_manager) {
	    for (int i = y / 64; i < (y + h) / 64; i++) {
	        for (int j = x / 64; j < (x + w) / 64; j++) {
				auto t = map_manager.getTileMapID(i, j);
		        if (t == 4) {
			        if (dy>0) y = i * 64 - h;
			        if (dy<0) y = i * 64 + 64;
			        if (dx>0) x = j * 64 - w;
			        if (dx<0) x = j * 64 + 64;
		        }
		        if (t == 5) {
			        x = 300; y = 300;
					map_manager.setTileMapID(i, j, 0);
		        }
	        }
		}
    }

    void update(auto& time, auto& map_manager, auto& game) {
		switch (dir) {
		    case 0: dx = speed; dy = 0; break;
		    case 1: dx = -speed; dy = 0; break;
		    case 2: dx = 0; dy = -speed; break;
		    case 3: dx = 0; dy = speed; break;
		}

		x += dx*time;
		y += dy*time;

		speed = 0;
		interactionWithMap(map_manager);
		updateDialog(game);
		game.current_other_sprites[static_sprite].setPosition(x, y);
	}

    void updateDialog(auto& game) {
		if (game.player->is_dialog) {
			if (game.player->dialog_phase == end_dialog_phases[end_dialog_phase]) {
				if (end_dialog_phase+1 != end_dialog_phases.size()) {
					start_dialog_phase++;
					end_dialog_phase++;
				}
				game.text_NPC_talk.setString("");
				game.player->is_dialog = false;
			} else {
				game.text_NPC_talk.setString(dialog[game.player->dialog_phase]);
			}
		} else {
			game.text_NPC_talk.setString("");
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
	std::string getName() {
		return name;
	}
};
