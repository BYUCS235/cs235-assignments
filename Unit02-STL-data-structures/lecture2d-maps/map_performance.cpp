#include <iostream>
using std::cout, std::endl;

#include <map>
using std::map;

#include <unordered_map>
using std::unordered_map;

#include "timing.h"

template <class M>
long long gauntlet(size_t bound = 1000000, size_t rounds = 5)
{
    Timer timer;
    timer.start();
    for (size_t round = 0; round < rounds; round++)
    {
        M numbers;
        for (size_t i = 0; i < bound; i++)
        {
            numbers[i] = i + 1;
        }
    }
    timer.stop();
    return timer.nanoseconds() / rounds;
}

int main()
{
    for (size_t bound : {1000, 10000, 100000, 1000000, 10000000})
    {
        cout << "N = " << bound << endl;
        
        auto map_time = gauntlet<map<int, int>>(bound);
        cout << " map took " << map_time << " nanoseconds; " << map_time / bound << " per item" << endl;
        
        auto umap_time = gauntlet<unordered_map<int, int>>(bound);
        cout << "umap took " << umap_time << " nanoseconds; "  << umap_time / bound << " per item" << endl;
        
        cout << endl;
    }
}