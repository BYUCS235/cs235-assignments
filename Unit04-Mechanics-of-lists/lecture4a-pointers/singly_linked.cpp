#include <stddef.h>
#include <iostream>
using std::cout, std::endl;

template <class T>
class SLList
{
    public:
    struct Node {
        T value;
        Node* next;
        Node(T const& item) : value(item), next(nullptr) {}
    };
private:
    Node* _head;
    size_t _size;

    void _push_back(Node*& node, T const& item) {
        if (node == nullptr) {
            node = new Node(item);
            _size++;
        } else {
            _push_back(node->next, item);
        }
    }

    void _clear(Node*& node) {
        if (node != nullptr) {
            _clear(node->next);

            delete node;
            node = nullptr;
            _size--;        
        }
    }

public:
    SLList() : _head(nullptr), _size(0) {}

    ~SLList() {
        clear();
    }

    T first() const
    {
        /* don't call this unless you're sure there is a value here! */
        return _head->value;
    }

    size_t size() const {
        return _size;
    }

    void push_back(T const &item)
    {
        _push_back(_head, item);
    }

    void clear()
    {
        _clear(_head);
    }
};

void epic() {
    SLList<long long> list;
    for (int i = 0; i < 10; i++) {
        list.push_back(i);
    }
}

int main()
{
    for (int i = 0; i < 1000000000; i++) {
        epic();
    }

    SLList<int> list;
    cout << "Size should be 0: " << list.size() << endl;
    list.push_back(7);
    list.push_back(8);
    cout << "Size should be 2: " << list.size() << endl;
    list.clear();
    cout << "Size should be 0: " << list.size() << endl;
}