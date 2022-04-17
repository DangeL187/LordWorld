class Player {
public:
	float x, y;
    float w, h, dx, dy, speed;
    int dir = 0;
    Image image;
    Texture texture;

    Player(float X, float Y, float W, float H) {
		dx=0;dy=0;speed=0;
		w = W; h = H;
		image.loadFromFile("../images/hero.png");
		texture.loadFromImage(image);
		herosprite.setTexture(texture);
		x = X; y = Y;
		herosprite.setTextureRect(IntRect(0, 0, w, h));
	}

    void interactionWithMap() {
	    for (int i = y / 64; i < (y + h) / 64; i++)
	    for (int j = x / 64; j<(x + w) / 64; j++) {
		if (TileMap[i][j] == '0') {
			if (dy>0) y = i * 64 - h;
			if (dy<0) y = i * 64 + 64;
			if (dx>0) x = j * 64 - w;
			if (dx<0) x = j * 64 + 64;
		}
		if (TileMap[i][j] == 's') {
			x = 300; y = 300;
			TileMap[i][j] = ' ';
		}
	    }
    }

    void update(float time) {  // one more parameter with player's number!
		switch (dir) {
		case 0: dx = speed; dy = 0; break;
		case 1: dx = -speed; dy = 0; break;
		case 2: dx = 0; dy = -speed; break;
		case 3: dx = 0; dy = speed; break;
		}

		x += dx*time;
		y += dy*time;

		speed = 0;
		interactionWithMap();
		player_x = x/1;
		player_y = y/1;
		herosprite.setPosition(x, y);
	}

    float getPlayerCoordinateX() {
        return x;
    }
    float getPlayerCoordinateY() {
	    return y;
    }
};

class Monster {
public:
	float x, y;
	float w, h, dx, dy, speed;
	int dir = 0;
	int dmg, hp, mp, lvl;
	int static_sprite = sprite_counter;
	std::string name;
	std::vector<std::string> buffs;
	std::vector<int> timers; //spells timers
	Image image;
	Texture texture;
	Sprite sprite;
	bool dealt = false;

	Monster(float X, float Y, float W, float H, std::string NAME) {
		dx=0;dy=0;speed=0;
		w = W; h = H;
		name = NAME;
		#include "monsters.h"
		image.loadFromFile("../images/" + NAME + ".png");
		std::cout << NAME << std::endl;
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		other_sprites.push_back(sprite);
		x = X; y = Y;
		other_sprites[static_sprite].setTextureRect(IntRect(0, 0, w, h));
		sprite_counter++;
	}

	void interactionWithMap() {
	    for (int i = y / 64; i < (y + h) / 64; i++) {
	        for (int j = x / 64; j < (x + w) / 64; j++) {
		        if (TileMap[i][j] == '0') {
			        if (dy>0) y = i * 64 - h;
			        if (dy<0) y = i * 64 + 64;
			        if (dx>0) x = j * 64 - w;
			        if (dx<0) x = j * 64 + 64;
		        }
		        if (TileMap[i][j] == 's') {
			        x = 300; y = 300;
			        TileMap[i][j] = ' ';
		        }
	        }
	    }
    }

    void update(float time) { //TODO: move checkbuff here
		switch (dir) {
		    case 0: dx = speed; dy = 0; break;
		    case 1: dx = -speed; dy = 0; break;
		    case 2: dx = 0; dy = -speed; break;
		    case 3: dx = 0; dy = speed; break;
		}

		x += dx*time;
		y += dy*time;

		speed = 0;
		interactionWithMap();
		other_sprites[static_sprite].setPosition(x, y);
		checkBuff(time);
	}

	void checkBuff(float globaltime) {
		for (int v = 0; v < buffs.size(); v++) {
			#include "buffs.h"
			#include "timers.h"
			if (timers[v] <= 0) {
				buffs.erase(buffs.begin() + v);
		        timers.erase(timers.begin() + v);
			}
		}
	}
	void hitMonster(int local_dmg, float hittime) {
		hp -= local_dmg;
		dealt = true;
		checkBuff(hittime);
		dealt = false;
	}
	void giveBuff(std::string somebuff, int sometime) {
		timers.push_back(sometime);
		buffs.push_back(somebuff);
	}
	void reduceMonsterSprite() {
		static_sprite--;
	}
	int getMonsterSprite() {
		return static_sprite;
	}
	float getMonsterCoordinateX() {
        return x;
    }
    float getMonsterCoordinateY() {
	    return y;
    }
	int getMonsterHP() {
        return hp;
    }
	int getMonsterMP() {
		return mp;
	}
	int getMonsterLVL() {
		return lvl;
	}
	std::string getMonsterName() {
		return name;
	}
};
