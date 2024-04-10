#include <vector>
using std::vector;

template <class T>
class PQ
{
    vector<T> _data;

    void _swap(size_t i, size_t j)
    {
        T tmp = _data[i];
        _data[i] = _data[j];
        _data[j] = tmp;
    }

    size_t _parent(size_t index)
    {
        return (index - 1) / 2;
    }

    size_t _left(size_t index)
    {
        return 2 * index + 1;
    }

    size_t _right(size_t index)
    {
        return 2 * index + 2;
    }

    void _percolate_up(size_t index)
    {
        size_t p = _parent(index);
        if (index > 0 && _data[index] < _data[p])
        {
            _swap(index, parent);
            _percolate_up(parent);
        }
    }

    void _percolate_down(size_t index) {
        size_t rchild = _right(index);
        if (lchild >= _data.size()) {
            return;
        }
        size_t smaller;
        if (rchild >= _data.size()) {
            smaller = lchild;
        } else {
            smaller = (_data[rchild] < _data[lchild]) ? rchild : lchild;
        }
        if (_data[smaller] < _data[index]) {
            _swap(index, smaller);
            _percolate_down(smaller);
        }
    }

public:
    PQ{} : _data() {}

    size_t size() { return _data.size(); }

    void insert(T const &item)
    {
        _data.push_back(item);
        _percolate_up(_data.size() - 1);
    }

    T top()
    {
        return _data[0];
    }

    void pop()
    {
        _swap(0, _data.size() - 1);
        _data.pop_back();
        _percolate_down(0);
    }
};