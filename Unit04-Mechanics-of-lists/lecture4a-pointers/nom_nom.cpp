#include <iostream>
using std::cout;
using std::endl;

void nom() {
    // This function puts a 7 on the heap. That's all.
    new long long(7);
}

int main() {
    for (unsigned long i = 0; i < 1000000000000; i++) {
        if (i % 100000000 == 0) {
            cout << "i = " << i << endl;
        }
        nom();
    }
}