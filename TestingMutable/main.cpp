#include <iostream>

class AnotherEntity {

    public:
        AnotherEntity(const int y, int x) : _y(y), _x(x) { }

        int y() const { 
            _x++;
            return _y;
        }

    private:
        int _y;
        mutable int _x; // For debug purposes, for example, serves to count the amount of times y() was called

};

int main() {

    auto f = []() {
        std::cout << "Hello" << std::endl;
    };

    int x = 2;
    auto f1 = [x]() mutable {
        x++;
        std::cout << x << std::endl;
    };

    f1(); // Prints '3'
    std::cout << x << std::endl; //  Prints '2'

}