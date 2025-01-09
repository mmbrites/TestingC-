#include <iostream>
#include <array>

template<class C, size_t S>
void printArray(const std::array<C, S> & arr)
{
    for (int index = 0; index < arr.size(); index++)
        std::cout << arr[index] << std::endl;
}

int main()
{
    std::array<int, 5> data;
    data[0] = 2;
    data[4] = 1;
    printArray(data);
}