#include <vector>
#include <string>
using std::string, std::getline, std::stoul;
#include <iostream>
using std::cout, std::cin, std::endl;

class Counters
{
    // class fields default to private if they aren't in a public section.
    std::vector<int> _counters;

public:
    Counters(size_t size) : _counters(size)  // initialize a pre-allocated vector of size `size`
    {
        for (size_t i = 0; i < size; i++)
        {
            _counters[i] = 0;
        }
    }

    size_t size() const {
        return _counters.size();
    }

    int increment(size_t which) {
        return ++_counters.at(which-1);
    }

    int get(size_t which) const {
        return _counters.at(which-1);
    }
};

bool input(string const& prompt, string &response) {
    return cout << prompt && getline(cin, response) && !response.empty();
}

std::ostream & operator<<(std::ostream &out, Counters const& counters) {
    for (size_t i = 0; i < counters.size(); i++) {
        out << i+1 << ": " << counters.get(i+1) << endl;
    } 
    return out;
}

int main() {
    Counters counters(31);
    string response;
    while (input("Day of month: ", response)) {
       size_t day = stoul(response);
       counters.increment(day); 
    }

    cout << counters << endl;
}