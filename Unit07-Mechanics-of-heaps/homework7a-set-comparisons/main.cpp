#include <array>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>

#include "timing.h"

#include <set>
#include <unordered_set>
#include "VectorSet.h"
#include "BST.h"
#include "AVL.h"
#include "HashSet.h"

int main(int argc, char* argv[]) {
    std::srand(std::time(nullptr));
    std::array<int, 5> numbers_of_data{ 1000, 10000, 100000, 1000000, 10000000 };
    Timer timer;

    // choose an implementation of a set by uncommenting the appropriate line
    // below
    std::set<int> set;
    // std::unordered_set<int> set;
    // VectorSet<int> set;
    // BST<int> set;
    // AVL<int> set;
    // HashSet<int> set;

    std::cout << "    N       " << "Time to insert" << std::endl;
    std::cout << "---------- ----------------" << std::endl;
    for (int N : numbers_of_data) {
        std::cout << ' ' << std::setw(8) << std::right << N << "   ";
        timer.start();

        for (int i = 0; i < N; i++) {
            // choose whether to insert sequential or random data by
            // uncommenting the appropriate line below

            // SEQUENTIAL DATA
            set.insert(i);

            // RANDOM DATA
            // set.insert(rand());
        }

        timer.stop();
        std::cout << std::setw(12) << std::right << timer.milliseconds() << "ms" << std::endl;
    }

    return 0;
}
