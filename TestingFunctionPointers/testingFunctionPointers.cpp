#include <iostream>
#include <vector>

void helloWorld()
{
    std::cout << "Hello World!" << std::endl;
}

int helloWorldTwist(int a)
{
    std::cout << "Hello World! Value: " << a << std::endl;
    return 0;
}

void printValue(int value)
{
    std::cout << "Value: " << value << std::endl;
}

void forEach(const std::vector<int> & values, void(*func)(int))
{
    for (int value : values)
        func(value);
}

int main()
{

    auto function = &helloWorld; // You do not need the '&', since there is an implicit conversion, but I am just using it because to be more explicit

    // Two calls to helloWorld()
    function();
    function();

    void(*functionName)() = helloWorld;

    functionName();

    typedef void(*HelloWorldFunction)(); // Better way to deal with the weird type

    HelloWorldFunction fun = helloWorld;
    fun();

    typedef int(*HelloWorldTwistFunction)(int);
    HelloWorldTwistFunction tFun = helloWorldTwist;
    tFun(8);

    // Practical Example

    std::vector<int> values = {1, 5, 4, 2, 3};
    forEach(values, printValue);

    // Alternate way using a lambda expression/function
    forEach(values, [](int value) { std::cout << "Value: " << value << std::endl; });
    
}