#include <vector>
using std::vector;
#include <iostream>
using std::cout, std::endl;

class Noisy {
    int value;
    public:
    Noisy(int v) : value(v) { cout << "Noisy constructed from " << v << endl; }
    Noisy(Noisy const& other) : value(other.value) { cout << "Noisy copied from " << other.value << endl; }
    Noisy& operator=(Noisy const& other) { 
        cout << "Noisy assigned from " << other.value << endl; value = other.value; return *this; 
    }
    int get_value() const { return value; }
};

int main() {
    vector<Noisy> noises;
    for (int i = 0; i < 32; i++) {
        noises.push_back(Noisy(i));
    }
}