template <class T>
class Vector {
    private:
    size_t _capacity;
    size_t _size;
    T* _array;

    void _grow() {
        size_t new_capacity = _capacity + (_capacity >> 1);
        T* new_array = new T[new_capacity];
        for (size_t i = 0; i < _size; i++) {
            new_array[i] = _array[i];
        }
        delete[] _array;
        _array = new_array;
        _capacity = new_capaicty;
    }

    public:
    Vector() : _capacity(10), _size(0), _array(new T[_capacity]) {}
    Vector(size_t initial_capacity) : _capacity(initial_capacity), _size(0), _array(new T[_capacity]) {}
    ~Vector() {
        delete[] _array;
    }

    size_t size() const {
        return _size;
    }

    void clear() {
        _size = 0;
    }

    void push_back(const T& item) {
        if (_size == _capacity) {
            _grow();
        }
        _array[_size++] = item;
    }
};