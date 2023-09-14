#include <vector>
#include <string>
using std::string, std::getline;
#include <iostream>
using std::cout, std::cin, std::endl;

class Counters
{
    std::vector<int> _counters;

public:
    Counters(size_t size) : _counters(size)  // initialize a pre-allocated vector of size `size`
    {
        for (int i = 0; i < size; i++)
        {
            _counters[i] = 0;
        }
    }

    size_t size() const {
        return _counters.size();
    }

    int increment(size_t which) {
        return ++_counters.at(which);
    }

    int get(size_t which) const {
        return _counters.at(which);
    }
};

bool input(string const& prompt, string &response) {
    cout << prompt;
    getline(cin, response);
    return (response != "");
}


int main() {
    Counters counters(31);
    string response;
    while (input("Day of month: ", response)) {
       int day = std::stoi(response);
       counters.increment(day); 
    }

    for (size_t i = 0; i < counters.size(); i++) {
        cout << i << ": " << counters.get(i) << endl;
    } 
}