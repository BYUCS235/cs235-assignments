#include <iostream>
using std::cout, std::endl, std::istream, std::ostream;

#include <string>
using std::string;

#include <fstream>
using std::ifstream;

#include <vector>
using std::vector;

#include <unordered_map>
using std::unordered_map;

#include <ctime>

typedef unordered_map<string, vector<string>> wordmap;

wordmap read_words(istream &in)
{
    wordmap words;
    string prev = "";
    string curr;
    while (in >> curr)
    {
        words[prev].push_back(curr);
        prev = curr;
    }
    return words;
}

const string &pick_word(wordmap const &words, string const &word)
{
    auto const &bucket = words.at(word);
    return bucket[rand() % bucket.size()];
}

void generate_text(wordmap const &words, int how_many, string prev, ostream &out)
{
    out << prev << " ";
    for (int i = 0; i < how_many; i++)
    {
        string word = pick_word(words, prev);
        cout << word << " ";
        prev = word;
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "missing filename and count" << endl;
        return 1;
    }

    ifstream file(argv[1]);
    if (!file.is_open())
    {
        std::cerr << "could not open " << argv[1] << endl;
        return 2;
    }

    if (argc < 3)
    {
        std::cerr << "missing count" << endl;
        return 3;
    }

    wordmap words = read_words(file);
    int how_many = atoi(argv[2]);

    generate_text(words, how_many, "", cout);
}