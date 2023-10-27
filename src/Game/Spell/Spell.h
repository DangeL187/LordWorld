class Spell {
protected:
    int id = 0;
    int buff_duration = 0;
    int cooldown = 0;
    int damage_from_spell = 0;
    int mana_cost = 0;
    float aoe_range = 0;
    float cast_range = 0;
    std::string name = "";
    std::string description = "";
    Sprite sprite;
public:
    Spell(int id_=0) {
        id = id_;
    }

    virtual void cast(std::vector<Monster>& monsters, int& mp, float px, float py, float pw, float ph, std::shared_ptr<Timer>& cooldowns) = 0;

    int getID() {
        return id;
    }
    int getManacost() {
        return mana_cost;
    }
    Sprite getSprite() {
        return sprite;
    }
    std::string getDescription() {
        return description;
    }

    void createDescription(std::string info, std::string lore, bool custom_description=false, int length=28) {
        int spaces = int((length - name.length()) / 2);
        std::string left(spaces, ' ');
        std::string first_line = left + name;

        if (!custom_description) {
            description = first_line + formalize(info) + "\n" + formalize(lore);
        } else {
            description = first_line + info + lore;
        }
    }
private:
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
        formalized += "\n" + line;
        return formalized;
    }
};

class NullSpell: public Spell {
public:
    NullSpell(): Spell(0) {}
    void cast(std::vector<Monster>& monsters, int& mp, float px, float py, float pw, float ph, std::shared_ptr<Timer>& cooldown_timer) override {}
};
