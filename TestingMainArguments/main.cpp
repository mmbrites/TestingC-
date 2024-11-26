#include <iostream>

int main(int argc, char * * argv) {

    // argc counts './programName', therefore, argc is always 1 or higher
    if (argc == 1) {

        std::cout << "You did not provide any arguments..." << std::endl;
        exit(0);

    }

    std::cout << "argv is at address: " << &argv << std::endl;
        std::cout << "argv points to address: " << argv << std::endl;

    int numberOfArguments = 0;
    while (numberOfArguments < argc - 1) {

        std::cout << "argv[" << numberOfArguments + 1 << "]: " << *(argv + numberOfArguments + 1) << std::endl;
        numberOfArguments++;

    }
        
    std::cout << "Ending program normally..." << std::endl;

}