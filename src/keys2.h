/*void keyD(auto get_player, auto get_time) {
	if (Keyboard::isKeyPressed(Keyboard::D) && !key_a && !key_w && !key_s && attack_animation == 0) {
		key_d = true;
		get_player.speed = 0.15;
		get_player.dir = 0;
		herosprite.setTextureRect(IntRect(52 * int(current_frame), 128, 50, 62));
		getPlayerCoordinateForView(get_player.getPlayerCoordinateX(), getP.getPlayerCoordinateY());
		moveCurrentFrame(get_time);
	} else { key_d = false; }
}

void keys(auto get_player, auto get_time) {
	bool key_a = false, key_d = false, key_w = false, key_s = false;
	bool key_e = false, key_g = false;
	bool key_m1 = false, key_m2 = false;
	bool key_1 = false, key_2 = false, key_3 = false, key_4 = false;
	bool key_5 = false, key_6 = false, key_7 = false, key_8 = false, key_9 = false;
	bool key_shift = false, key_space = false;
	bool is_info = false;
	bool break4items = false;

	keyD(get_player, get_time);
}*/

class Keys {
	bool key_a = false, key_d = false, key_w = false, key_s = false;
	bool key_e = false, key_g = false;
	bool key_m1 = false, key_m2 = false;
	bool key_1 = false, key_2 = false, key_3 = false, key_4 = false;
	bool key_5 = false, key_6 = false, key_7 = false, key_8 = false, key_9 = false;
	bool key_shift = false, key_space = false;
	bool is_info = false;
	bool break4items = false;
public:
	void keyD(auto get_player, auto get_time) {
		if (Keyboard::isKeyPressed(Keyboard::D) && !key_a && !key_w && !key_s && attack_animation == 0) {
			key_d = true;
			get_player.speed = 0.15;
			get_player.dir = 0;
			herosprite.setTextureRect(IntRect(52 * int(current_frame), 128, 50, 62));
			getPlayerCoordinateForView(get_player.getPlayerCoordinateX(), get_player.getPlayerCoordinateY());
			moveCurrentFrame(get_time);
		} else { key_d = false; }
	}

	Keys(auto get_player, auto get_time) {
		keyD(get_player, get_time);
	}
};
