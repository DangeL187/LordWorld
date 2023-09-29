class Buff {
protected:
    std::string name;
    float timer_buff = 0;
public:
    Buff(float duration) {
        timer_buff = duration;
    }

    void updateTimers(std::vector<std::reference_wrapper<float>>& timers, float time) {
        timers.push_back(timer_buff);
        for (auto& i: timers) {
            if (i.get() > 0) {
                i.get() -= time;
            } else {
                i.get() = 0;
            }
        }
    }
    float getTimer() {
        return timer_buff;
    }
};
