#pragma once

#include <iostream>

#include <string>
using std::string;

class Stuff
{
private:
    int integer;
    double decimal;
    string word;

public:
    Stuff(int number, double decimal_number, string text)
        : integer(number), decimal(decimal_number), word(text) {}

    int get_integer() const { return integer; }
    double get_decimal() const { return decimal; }
    string get_word() const { return word; }
};

int operator+(Stuff const &one, Stuff const &two)
{
    return one.get_integer() + two.get_integer();
}

std::ostream &operator<<(std::ostream &out, Stuff const &stuff)
{
    out << "Integer: " << stuff.get_integer() << std::endl;
    out << "Decimal: " << stuff.get_decimal() << std::endl;
    out << "Word: " << stuff.get_word() << std::endl;
    return out;
}