#include <iostream>
#include <tuple>
#include <string>

std::tuple<std::string, std::string, int> getData()
{
    return { "one", "two", 3};
}

int main() 
{

    auto [string1, string2, number] = getData();
    std::cout << string1 << " " << string2 << " " << number << std::endl;

}