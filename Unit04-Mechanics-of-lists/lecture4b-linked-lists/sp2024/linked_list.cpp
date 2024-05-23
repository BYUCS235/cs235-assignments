// :)

template <class T>
class DLL
{
private:
    struct Node
    {
        T value;
        Node *next;
        Node *prev;
        Node(T const &item) : value(item), next(nullptr), prev(nullptr) {}
    };

    Node *_head;
    Node *_tail;
    size_t _size;

public:
    DLL() : _head(nullptr), _tail(nullptr), _size(0) {}

    size_t size() const { return _size; }

    void push_back(T const &item)
    {
        if (_tail == nullptr)
        {
            _tail = new Node(item);
            _head = _tail;
        }
        else
        {
            // Create new node
            Node *node = new Node(item);

            // node->prev is now tail
            node->prev = _tail;

            // tail->next is now node
            _tail->next = node;

            // tail is now node
            _tail = node;   
        }

        _size++;
    }

    void push_front(T const& item) {
        if (_head == nullptr)
        {
            _head = new Node(item);
            _tail = _head;
        }
        else
        {
            // Create new node
            Node *node = new Node(item);

            // node->next is now tail
            node->next = _head;

            // head->prev is now node
            _head->prev = node;

            // head is now node
            _head = node;   
        }

        _size++;
    }

    void insert(size_t pos, T const& item) {
        if (pos == 0) {
            push_front(item);
            return;
        }

        if (pos == _size) {
            push_back(item);
            return;
        }

        Node* here = _head;
        for (size_t i = 0; i < pos; i++) {
            here = here->next;
        }

        Node* node = new Node(item);
        node->next = here;
        node->prev = here->prev;

        here->prev->next = node;
        here->prev = node;

        _size++;
    }

};