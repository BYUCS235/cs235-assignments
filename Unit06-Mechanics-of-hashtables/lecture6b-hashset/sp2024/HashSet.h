#pragma once

#include <functional>
using std::hash;

#include <list>
using std::list;

#include "../../../lib/debug.h"

#include <iostream>
template <class T>
std::ostream &operator<<(std::ostream &out, list<T> const &bucket)
{
    for (T const &item : bucket)
    {
        out << item << ' ';
    }
    return out;
}

template <class T>
class HashSet
{
private:
    const double LOAD_FACTOR = 0.8;

    hash<T> _hash;
    size_t _size;
    size_t _capacity;
    list<T> *_buckets;

    list<T> &_get_bucket(T const &item)
    {
        size_t hashcode = _hash(item);
        size_t pos = hashcode % _capacity;
        return _buckets[pos];
    }

    bool _contains(list<T> const &bucket, T const &item) const
    {
        for (T const &thing : bucket)
        {
            if (item == thing)
            {
                return true;
            }
        }
        return false;
    }

    void _grow()
    {
        TRACE
        size_t old_capacity = _capacity;
        _capacity = _capacity << 1;
        list<T> *old_buckets = _buckets;
        _buckets = new list<T>[_capacity];

        TRACE
        /* Add all items in current buckets to new buckets*/
        for (size_t i = 0; i < old_capacity; i++)
        {
            list<T> &old_bucket = old_buckets[i];
            for (T const &item : old_bucket)
            {
                // Add this item to new_buckets
                list<T> &bucket = _get_bucket(item);
                bucket.push_back(item);
            }
        }

        TRACE
        delete[] old_buckets;
    }

public:
    HashSet() : _size(0), _capacity(8), _buckets(new list<T>[_capacity]) {}

    ~HashSet()
    {
        delete[] _buckets;
    }

    bool insert(T item)
    {
        if (_size > LOAD_FACTOR * _capacity)
        {
            _grow();
        }

        list<T> &bucket = _get_bucket(item);

        if (_contains(bucket, item))
        {
            return false;
        }

        bucket.push_back(item);

        _size++;
        return true;
    }

    bool remove(T item)
    {
        list<T> &bucket = _get_bucket(item);
        bool contained = _contains(bucket, item);
        if (contained) {
            bucket.remove(item);
            _size--;
        }
        return contained;
    }

    bool contains(T item) const
    {
        size_t hashcode = _hash(item);
        size_t pos = hashcode % _capacity;
        list<T> &bucket = _buckets[pos];
        return _contains(bucket, item);
    }

    void clear()
    {
        for (size_t i = 0; i < _capacity; i++)
        {
            _buckets[i].clear();
        }
        _size = 0;
    }

    size_t size() const
    {
        return _size;
    }
};
