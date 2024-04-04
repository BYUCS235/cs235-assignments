#include <unordered_set>
using std::unordered_set;

void print(unordered_set<int> const& numbers) {
    for (auto const& number : numbers) { 
        printf("The number %i is at %p\n", number, &number);
    }
}

int main() {
    unordered_set<int> numbers;
    numbers.insert(0);
    print(numbers);

    for (int i = 0; i < 100; i++) {
        numbers.insert(i);
    }
    print(numbers);
}