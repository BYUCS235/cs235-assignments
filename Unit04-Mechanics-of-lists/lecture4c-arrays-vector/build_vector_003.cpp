template <class T>
class Vector {
    size_t _size;
    size_t _limit;
    T* _array;

    void _grow() {
        _limit *= 2;
        T* new_array = new T[_limit];
        for (size_t i = 0; i < _size; i++) {
            new_array[i] = _array[i];
        }
        delete[] _array;
        _array = new_array;
    }


    public:

    Vector(size_t limit = 8): _size(0), _limit(limit), _array(new T[_limit]) {}

    ~Vector() {
        delete[] _array;
    }

    size_t size() const {

        return _size;
    }

    void push_back(T const& item) {
        if (_size + 1 >= _limit) {
            _grow();
        }
        _array[_size++] = item;
    }

    void clear() {
        _size = 0;
    }

    /*
    size
    push_back
    pop_back
    clear
    */
};