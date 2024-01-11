#include <functional>
using std::hash;

#include <iostream>
using std::cout, std::endl;

#include <string>
using std::string;

#include <list>
using std::list;

template<class T>
class HashSet {
    size_t _capacity;
    size_t _size;
    list<T>* _table;
    
    list<T>& _get_bucket(T const& value) {
        int pos = hash<T>{}(value) % _capacity;
        return _table[pos];
    }

    void _grow() {
        auto old_table = _table;
        auto old_capacity = _capacity;
        _capacity *= 2;
        _table = new list<T>[_capacity];
        _size = 0;
        for (int i = 0; i < old_capacity; i++) {
            for (auto item : old_table[i]) {
                insert(item);
            }
        }
        delete[] old_table;
    }

    public:

    HashSet() : _capacity(8), _size(0), _table(new list<T>[_capacity]) { }
    ~HashSet() {
        clear();
        delete[] _table;
    }
    
    bool insert(T const& value) {
        if (_size > _capacity * 0.8) {
            _grow();
        }
        
        // Is this item already in the table?
        auto& bucket = _get_bucket(value);
        bool found = (std::find(bucket.begin(), bucket.end(), value) != bucket.end());

        if (found) {
            return false;
        }
        
        bucket.push_back(value);
        _size++;
        return true;
    }
    
    bool remove(T const& value) {
        auto &bucket = _get_bucket(value);
        auto iter = std::find(bucket.begin(), bucket.end(), value);

        if (iter == bucket.end()) {
            return false;
        }
        
        bucket.erase(iter);
        _size--;
        return true;
    }
    
    bool contains(T const& value) const {
        // Is this item already in the table?
        auto &bucket = _get_bucket(value);
        return (std::find(bucket.begin(), bucket.end(), value) != bucket.end());
    }

    size_t size() const {
        return _size;
    }

    void clear() {
        for (size_t i = 0; i < _capacity; i++) {
            _table[i].clear();
        }
    }

    // For demonstration purposes
    friend std::ostream& operator<<(std::ostream& out, HashSet const& set) {
        for (size_t i = 0; i < set._capacity; i++) {
            out << i << ": ";
            for (auto item : set._table[i]) {
                out << item << ",";
            }
            out << endl;
        }
        return out;
    }
};



int main() {
    HashSet<string> words;
    words.insert("sidewalk");
    words.insert("boomerang");
    words.insert("hat");
    words.insert("pony");
    words.insert("enunciate");
    words.insert("hashtable");

    cout << words << endl;

    words.remove("boomerang");
    words.remove("hat");

    cout << words << endl;

    words.insert("numeric");
    words.insert("wizard");
    words.insert("expanding");
    
    cout << words << endl;
    words.insert("too big!");

    cout << words << endl;
}