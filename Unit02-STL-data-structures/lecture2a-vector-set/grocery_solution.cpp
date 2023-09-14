#include <vector>
#include <iostream>
#include <string>
using std::string;

void input(string const &prompt, string &response)
{
    std::cout << prompt;
    std::getline(std::cin, response);
}

int main()
{
    std::vector<string> items;
    string item;
    while (true)
    {
        input("Item: ", item);
        if (item == "")
        {
            break;
        }
        items.push_back(item);
    }
    for (auto item : items)
    {
        std::cout << "- " << item << std::endl;
    }
}