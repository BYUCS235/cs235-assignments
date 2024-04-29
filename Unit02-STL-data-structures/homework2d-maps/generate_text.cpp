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

#include <list>
using std::list;

typedef unordered_map<string, vector<string>> wordmap;

string to_key(list<string> const &tokens)
{
    string key;
    for (auto const &token : tokens)
    {
        key += token + '|';
    }
    return key;
}

wordmap read_words(istream &in, size_t window_size)
{
    wordmap words;
    list<string> prev = {""};
    string curr;
    while (in >> curr)
    {
        words[to_key(prev)].push_back(curr);
        prev.push_back(curr);
        if (prev.size() > window_size)
        {
            prev.pop_front();
        }
    }
    return words;
}

const string &pick_word(wordmap const &words, list<string> const &prev)
{
    auto const &bucket = words.at(to_key(prev));
    return bucket[rand() % bucket.size()];
}

void generate_text(
    wordmap const &words,
    size_t window_size,
    int how_many,
    list<string> prev,
    ostream &out)
{
    for (auto const &word : prev)
    {
        out << word << " ";
    }
    for (int i = 0; i < how_many; i++)
    {
        string word = pick_word(words, prev);
        cout << word << " ";
        prev.push_back(word);
        if (prev.size() > window_size)
        {
            prev.pop_front();
        }
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

    const size_t WINDOW = 4;
    wordmap words = read_words(file, WINDOW);
    int how_many = atoi(argv[2]);

    list<string> prev = {""};
    generate_text(words, WINDOW, how_many, prev, cout);
}