#include <iostream>

class Entity {

    public:
        Entity(int position) : _position(position) { std::cout << "Created Entity!" << std::endl; };
        ~Entity() { std::cout << "Destroyed Entity!" << std::endl; }

    private:
        int _position;

};

class ScopedPointer {

    public:
        ScopedPointer(Entity * entity) : _entity(entity) { }
        ~ScopedPointer() { delete _entity; }

    private:
        Entity * _entity;

};

int main() {

    { ScopedPointer entityScopedPointer(new Entity(20)); } // Could also write: ScopedPointer entityScopedPointer = new Entity(20);

    std::cin.get(); // Its only purpose is just to be clear whether or not the allocated memory gets freed before the program ends :)

}