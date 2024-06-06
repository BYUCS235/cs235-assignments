#include <list>
using std::list;

#include <vector>
using std::vector;

const int N = 4000000;

int main() {
    list<int> numbers;
    // vector<int> numbers;
    for (int i = 0; i < N; i++) {
        numbers.push_back(i);
    }
}
