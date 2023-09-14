#include <iostream>
using std::cout, std::cerr, std::endl;

#include <fstream>
using std::ifstream, std::ofstream;

#include <string>
using std::string, std::getline;

#include <sstream>
using std::stringstream;

int sum_line(string line)
{
    stringstream line_stream(line);
    int total;
    int num;
    while (line_stream >> num)
    {
        total += num;
    }
    return total;
}

int main(int argc, char **argv)
{
    // for each line in input, sum numbers on line and write to output
    ifstream infile(argv[1]);
    ofstream outfile(argv[2]);

    string line;
    while (getline(infile, line))
    {
        outfile << sum_line(line) << endl;
    }

    infile.close();
    outfile.close();
}