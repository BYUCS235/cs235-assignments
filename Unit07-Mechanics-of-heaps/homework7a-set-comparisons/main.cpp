#include <array>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

#include "timing.h"

#include <set>
#include <unordered_set>
#include "VectorSet.h"
#include "BST.h"
#include "AVL.h"
#include "HashSet.h"

template <class S>
void run_performance(std::string name, bool random_data, int max_n = (1 << 24))
{
    Timer timer;
    S set;

    std::cout << "### " << name << " - " << ((random_data) ? "RANDOM" : "SEQUENTIAL") << " Data ###" << std::endl
              << std::endl;
    std::cout << "    N       Time to insert (ns)   Time per unit (ns) " << std::endl;
    std::cout << "---------- --------------------- --------------------" << std::endl;

    int N = 1 << 7; // i.e. 128 (but gets shifted to 256 at the beginning of the loop)
    while ((N <<= 1) < max_n)
    {
        std::cout << ' ' << std::setw(8) << std::right << N << "   ";

        timer.start();

        for (int i = 0; i < N; i++)
        {
            if (random_data)
            {
                set.insert(rand());
            }
            else
            {
                set.insert(i);
            }
        }

        timer.stop();

        std::cout << std::setw(19) << std::right << timer.nanoseconds() << "    "
                  << std::setprecision(10) << std::setw(17) << std::right << timer.nanoseconds() / N
                  << std::endl;
    }

    std::cout << std::endl
              << std::endl;
}

int main(int argc, char *argv[])
{
    std::srand(std::time(nullptr));

    auto foo = new long[100000000];
    delete[] foo;

    run_performance<std::set<int>>("std::set", false);
    run_performance<std::unordered_set<int>>("std::unordered_set", false);
    run_performance<BST<int>>("BST", false, 12000);
    run_performance<AVL<int>>("AVL", false);
    run_performance<HashSet<int>>("HashSet", false);
    run_performance<VectorSet<int>>("VectorSet", false, 12000);

    run_performance<std::set<int>>("std::set", true);
    run_performance<std::unordered_set<int>>("std::unordered_set", true);
    run_performance<BST<int>>("BST", true);
    run_performance<AVL<int>>("AVL", true);
    run_performance<HashSet<int>>("HashSet", true);
    run_performance<VectorSet<int>>("VectorSet", true, 12000);

    return 0;
}
