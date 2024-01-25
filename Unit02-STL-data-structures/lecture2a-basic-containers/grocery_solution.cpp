#include <vector>
#include <iostream>
#include <string>
using std::string;

bool input(string const &prompt, string &response)
{
    std::cout << prompt;
    std::getline(std::cin, response);
    return response == "";
}

int main()
{
    std::vector<string> items;
    string item;
    while (input("Item: ", item))
    {
        items.push_back(item);
    }
    
    for (auto item : items)
    {
        std::cout << "- " << item << std::endl;
    }
}