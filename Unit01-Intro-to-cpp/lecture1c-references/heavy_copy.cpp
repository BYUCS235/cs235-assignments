#include <string>
using std::string;

#include <iostream>
using std::cout, std::cerr, std::endl;

#include <fstream>
#include <chrono>
using std::chrono::high_resolution_clock, std::chrono::duration_cast, std::chrono::nanoseconds;

string get_file_contents(string filename) {

    std::ifstream file(filename);
    if (!file.is_open()) {
        return "";
    }

    string content;
     /* char(0) tells getline to treat char(0) as the "newline" character, 
     and thus reads through the whole file in a single pass*/
    std::getline(file, content, char(0));

    file.close();

    return content;
}

int get_size(string text) {
    return text.size();
}

int get_size_ref(string& some_text) {
    return some_text.size();
}

int main(int argc, char** argv) {
    if (argc < 2) { cerr << "Needs file and how many" << endl; exit(1); }

    string filename(argv[1]);
    int how_many(std::stoi(argv[2]));  // int how_many = atoi(argv[2]);

    string text = get_file_contents(filename);
    cout << "Length of text is: " << text.size() << endl;

    uint total_size(0);

    /* Version with string */
    cout << endl;
    cout << "Exercise with string beginning..." << endl;

    auto start = high_resolution_clock::now();

    for (int i = 0; i < how_many; i++) {
        total_size += get_size(text);
    }
    auto finish = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(finish - start);

    cout << "Length of text X " << how_many << " is: " << total_size << endl;
    cout << "Version with string took " << duration.count() << " nanoseconds" << endl;

    /* Version with string reference */    
    cout << endl;
    cout << "Exercise with string& beginning..." << endl;

    start = high_resolution_clock::now();

    total_size = 0;

    for (int i = 0; i < how_many; i++) {
        total_size += get_size_ref(text);
    }
    finish = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(finish - start);

    cout << "Length of text X " << how_many << " is: " << total_size << endl;
    cout << "Version with string& took " << duration.count() << " nanoseconds" << endl;
    
    return 0;
}