#include <iostream>
#include <string>
#include <algorithm>

namespace apple
{
    void print(const std::string & text)
    {
        std::cout << text << std::endl;
    }
}

namespace orange
{
    void print(const char * text)
    {
        std::string temporary = text;
        std::reverse(temporary.begin(), temporary.end());
        std::cout << temporary << std::endl;
    }
}

// This way of defining a nested namespace is equivalent to: namespace banana { namespace functions { } }
namespace banana::functions
{

}

int main()
{
    using namespace apple; // You can also just "import" specific functions, e.g., using apple::print; --> Only imports the print function from the apple namespace.
    // You can also create aliases for namespaces, e.g., namespace a = apple. With this you can write a::print("Hello");. It is particularly useful for nested namespaces.
    // Beware with the creation of aliases, they should be created in the smallest scope possible to avoid naming conflicts.
    print("Hello");
}