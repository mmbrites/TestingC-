#include <iostream>

// The template needs to be defined right before the function declaration.
template<typename T>
void print(T value) // The functions get created at compile-time with respect to the function calls that are performed. In this case, there will be a function with parameter of type 'int', and another with parameter of type 'float'.
{
    std::cout << value << std::endl;
}

// Class Example
template<typename T, int N>
class Array
{

    private:
        T _array[N];
    public:
        int getSize() const { return N; }

};

int main()
{

    print(5);
    print(5.1f);

    // To improve overall readability, you can call template functions as following:
    print<double>(5.2); // This type of syntax is fundamental when using arguments with a type that cannot be inferred by the compiler.

    Array<int, 4> array;
    std::cout << array.getSize() << std::endl;

}