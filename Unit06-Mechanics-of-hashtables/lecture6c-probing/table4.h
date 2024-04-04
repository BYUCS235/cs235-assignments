#pragma once

#include <stddef.h> // size_t

#include <string>
using std::string;

#include <iostream>
using std::cout, std::endl;

#include <functional> // std::hash

#include "debug.h"

class Table4
{
    struct entry
    {
        bool is_entry;
        bool is_deleted;
        string value;

        void set_value(string const &value)
        {
            this->value = value;
            is_entry = true;
            is_deleted = false;
        }

        void clear_value()
        {
            is_entry = false;
            is_deleted = true;
        }
    };

    const size_t N = 8;
    entry *table;
    std::hash<string> hash;

public:
    Table4() : table(new entry[N]), hash() { reset(); }
    ~Table4() { delete[] table; }

    void reset()
    {
        for (size_t i = 0; i < N; i++)
        {
            table[i].value = "";
            table[i].is_entry = false;
            table[i].is_deleted = false;
        }
    }

    void print() const
    {
        for (size_t i = 0; i < N; i++)
        {
            cout << i
                 << "(" << table[i].is_entry << ")["
                 << table[i].is_deleted << "]:  "
                 << table[i].value << endl;
        }
    }

    void insert(string const &item)
    {
        size_t pos = hash(item) % N;
        while (table[pos].is_entry || table[pos].is_deleted)
        // Consider: Why can't we reuse deleted slots?
        {
            pos = (pos + 1) % N;
        };
        table[pos].set_value(item);
    }

    bool contains(string const &item)
    {
        size_t pos = hash(item) % N;
        while (table[pos].is_entry || table[pos].is_deleted)
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
        while (table[pos].is_entry || table[pos].is_deleted)
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