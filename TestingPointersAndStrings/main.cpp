#include <iostream>

int main() {

    int a = 5;
    int * pointerToa = &a;
    int * * pointerToPointerToa = &pointerToa;

    std::cout << "Address of the pointer that points to a pointer that points to a: " << &pointerToPointerToa << std::endl;
    std::cout << "Address of the pointer that points to a: " << pointerToPointerToa << std::endl;
    std::cout << "Address of a: " << *pointerToPointerToa << std::endl;

    const char * testChar = "hi";

    std::cout << "testChar's address: " << &testChar << std::endl;
    std::cout << "testChar points to: " << (void *) testChar << std::endl; // std::cout has a special handling for char *.  It knows that a const char* is a pointer to the first character of a null-terminated string. So, it prints characters one by one starting at the address testChar points to, and stops when it encounters the null terminator ('\0').
    std::cout << "String stored by the address testChar points to: " << *testChar << std::endl;

    const int * testInt = &a;

    std::cout << "testInt's address: " << &testInt << std::endl;
    std::cout << "testInt points to: " << testInt << std::endl;
    std::cout << "String stored by the address testInt points to: " << *testInt << std::endl;

}