#include <iostream>
#include <fstream>
#include <sstream>
using std::stringstream;

#include <string>
using std::string;

int count_words(string line) {
    stringstream ss(line);
    int count = 0;
    string token;
    while (ss >> token) { count++; }
    return count;
}

int main(int argc, char** argv) {
    if (argc < 3) {
        std::cerr << "Not enough arguments" << std::endl;
        return 1;
    }

    string input_file(argv[1]);
    string output_file(argv[2]);

    std::ifstream input(argv[1]);
    if (!input.is_open()) {
        std::cerr << "Unable to open input file: " + input_file << std::endl;
        return 2;
    }

    std::ofstream output(argv[2]);
    if (!output.is_open()) {
        std::cerr << "Unable to open output file: " + output_file << std::endl;
        return 3;
    }

    string line;
    while (getline(input, line)) {
        int count = count_words(line);
        output << count << std::endl;
    }

    input.close();
    output.close();
    return 0;
}