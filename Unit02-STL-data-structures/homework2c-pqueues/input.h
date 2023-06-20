#pragma once

#include <iostream>
#include <string>

bool input(std::string const& prompt, std::string& response) {
    std::cout << prompt;
    std::cout.flush();
    getline(std::cin, response);
    return (response != "");
}
