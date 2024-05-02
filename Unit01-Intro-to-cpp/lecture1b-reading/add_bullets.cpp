#include <iostream>
using std::cout, std::cerr, std::endl;

#include <fstream>
using std::ifstream, std::ofstream;

#include <string>
using std::string, std::getline;

int main(int argc, char *argv[])
{
    // First arg is input file, second arg is output file, third arg is bullet
    if (argc < 4) {
        cerr << "This program needs an input file, output file, and bullet" << endl;
        return 1;
    }

    ifstream infile(argv[1]); //  same as:  ifstream infile = ifstream(argv[1])
    if (!infile.is_open())
    {
        cerr << "Unable to open file for reading: " << argv[1] << endl;
        return 2;
    }

    ofstream outfile(argv[2]);
    if (!outfile.is_open())
    {
        cerr << "Unable to open file for writing: " << argv[2] << endl;
        return 3;
    }

    string line;
    while (getline(infile, line))
    {
        outfile << argv[3] << " " << line << endl;
    }

    infile.close();
    outfile.close();
}