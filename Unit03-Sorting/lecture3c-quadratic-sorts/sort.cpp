#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::cout, std::cin, std::endl;

#include "handy.h"
using handy::print;

#if SORT == 1 // bubble
#include "bubble.h"

#elif SORT == 2 // selection
#include "selection.h"

#elif SORT == 3 // insertion
#include "insertion.h"

#elif SORT == 4 // merge
#include "merge.h"

#elif SORT == 5 // quick
#include "quick.h"

#elif SORT == 6 // bean
#include "bean.h"

#elif SORT == 7 // std::sort
#include <algorithm>
template<class T>
void sort(vector<T> &items) {
    std::sort(items.begin(), items.end());
}
#else
template <class T>
void sort(vector<T> &items)
{
    std::cerr << "'sort' not defined! Be sure to compile with -DSORT 1|2|3|4|5" << endl;
}
#endif

int main(int argc, char* argv[]) {
    // if argc == 1, read from stdin
    // otherwise use argv[2:]
    vector<string> stuff;
    if (argc == 1) {
        string word;
        while (cin >> word) {
            stuff.push_back(word);
        }
    } else {
        for (int i = 1; i < argc; i++) {
            stuff.push_back(argv[i]);
        }
    }

    print(stuff);
    sort(stuff);
    print(stuff);
}

