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
    stringstream line_stream(line); // line_stream = stringstream(line)
    int total = 0;  // leave off "= 0", what happens?
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
    if (argc != 3) { cerr << "needs 3 args" << endl; return 1;}

    ifstream infile(argv[1]);
    ofstream outfile(argv[2]);
    if (!outfile.is_open()) { cerr << argv[2] << " did not open" << endl; }

    string line;
    while (getline(infile, line))
    {
        outfile << sum_line(line) << endl;
    }

    infile.close();
    outfile.close();
}