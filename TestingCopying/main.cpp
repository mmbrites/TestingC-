#include <iostream>
#include <cstring>

class String {

    public:
        String(const char * buffer) {

            _size = strlen(buffer);
            _buffer = new char[_size + 1];
            memcpy(_buffer, buffer, _size); // You could do memcpy(_buffer, buffer, size + 1); but then you would trusting that the 'buffer' parameter would be properly setup, i.e., last character would be a null-terminator. Instead of memcpy, you could also use strcpy
            _buffer[_size] = 0;

            //std::cout << "Dog" << std::endl;

        }

        /* Example of a copy constructor by default:
        
            String(const String & other) : _buffer(other._buffer), _size(other._size) { }
        
        */

        String(const String & other) : _size(other._size) {

            std::cout << "copy" << std::endl;

            _buffer = new char[_size + 1];
            memcpy(_buffer, other._buffer, _size + 1); // Here we can do _size + 1 because we know that the 'String' object for sure has the null-terminator

        }

        ~String() {
            delete[] _buffer;
        }

        char & operator[](int index) {
            return _buffer[index];
        }

        void print() { }

    private:
        char * _buffer;
        unsigned int _size;


    friend std::ostream & operator<<(std::ostream & stream, const String & string); // Declared as a friend so as to access the private field '_buffer'. Of course, we could just have a getter.

};

std::ostream & operator<<(std::ostream & stream, const String & string) {

    stream << string._buffer;
    return stream;

}

int main() {

    // The only exception regarding copying and the assignment operator.

    int a = 10;
    int & z = a;
    int & x = z; // Assigning x = y does not create a new a or copy anything. It just says, "let x also refer to what z refers to," which is already a.

    // References don’t have their own memory separate from the object they refer to. When you assign one reference to another, you’re simply saying that both references point to the same underlying object. There’s no new object to copy, and the compiler doesn’t need to invoke any copy operation.

    String string = "Miguel";
    std::cout << string << std::endl;
    String string1 = string;
    string1[2] = 'j';
    std::cout << string1 << std::endl;

}