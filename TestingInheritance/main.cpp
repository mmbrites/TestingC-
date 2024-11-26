#include <iostream>

class Entity {

    public:
        float x, y;

        Entity() {
            x = 0; y = 0;
        }

        void printXY() {
            std::cout << x << " " << y << std::endl;
        }

        void Move(float xa, float ya) {

            x += xa;
            y += ya;

        }

};

class Player : public Entity {

    public:
        const char * name = "Miguel";
        float x, y;

        Player() {
            x = 1; y = 1;
            
        }

        void printPositions() {
            std::cout << Entity::x << " " << y << std::endl;
        }

        void printName() {
            std::cout << name << std::endl;
        }

        const char * getName() { return name; }

};

int main() {

    Player p;
    p.printPositions();
    p.printName();
    const char * playerName = p.getName();
    std::cout << playerName << std::endl;

}