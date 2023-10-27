class Timer {
private:
    bool auto_restart = false;
    float duration = -1;
    float time_passed = 0;
    float time_left = -1;
    std::chrono::time_point<std::chrono::system_clock> start;
    std::chrono::time_point<std::chrono::system_clock> end;
public:
    Timer() = default;

    void run(float duration_) {
        duration = duration_;
        time_passed = 0;
        start = std::chrono::high_resolution_clock::now();
    }

    void update() {
        if (time_passed <= duration) {
            end = std::chrono::high_resolution_clock::now();
            time_passed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        }
        time_left = duration - time_passed;
        if (time_left <= 0) {
            time_left = 0;
        }
    }

    float getTime() {
        update();
        return time_left;
    }

    bool isRunning() {
        return (getTime() > 0);
    }
    bool isOver() {
        return (getTime() == 0);
    }

    ~Timer() {}
};
