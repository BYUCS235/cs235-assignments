#pragma once

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::cout, std::endl;

#include <chrono>

#ifdef ANSI
#define SWAP cout << "\033[32m";
#define POS cout << "\033[48;5;7m";
#define CLOSE cout << "\033[0m";
#else
#define SWAP
#define CLOSE
#define POS
#endif

#ifdef VERBOSE
#define PRINT(x, k, i, j) handy::print(x, k, i, j);
#else
#define PRINT(x, k, i, j)
#endif

namespace handy
{
    template <class T>
    void swap(T &a, T&b) {
        T tmp = a;
        a = b;
        b = tmp;
    }
    
    /*
        Print out everything in the vector on a single line
    */
    template <class T>
    void print(vector<T> const &stuff, int key_pos = -1, int swap_i = -1, int swap_j = -1)
    {
        for (int pos = 0; pos < stuff.size(); pos++)
        {
            // ANSI codes
            if (pos == key_pos)
            {
                POS;
            }
            if (pos == swap_i || pos == swap_j)
            {
                SWAP;
            }

            // Print item
            cout << stuff[pos];

            // Reset ANSI codes            
            if (pos == key_pos || pos == swap_i || pos == swap_j)
            {
                CLOSE;
            }
            cout << " ";
        }
        cout << endl;
    }

    class Timer
    {
        bool started;
        bool running;
        std::__1::chrono::steady_clock::time_point start_time;
        std::__1::chrono::steady_clock::time_point end_time;

    public:
        Timer() : started(false), running(false) {}

        void start()
        {
            start_time = std::chrono::high_resolution_clock::now();
            started = true;
            running = true;
        }

        void stop()
        {
            end_time = std::chrono::high_resolution_clock::now();
            running = false;
        }

        template <class duration>
        long long time() const
        {
            return std::chrono::duration_cast<duration>(((running) ? std::chrono::high_resolution_clock::now() : end_time) - start_time).count();
        }

        long long nanoseconds() const
        {
            return time<std::chrono::nanoseconds>();
        }

        long long milliseconds() const
        {
            return time<std::chrono::milliseconds>();
        }
    };
}
