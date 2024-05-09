#include <iostream>
using std::cout, std::endl;

#include <vector>
using std::vector;

#include <string>
using std::string;

template <class T>
class PQ {
    vector<T> _data;

    public:
    PQ() : _data() {}

    T pop() {
        // find the max
        size_t max_pos = 0;
        for (size_t i = 0; i < _data.size(); i++) {
            if (_data[i] > _data[max_pos]) { max_pos = i;}
        }

        // remove the max
        size_t last_pos = _data.size() - 1;
        T tmp = _data[last_pos];
        _data[last_pos] = _data[max_pos];
        _data[max_pos] = tmp;

        tmp = _data[last_pos];
        _data.pop_back();

        // return the max
        return tmp;
    }

    void push(T item) {
        _data.push_back(item);
    }

    bool empty() {
        return _data.empty();
    }
};

int main() {
    PQ<int> stuff;
    stuff.push(1);
    stuff.push(4);
    stuff.push(2);
    stuff.push(7);

    while (!stuff.empty()) {
        cout << stuff.pop() << endl;
    }
    // Big words come out first (i.e. zebra > animal)
    PQ<string> words;
    words.push("children");
    words.push("abacus");
    words.push("zebra");

    cout << words.pop() << endl;
    cout << words.pop() << endl;
 
    words.push("alpaca");  // > abacus
    words.push("aaron"); // < abacus

    cout << words.pop() << endl;
    cout << words.pop() << endl;
    cout << words.pop() << endl;


}