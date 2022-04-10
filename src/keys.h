bool key_a = false, key_d = false, key_w = false, key_s = false, key_m1 = false, key_m2 = false;
bool key_1 = false, key_2 = false, key_3 = false, key_4 = false;
bool key_i = false;
bool nums = false;
bool tempstop = true;
bool tempstop2 = true;
bool break4items = false;

if (Keyboard::isKeyPressed(Keyboard::A) && key_d == false && key_w == false && key_s == false) {
	key_a = true;
	p.dir = 1;
	p.speed = 0.15;
	CurrentFrame += 0.005*time;
	if(CurrentFrame > 3) CurrentFrame -= 3;
	herosprite.setTextureRect(IntRect(52 * int(CurrentFrame), 64, 50, 62));
	getplayercoordinateforview(p.getplayercoordinateX(), p.getplayercoordinateY());
} else { key_a = false; }
if (Keyboard::isKeyPressed(Keyboard::D) && key_a == false && key_w == false && key_s == false) {
	key_d = true;
	p.dir = 0;
	p.speed = 0.15;
	CurrentFrame += 0.005*time;
	if(CurrentFrame > 3) CurrentFrame -= 3;
	herosprite.setTextureRect(IntRect(52 * int(CurrentFrame), 128, 50, 62));
	getplayercoordinateforview(p.getplayercoordinateX(), p.getplayercoordinateY());
} else { key_d = false; }
if (Keyboard::isKeyPressed(Keyboard::W) && key_d == false && key_a == false && key_s == false) {
	key_w = true;
	p.dir = 2;
	p.speed = 0.15;
	CurrentFrame += 0.005*time;
	if(CurrentFrame > 3) CurrentFrame -= 3;
	herosprite.setTextureRect(IntRect(52 * int(CurrentFrame), 192, 50, 62));
	getplayercoordinateforview(p.getplayercoordinateX(), p.getplayercoordinateY());
} else { key_w = false; }
if (Keyboard::isKeyPressed(Keyboard::S) && key_d == false && key_w == false && key_a == false) {
	key_s = true;
	p.dir = 3;
	p.speed = 0.15;
	CurrentFrame += 0.005*time;
	if(CurrentFrame > 3) CurrentFrame -= 3;
	herosprite.setTextureRect(IntRect(52 * int(CurrentFrame), 0, 50, 62));
	getplayercoordinateforview(p.getplayercoordinateX(), p.getplayercoordinateY());
} else { key_s = false; }
if (Keyboard::isKeyPressed(Keyboard::LShift)) {
	p.speed = 0.3;
	getplayercoordinateforview(p.getplayercoordinateX(), p.getplayercoordinateY());
}
//temp:
if (Keyboard::isKeyPressed(Keyboard::L) && tempstop2) {
	inv_items[0] = item1.getid();
	item1.makeiteminvisible();
	tempstop2 = false;
}
if (Keyboard::isKeyPressed(Keyboard::K)) {
	inv_items[0] = item00.getid();
	item1.setx(200);
	item1.sety(200);
}
//
if (Keyboard::isKeyPressed(Keyboard::E)) {
	if (items_floor.size() != 0) {
	    for (int i = 0; i <= items_floor.size(); i++) {
	    	if (items_floor_x[i]/1 - range*64 <= player_x && player_x <= items_floor_x[i]/1 + range*64 && items_floor_y[i]/1 - range*64 <= player_y && player_y <= items_floor_y[i]/1 + range*64) {
                for (int j = 0; j <= 33; j++) {
            	    if (inv_items[j] == 0) {
				    	inv_items[j] = items_floor[i];
						std::cout << "!!! " << inv_items[j] << std::endl; //TEMP, TODO: DELETE
				    	items_floor.erase(items_floor.begin() + i);
						items_floor_x.erase(items_floor_x.begin() + i);
						items_floor_y.erase(items_floor_y.begin() + i);
						items_floor_sprite.erase(items_floor_sprite.begin() + i);
				    	break4items = true;
			    		break;
			    	}
                }
            }
		    if (break4items) {
		    	break4items = false;
			    break;
		    }
	    }
    }
}
if (Keyboard::isKeyPressed(Keyboard::G)) {
	if (inv_items[0] != 0) {
		std::cout << "DROP\n";
	    items_floor.push_back(inv_items[0]);
		items_floor_x.push_back(player_x);
		items_floor_y.push_back(player_y);
		items_floor_sprite.push_back(item1.getitemsprite()); //this is temp, TODO: replace with get_item_sprite_by_id();
		//TODO: create function get_item_sprite_by_id()
	    inv_items[0] = 0;
    }
}
if (Keyboard::isKeyPressed(Keyboard::I)) {
	if (!inventory_open) {
		inventory_open = true;
	}
}
if (Keyboard::isKeyPressed(Keyboard::Escape)) {
	if (inventory_open) {
		inventory_open = false;
	}
}
//
if (Keyboard::isKeyPressed(Keyboard::Num1) && key_2 == false && key_3 == false && key_4 == false) {
	key_1 = true;
} else { key_1 = false; }
//
if (Mouse::isButtonPressed(Mouse::Left)) {
	key_m1 = true;
	if (aiming) {
		aiming = false;
		#include "spells.h"
	}
	attack = 1; //first type of attack
} else { key_m1 = false; }
if (Mouse::isButtonPressed(Mouse::Right)) {
	key_m2 = true;
	aiming = false;
} else { key_m2 = false; }
//
if (!key_m1 && !key_m2) {
	attack = 0;
}
if (key_1) {
	aiming_kid = true;
}
if (!key_1 && aiming_kid) {
	spell_name = hotbar_spells[0];
	spell_slot = 0;
	aiming = true;
	aiming_kid = false;
}
if (Keyboard::isKeyPressed(Keyboard::LControl) && key_m2) {
	targeting();
}
