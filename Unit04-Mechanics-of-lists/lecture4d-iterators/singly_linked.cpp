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

    class iterator {
        // Track whatever state is necessary to keep track of your place in the container
        Node* current;
        
        public:
        // The constructor starts with this information
        iterator(Node*const& node) : current(node) {}

        // Define == and != so you know when you've reached end()
        bool operator==(iterator const& other) {
            return current == other.current;
        }

        bool operator!=(iterator const& other) {
            return !(*this == other);
        }

        // Define ++ to move from the current position to the next one
        iterator& operator++() {
            current = current->next;
            return *this;
        }

        // Define * to retrieve the value at the current position
        T operator*() {
            return current->value;
        }
    };  // Don't forget the semicolon at the end of the class!

    // begin() returns an iterator for the first element in your collection
    iterator begin() const {
        return iterator(head);
    }

    // end() returns an iterator that has gone past the end of your collection
    // it is not the last value, it is AFTER the last value
    iterator end() const {
        return iterator(nullptr);
    }
};

int main()
{
    SLList<int> list;
    cout << "Size should be 0: " << list.size() << endl;
    list.push_back(7);
    list.push_back(8);
    for (auto item : list) {
        cout << item << endl;
    }
    cout << "Size should be 2: " << list.size() << endl;
    list.clear();
    cout << "Size should be 0: " << list.size() << endl;
}