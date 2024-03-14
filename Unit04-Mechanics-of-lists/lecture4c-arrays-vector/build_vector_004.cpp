template <class T>
class Vector {

    size_t _size;
    size_t _max_size;

    T* _items;

    void _grow() {
        _max_size *= 2;
        T* new_array = new T[_max_size];
        for (size_t i = 0; i < _size; i++) {
            new_array[i] = _items[i];
        }
        delete[] _items;
        _items = new_array;
    }

    public:
    Vector(size_t initial_capacity = 8) : _size(0), _max_size(initial_capacity), _items(new T[_max_size]) { }

    ~Vector() {
        delete[] _items;
    }

    size_t size() const {
        return _size;
    }

    T& back() const {
        return _items[_size-1];
    }

    void push_back(T const& item) {
        if (_size == _max_size) {
            _grow();
        }
        _items[_size++] = item;
    }

    void pop_back() {
        _size--;
    }

    bool empty() const {
        return _size == 0;
    }

    void clear() {
        _size = 0;
    }
};