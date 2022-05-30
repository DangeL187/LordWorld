void guiTarget() {
    if (target_m.size() != 0) {
        target_m[0] = v_monsters[target_number];
        std::stringstream ss;
        std::stringstream ss2;
        std::string t_lvl;
        std::string t_hp;
        std::string t_name;
	    ss<<target_m[0].getMonsterLVL();
	    ss>>t_lvl;
        ss2<<target_m[0].getMonsterHP();
        ss2>>t_hp;
        t_name = target_m[0].getMonsterName();
        text.setString("TARGET: " + t_name + "\nLVL: " + t_lvl + "\nHP: " + t_hp);
    } else {
        text.setString("");
    }
}
