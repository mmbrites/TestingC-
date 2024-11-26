#include <iostream>

class Entity {

    public:
        Entity() {
            std::cout << "Created Entity!" << std::endl;
        }

        ~Entity() {
            std::cout << "Deleted Entity!" << std::endl;
        }

};

int main() {

    Entity e;

    std::cin.get(); // It still prints the message in Entity's destructor. You just need to input, at least, one character

}
