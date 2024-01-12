#pragma once

#include <string>
#include <iostream>

namespace handy
{
    std::string input(std::string prompt)
    {
        std::cout << prompt;
        std::string response;
        std::getline(std::cin, response);
        return response;
    }
}