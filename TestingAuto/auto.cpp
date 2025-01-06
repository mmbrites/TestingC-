#include <iostream>
#include <string>
#include <vector>

const char * getName()
{
    return "sanctuary";
}

int main()
{

    auto name = getName();
    std::cout << name << std::endl;

    std::vector<std::string> strings;
    strings.push_back("Apple");
    strings.push_back("Orange");

    using stringIterator = std::vector<std::string>::iterator;
    typedef std::vector<std::string>::iterator stringIt;

    // Helpful to avoid having to write the whole iterator type
    for (auto it = strings.begin(); it != strings.end(); ++it)
        std::cout << *it << std::endl;

    for (stringIterator it = strings.begin(); it != strings.end(); ++it)
        std::cout << *it << std::endl;

    for (stringIt it = strings.begin(); it != strings.end(); ++it)
        std::cout << *it << std::endl;

}