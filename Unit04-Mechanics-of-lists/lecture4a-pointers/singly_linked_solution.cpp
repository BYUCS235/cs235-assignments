#include <stddef.h>
#include <iostream>
using std::cout, std::endl;

template <class T>
class SLList
{
    struct Node
    {
        T value;
        Node *next;
        Node(T const &item) : value(item), next(nullptr) {}
    };

    Node *head;
    size_t _size;

    void _push_back(Node *&node, T const &value)
    {
        if (node == nullptr)
        {
            node = new Node(value);
            _size++;
        }
        else
        {
            _push_back(node->next, value);
        }
    }

    void _clear(Node *&node)
    {
        if (node == nullptr)
        {
            return;
        }
        _clear(node->next);
        delete node;
        node = nullptr;
        _size--;
    }

public:
    SLList() : head(nullptr), _size(0) {}
    ~SLList()
    {
        clear();
    }

    T first() const
    {
        /* don't call this unless you're sure there is a value here! */
        return head->value;
    }

    size_t size() const { return _size; }

    void push_back(T const &item)
    {
        _push_back(head, item);
    }

    void clear()
    {
        _clear(head);
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