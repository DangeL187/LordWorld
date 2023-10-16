class Buff {
protected:
    std::string name;
    std::shared_ptr<Timer> buff_timer;
public:
    Buff(float duration) {
        buff_timer = std::make_shared<Timer>();
        buff_timer->run(duration);
    }

    float getBuffTime() {
        return buff_timer->getTime();
    }
};
