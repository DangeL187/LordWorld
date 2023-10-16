class Timer {
private:
    bool should_terminate = false;
    std::thread::id thread_id;
    float duration = -1;
    float time_passed = 0;
    std::thread thread_for_updating;
    std::chrono::time_point<std::chrono::system_clock> start;
    std::chrono::time_point<std::chrono::system_clock> end;

    void updating() {
        while (time_passed < duration && !should_terminate) {
            end = std::chrono::high_resolution_clock::now();
            time_passed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        }
        should_terminate = false;
    }
public:
    Timer() = default;

    void run(float duration_) {
        stop();
        duration = duration_;
        time_passed = 0;
        start = std::chrono::high_resolution_clock::now();
        thread_for_updating = std::thread(&Timer::updating, this);
        thread_id = thread_for_updating.get_id();
        thread_for_updating.detach();
    }

    void stop() {
        if (time_passed < duration) {
            should_terminate = true;
        }
        while (thread_id == thread_for_updating.get_id() && should_terminate) {}
    }

    float getTime() {
        float time_left = duration - time_passed;
        if (time_left <= 0) {
            return 0;
        }
        return time_left;
    }

    ~Timer() {
        stop();
    }
};
