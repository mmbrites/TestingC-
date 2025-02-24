#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

void forEachVanilla(const std::vector<int> & values, void(*func)(int))
{
    for (int value : values)
        func(value);
}

void forEach(const std::vector<int> & values, const std::function<void(int)> & func)
{
    for (int value : values)
        func(value);
}

int main()
{
    std::vector values = { 1, 5, 4, 2, 3 };

    // Example of usage of a lambda function
    auto iterator = std::find_if(values.begin(), values.end(), [](int value) { return value > 3;});
    std::cout << *iterator << std::endl;

    int a = 5;
    // [] --> captures outside variables
    auto lambda = [a](int value) { std::cout << "Value: " << a << std::endl; };
    forEach(values, lambda);
}