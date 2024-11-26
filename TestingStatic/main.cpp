#include <iostream>

class ExampleA {

    public:
	    static int s_variable;
	
};

int ExampleA::s_variable;

void function() {

    static int i = 0; // Only runs on the first function call :)
    i++;
    std::cout << i << std::endl;

}

class Singleton {

    public:
        static Singleton & getInstance() { return *_instance; }
        void hello() { }

    private:
        static Singleton * _instance;

};

Singleton * Singleton::_instance = nullptr; // If we define the 'Singleton' class like above, we need to initialize '_instance' outside the class  because in C++11 and later, static member variables can only be initialized inside the class definition if they are of a type that supports constant expression evaluation (e.g., integral types, pointers, etc.), and the constexpr specifier is required. 'nullptr' could be used with 'constexpr', but we do not want '_instance' to be a nullptr forever. To avoid needing this statement, you can use the 'local static' way:

class BetterSingleton {

    public:
        static BetterSingleton & getInstance() { 
            static BetterSingleton instance; // Only runs once
            return instance; 
        }
        void hello() { }

};

int main() {

    ExampleA::s_variable = 10;
    std::cout << ExampleA::s_variable << std::endl;

    function();
    function();
    function();

    Singleton::getInstance().hello();
    BetterSingleton::getInstance().hello();

}