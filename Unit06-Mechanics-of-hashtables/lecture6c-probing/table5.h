#pragma once

#include <stddef.h>  // size_t

#include <string>
using std::string;

#include <iostream>
using std::cout, std::endl;

#include <functional>  // std::hash

#include "debug.h"

class Table5 {
    struct entry {
        bool is_entry;
        bool is_deleted;
        string value;
        
        void set_value(string const& value) {
            this->value = value;
            is_entry = true;
            is_deleted = false;
        }
        
        void clear_value() {
            is_entry = false;
            is_deleted = true;
        }
    };
    
    const size_t PERTURB_SHIFT = 5;  // taken from python
    const size_t N = 8;  // power of 2 capacity is important for the pseudo-random walk
    entry* table;
    std::hash<string> hash;
    
    public:
    Table5() : table(new entry[N]), hash() { reset(); }
    ~Table5() { delete[] table; }
    
    void reset() { 
        for (size_t i = 0; i < N; i++) { 
            table[i].value = ""; table[i].is_entry = false; table[i].is_deleted = false;
        }
    }
    
    void print() const { 
        for (size_t i = 0; i < N; i++) { 
            cout << i 
                 << "(" << table[i].is_entry << ")[" 
                 << table[i].is_deleted << "]:  " 
                 << table[i].value << endl; 
        }
    }
    
    bool insert(string const& item) { 
        TRACK(item)
        size_t perturb = hash(item);
        size_t pos = perturb;

        for (;;) {  // equivalent to while (true)
            TRACK(pos % N)
            entry& ent = table[pos % N];
            
            if (ent.is_entry && ent.value == item) {
                return false;
            }
            
            if (!ent.is_entry) {
                ent.set_value(item);
                return true;
            }
            
            perturb >>= PERTURB_SHIFT;
            pos = pos*5 + perturb + 1;
        }
    }
    
    bool contains(string const& item) {
        TRACK(item)        
        size_t perturb = hash(item);
        size_t pos = perturb;

        for (;;) {
            TRACK(pos % N)
            entry const& ent = table[pos % N];
            
            if (ent.is_entry && ent.value == item) {
                return true;
            }
            
            if (!ent.is_entry && !ent.is_deleted) {
                return false;
            }
            
            perturb >>= PERTURB_SHIFT;
            pos = pos*5 + perturb + 1;
        }
    }
    
    bool remove(string const& item) {
        TRACK(item)
        size_t perturb = hash(item);
        size_t pos = perturb;

        for (;;) {
            TRACK(pos % N)
            entry& ent = table[pos % N];
            
            if (ent.is_entry && ent.value == item) {
                ent.clear_value();
                return true;
            }
            
            if (!ent.is_entry && !ent.is_deleted) {
                return false;
            }
            
            perturb >>= PERTURB_SHIFT;
            pos = pos*5 + perturb + 1;
        }
    }
};

