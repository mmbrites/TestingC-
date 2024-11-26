#include <iostream>
#include <array>

class Entity {

    public:
        static constexpr int size = 5;
        int arr[size];

};

void arraySize() {

    const int size = 5;
    int arr[size];

}

int main() {

    int example[5];

    example[0] = 99;
    example[1] = 66;

    std::cout << "Address of the array's element 0: " << example << std::endl;
    std::cout << "Address of the pointer: " << &example << std::endl;
    std::cout << "example[0]: " << *example << std::endl;
    std::cout << "example[1]: " << *(example + 1) << std::endl;
    std::cout << "example[1]'s address: " << &example[1] << std::endl;

    int * pointerToArray = example;

    std::cout << "Address of the array's element 0: " << pointerToArray << std::endl;
    std::cout << "Address of the array's pointer: " << &pointerToArray << std::endl;

    example[-10] = 10;
    std::cout << "example[-10]: " << example[-1] << std::endl;

    example[2] = 10;
    std::cout << "example[2]: " << example[2] << std::endl;
    *(pointerToArray + 2) = 1024;
    std::cout << "example[2] after changes: " << example[2] << std::endl;
    * (int *) ((char *) pointerToArray + 8) = 100; // Just experimenting with pointer arithmetic, do not take it seriously. Either way, remember that when casting pointers the value you are inserting will be seen as the size of the pointer, inserting 100 as 1 byte is different from inserting 100 as 4 bytes, since we are overwriting the other 3 bytes (if we insert 100 as 1 byte the information in the other 3 bytes is retained). Casting to int * guarantees that the compiler sees this as a 4 byte operation. If we had not casted 'pointerToArray' to char *, we would add 2 instead of 8, because remember, in pointer arithmetic a unit depends on the size of the type it points to!
    std::cout << "example[2] after more changes: " << example[2] << std::endl;

    // EXAMPLE OF AN ARRAY HEAP ALLOCATION:

    int * another = new int[5];
    delete[] another;

    int other[9];
    std::cout << "Array size (in bytes): " << sizeof(other) << std::endl;
    std::cout << "Number of elements in the array: " << sizeof(other) / sizeof(int) << std::endl;

    const int size = 5;
    int even[size];

    std::array<int, 5> anoanother;

}