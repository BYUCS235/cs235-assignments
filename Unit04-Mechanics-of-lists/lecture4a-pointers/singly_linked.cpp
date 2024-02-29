#include <stddef.h>
#include <iostream>
using std::cout, std::endl;

template <class T>
class SLList
{

public:
    T first() const
    {
        /* don't call this unless you're sure there is a value here! */
    }

    size_t size() const {}

    void push_back(T const &item)
    {
    }

    void clear()
    {
    }
};

int main()
{
    SLList<int> list;
    cout << "Size should be 0: " << list.size() << endl;
    list.push_back(7);
    list.push_back(8);
    cout << "Size should be 2: " << list.size() << endl;
    list.clear();
    cout << "Size should be 0: " << list.size() << endl;
}