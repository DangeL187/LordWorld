class Buff {
protected:
    std::string name;
    std::shared_ptr<Timer> buff_timer;
public:
    Buff(float duration=-1) {
        if (duration != -1) {
            buff_timer = std::make_shared<Timer>();
            buff_timer->run(duration);
        }
    }

    virtual void update(bool is_dealt, int& hp, bool& stun_monster) = 0;

    float getBuffTime() {
        return buff_timer->getTime();
    }
};
