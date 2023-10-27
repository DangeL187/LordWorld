class Item {
protected:
    float x, y;
    int id;
    int type;
    Sprite sprite;
    //armor:
    int armor = 0;
    //weapon:
    int damage = 0;
    int weapon_type = 0;
    Sprite animation_sprite;
    //description:
    std::string name = "";
    std::string description = "";

    void createDescription(std::string lore, bool custom_description=false, int length=28) {
        int spaces = int((length - name.length()) / 2);
        std::string left(spaces, ' ');
        std::string first_line = left + name + "\n";

        std::string stats_lines = "";
        if (damage != 0) {
            stats_lines += getStatLine(damage, "damage");
        } else if (armor != 0) {
            stats_lines += getStatLine(armor, "armor");
        }

        if (!custom_description) {
            description = first_line + stats_lines + formalize(lore);
        } else {
            description = first_line + lore;
        }
    }
public:
    Item(float x_=0, float y_=0, unsigned int id_=0, Sprite sprite_=Sprite()) {
        x = x_;
        y = y_;
        id = id_;
        sprite = sprite_;
        sprite.setScale(0.75, 0.75);
        sprite.setPosition(x, y);
    }

    unsigned int getID() {
        return id;
    }
    int& getType() {
        return type;
    }
    float getX() {
        return x;
    }
    float getY() {
        return y;
    }
    std::string getDescription() {
        return description;
    }

    int getArmor() {
        return armor;
    }

    int getDamage() {
        return damage;
    }
    int getWeaponType() {
        return weapon_type;
    }
    Sprite& getAnimationSprite() {
        return animation_sprite;
    }
    Sprite& getSprite() {
        return sprite;
    }
private:
    std::string getStatLine(int stat, std::string stat_name) {
        std::string minus(int(stat < 0), '-');
        std::string plus(int(stat > 0), '+');
        return " " + minus + plus + std::to_string(stat) + " " + stat_name + "\n";
    }
    std::string formalize(std::string text, int length=28) {
        std::string formalized = "";
        std::string line = " ";
        for (auto& word: split(text, ' ')) {
            if ((line.length() + word.length() + 1) <= length) {
                line += word + " ";
            } else {
                formalized += "\n" + line;
                line = " " + word + " ";
            }
        }
        formalized += "\n" + line + "\n";
        return formalized;
    }
};
