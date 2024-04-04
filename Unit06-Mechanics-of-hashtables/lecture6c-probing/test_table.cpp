#include "table5.h"
typedef Table5 Table;


int main() {
    Table table;

    cout << "--- INSERT ---" << endl;
    table.insert("foo");
    table.insert("bar");
    table.insert("baz");
    table.insert("xyz");

    table.print();    

    cout << "--- CONTAINS ---" << endl;
    cout << table.contains("foo") << endl;
    cout << table.contains("bar") << endl;
    cout << table.contains("baz") << endl;
    cout << table.contains("xyz") << endl;

    cout << "--- REMOVE ---" << endl;
    cout << table.remove("foo") << endl;
    cout << table.remove("foo") << endl;
    cout << table.contains("foo") << endl;
    cout << table.remove("bar") << endl;
    cout << table.remove("baz") << endl;
    cout << table.remove("xyz") << endl;

    table.print();

}