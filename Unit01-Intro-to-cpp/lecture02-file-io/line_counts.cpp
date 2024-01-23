// :)

#include <iostream>
using std::cerr, std::endl;

#include <fstream>
using std::ifstream, std::ofstream;

#include <string>
using std::string, std::getline;

#include <sstream>


int count_words(string line) {
    std::istringstream line_stream(line);
    int count = 0;
    string word;
    while (line_stream >> word)
    {
        count++;
    }
}

int main(int argc, char **argv)
{
    // for each line in input, sum numbers on line and write to output
    if (argc != 3) { cerr << "needs 3 args" << endl; return 1;}

    ifstream infile(argv[1]);
    ofstream outfile(argv[2]);
    if (!outfile.is_open()) { cerr << argv[2] << " did not open" << endl; }

    string line;
    while (getline(infile, line))
    {
        outfile << count_words(line) << endl;
    }

    infile.close();
    outfile.close();
}