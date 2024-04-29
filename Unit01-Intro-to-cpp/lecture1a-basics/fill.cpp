#include <fstream>
using std::ofstream, std::endl;

#include <string>
using std::string;

#include <cstdlib>  // atoi, size_t

int main(int argc, char* argv[]) {
    string filename = argv[1];
    ofstream out(filename);
    if (!out.is_open()) {
        return 1;
    }

    size_t limit = atoi(argv[2]);
    string word = argv[3];
    for (size_t count = 0; count < limit; count++) {
        out << word << endl;
    }

    out.close();
}
