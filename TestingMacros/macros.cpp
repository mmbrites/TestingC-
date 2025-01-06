#include <iostream>
#include <string>

#define RELEASE_MODE 0
#define DEBUG_MODE 1

#define RANDOM_MULTI_LINE_CONSTANT int main() \
{\
    std::cin.get();\
}

// '\' escapes the character after, in this case, the '\n', so for the compiler, the RANDOM_MULTI_LINE_CONSTANT preprocessor definition is all in the same line

// RANDOM_MULTI_LINE_CONSTANT

// #if 0 --> Combined with #endif at the end of the block you want to hide from the compiler :)

int main()
{

    #if DEBUG_MODE == 1
        #define LOG(x) std::cout << x << std::endl
    #elif RELEASE_MODE == 1
        #define LOG(x)
    #endif

    LOG("Hello");

}

// #endif