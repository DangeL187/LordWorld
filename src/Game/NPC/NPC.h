#include "DefineNPC.h"

class NPC: public DefineNPC {
public:
	float x, y;
	float w, h, dx, dy, speed;
	int dir = 0;
	int dialog_phase = 0;
	int static_sprite;
	std::vector<std::string> dialog;
	int id;
	Image image;
	Texture texture;
	Sprite sprite;

	NPC(float x_, float y_, float w_, float h_, int id_, auto& game) {
		dx=0; dy=0; speed=0;
		w = w_; h = h_;
		id = id_;
        static_sprite = game.sprite_counter;
		defineNPC(id, game, sprite, dialog);
		game.other_sprites.push_back(sprite);
		x = x_; y = y_;
		game.other_sprites[static_sprite].setTextureRect(IntRect(0, 0, w, h));
		game.sprite_counter++;
	}

	void interactionWithMap(auto& map_manager) {
	    for (int i = y / 64; i < (y + h) / 64; i++) {
	        for (int j = x / 64; j < (x + w) / 64; j++) {
		        if (map_manager.TileMap[i][j] == 1) {
			        if (dy>0) y = i * 64 - h;
			        if (dy<0) y = i * 64 + 64;
			        if (dx>0) x = j * 64 - w;
			        if (dx<0) x = j * 64 + 64;
		        }
		        if (map_manager.TileMap[i][j] == 2) {
			        x = 300; y = 300;
			        map_manager.TileMap[i][j] = 0;
		        }
	        }
		}
    }

    void update(auto& time, auto& game, auto& map_manager) {
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
		game.other_sprites[static_sprite].setPosition(x, y);
	}

    void startDialog() {
		std::cout << dialog[dialog_phase] << std::endl;
	}
	int getNPCSprite() {
		return static_sprite;
	}
    int getNPCId() {
		return id;
	}
	float getX() {
        return x;
    }
    float getY() {
	    return y;
    }
};
