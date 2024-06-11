#include <iostream>
using std::cout, std::endl;

class Random {
    // Make it happen    
};

int main() {
    for (auto num : Random(10)) {
        cout << num << endl;
    }
}