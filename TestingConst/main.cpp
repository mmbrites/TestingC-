#include <iostream>

class Entity {

    public:
        int x() const { return _x; }
        int y() const { return _y; }
        const float * const xmmFlag() const { return _xmmFlag; }

    private:
        int _x, _y;
        float * _xmmFlag;

};

void printEntity(const Entity & entity) {
    std::cout << entity.x() << std::endl;
}

int main() {

    const int MAX_AGE = 90;

    int * a = new int;
    *a = 2;
    a = (int *) &MAX_AGE; // Undefined behaviour! Depending on the compiler, the last two prints can be the same.

    std::cout << *a << std::endl;

    *a = 20;

    std::cout << MAX_AGE << std::endl;
    std::cout << *a << std::endl;

}