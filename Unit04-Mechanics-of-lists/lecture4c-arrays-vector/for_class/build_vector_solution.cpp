template <class T>
class Vector {
    T* _array;
    size_t _size;
    size_t _capacity;

    void _grow() {
        T* tmp = _array;
        size_t old_cap = _capacity;
        _capacity *= 2;
        _array = new T[_capacity]
        for (size_t i = 0; i < old_cap; i++) {
            _array[i] = tmp[i];
        }
        delete[] tmp;
    }

    public:
    Vector() : _size(0), _capacity(8), _array(new T[_capacity]) { }
    ~Vector() { delete[] _array; }

    void push_back(T const& item) {
        if (_size == _capacity) { _grow(); }
        _array[_size++] = item;
    }

    void pop_back() {
        _size--;
    }

    T& operator[] (size_t pos) {
        return _array[pos];
    }

    size_t size() const {
        return _size;
    }
};