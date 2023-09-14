#include <string>
using std::string;

#include <iostream>
using std::cout, std::endl;

template <class T>
class Pair
{
private:
    T first;
    T second;

public:
    Pair(T first, T second) : first(first), second(second) {}
    T get_first() const { return first; }
    T get_second() const { return second; }
};

int main() {
    Pair<int> numbers(3, 9);
    Pair<string> words("spaghetti", "salamander");

    cout << numbers.get_first() << " " << numbers.get_second() << endl;
    cout << words.get_first() << " " << words.get_second() << endl;

}