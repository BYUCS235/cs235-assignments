#pragma once

#include <chrono>

class Timer {
    bool started;
    bool running;
    std::__1::chrono::steady_clock::time_point start_time;
    std::__1::chrono::steady_clock::time_point end_time;

public:
    Timer() : started(false), running(false) {}

    void start() {
        start_time = std::chrono::high_resolution_clock::now();
        started = true;
        running = true;
    }

    void stop() {
        end_time = std::chrono::high_resolution_clock::now();
        running = false;
    }

    template <class duration>
    long long time() const {
        return std::chrono::duration_cast<duration>(((running) ? std::chrono::high_resolution_clock::now() : end_time) - start_time).count();
    }

    long long nanoseconds() const {
        return time<std::chrono::nanoseconds>();
    }

    long long milliseconds() const {
        return time<std::chrono::milliseconds>();
    }
};
