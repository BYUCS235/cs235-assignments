#pragma once

#include <stddef.h> // size_t

#include <string>
using std::string;

#include <iostream>
using std::cout, std::endl;

#include <functional> // std::hash

#include "debug.h"

class Table1
{
    const size_t N = 8;
    string *table;
    std::hash<string> hash;

public:
    Table1() : table(new string[N]), hash() { reset(); }
    ~Table1() { delete[] table; }
    void reset()
    {
        for (size_t i = 0; i < N; i++)
        {
            table[i] = "";
        }
    }
    void print() const
    {
        for (size_t i = 0; i < N; i++)
        {
            cout << i << ":  " << table[i] << endl;
        }
    }

    void insert(string const &item)
    {
        size_t pos = hash(item) % N;
        table[pos] = item;
    }

    bool contains(string const &item)
    {
        return table[hash(item) % N] == item;
    }

    bool remove(string const &item)
    {
        size_t pos = hash(item) % N;
        table[pos] = "";
        return true;
    }
};