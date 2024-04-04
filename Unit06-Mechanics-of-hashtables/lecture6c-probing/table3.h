#pragma once

#include <stddef.h> // size_t

#include <string>
using std::string;

#include <iostream>
using std::cout, std::endl;

#include <functional> // std::hash

#include "debug.h"

class Table3
{
    struct entry
    {
        bool is_entry;
        string value;

        void set_value(string const &value)
        {
            this->value = value;
            is_entry = true;
        }

        void clear_value()
        {
            is_entry = false;
        }
    };

    const size_t N = 8;
    entry *table;
    std::hash<string> hash;

public:
    Table3() : table(new entry[N]), hash() { reset(); }
    ~Table3() { delete[] table; }

    void reset()
    {
        for (size_t i = 0; i < N; i++)
        {
            table[i].value = "";
            table[i].is_entry = false;
        }
    }

    void print() const
    {
        for (size_t i = 0; i < N; i++)
        {
            cout << i << "(" << table[i].is_entry << "):  " << table[i].value << endl;
        }
    }

    void insert(string const &item)
    {
        size_t pos = hash(item) % N;
        while (table[pos].is_entry)
        {
            pos = (pos + 1) % N;
        };
        table[pos].set_value(item);
    }

    bool contains(string const &item)
    {
        size_t pos = hash(item) % N;
        while (table[pos].is_entry)
        {
            if (table[pos].is_entry && table[pos].value == item)
            {
                return true;
            }
            pos = (pos + 1) % N;
        };
        return false;
    }

    bool remove(string const &item)
    {
        size_t pos = hash(item) % N;
        while (table[pos].is_entry)
        {
            if (table[pos].is_entry && table[pos].value == item)
            {
                table[pos].clear_value();
                return true;
            }
            pos = (pos + 1) % N;
        };
        return false;
    }
};