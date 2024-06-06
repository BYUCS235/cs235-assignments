#include <iostream>

#define SHOW(x) std::cout << #x << std::endl;

#ifdef _MSC_VER
#define FUNCTION __FUNCSIG__
#else
#define FUNCTION __PRETTY_FUNCTION__ 
#endif

#include <set>
#include <unordered_set>

template <class T>
class FooSet {

};

template <class T>
void foo() {
    std::cout << FUNCTION << std::endl; 
    std::cout << typeid(T).name() << std::endl;
}

int main() {
    foo<std::set<int>>();
    foo<std::unordered_set<int>>();
    foo<FooSet<int>>();
}