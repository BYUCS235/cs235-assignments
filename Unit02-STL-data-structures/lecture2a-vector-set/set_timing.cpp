#include <iostream>
#include <chrono>
#include <set>
#include <unordered_set>

template <class S>
long long time_set(S& the_set, int item) {
    // Start the timer
    auto start_time = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < 1000000; ++i) {
        the_set.insert(item);
    }

    // Stop the timer
    auto end_time = std::chrono::high_resolution_clock::now();

    // Calculate the duration
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    return duration;
}

int main() {

    std::set<int> s_numbers;
    std::unordered_set<int> us_numbers;

    for (int limit = 1e3; limit < 1e8; limit *= 10) {

        for (int i = s_numbers.size(); i < limit; i++) {
            s_numbers.insert(i);
            us_numbers.insert(i);
        }

        auto s_time = time_set(s_numbers, 1);
        std::cout << "SET  insert at size " << limit << ": " << s_time << " milliseconds." << std::endl;

        auto us_time = time_set(us_numbers, 1);
        std::cout << "USET insert at size " << limit << ": " << us_time << " milliseconds." << std::endl;

    }

    return 0;
}