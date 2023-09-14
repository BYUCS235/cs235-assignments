#include <deque>
using std::deque;

#include <list>
using std::list;

#include <vector>
using std::vector;

#include <iostream>
using std::cout, std::endl;

#include <string>
using std::string;

#include "timing.h"

template <typename C>
void push_back(string const& message, int rounds=10, int n=1000000) {
    C container;
    Timer timer;
    timer.start();
    for (int round = 0; round < rounds; round++) {
        for (int i = 0; i < n; i++) {
            container.push_back(i);
        }
    }
    timer.stop();
    cout << message << " took " << timer.nanoseconds() / rounds / n << " ns" << endl;
}

template <typename C>
void pop_back(string const& message, int rounds=10, int n=1000000) {
    C container;
    long long time = 0;
    for (int round = 0; round < rounds; round++) {
        for (int i = 0; i < n; i++) {
            container.push_back(i);
        }
        Timer timer;
        timer.start();
        while (container.size() > 0) {
            container.pop_back();
        }
        timer.stop();
        time += timer.nanoseconds();
    }
    cout << message << " took " << time / rounds / n << " ns" << endl;
}

template <typename C>
void push_front(string const& message, int rounds=10, int n=1000000) {
    C container;
    Timer timer;
    timer.start();
    for (int round = 0; round < rounds; round++) {
        for (int i = 0; i < n; i++) {
            container.push_front(i);
        }
    }
    timer.stop();
    cout << message << " took " << timer.nanoseconds() / rounds / n << " ns" << endl;
}

template <typename C>
void at(string const& message, int rounds=10, int n=1000000) {
    C container;
    long long time = 0;
    for (int round = 0; round < rounds; round++) {
        for (int i = 0; i < n; i++) {
            container.push_back(i);
        }
        Timer timer;
        timer.start();
        for (int i = 0; i < container.size(); i++) {
            container[i] = i;
        }
        timer.stop();
        time += timer.nanoseconds();
    }
    cout << message << " took " << time / rounds / n << " ns" << endl;
}


int main() {
    cout << "push_back" << endl;
    cout << "--------------" << endl;
    push_back<list<int>>("list  ");
    push_back<vector<int>>("vector");
    push_back<deque<int>>("deque ");
    cout << endl;

    cout << "pop_back" << endl;
    cout << "--------------" << endl;
    pop_back<list<int>>("list  ");
    pop_back<vector<int>>("vector");
    pop_back<deque<int>>("deque ");
    cout << endl;

    cout << "push_front" << endl;
    cout << "--------------" << endl;
    push_front<list<int>>("list  ");
    push_front<deque<int>>("deque ");
    cout << endl;

    cout << "at" << endl;
    cout << "--------------" << endl;
    at<vector<int>>("vector");
    at<deque<int>>("deque ");
    cout << endl;
    
}