#include <iostream>

class Entity {

    public:
        Entity() : _x(0) { }
        Entity(int x) : _x(x) { }

        int x() { return _x; }

    private:
        int _x;

};

int main() {

    Entity entity0 = Entity(); // Stack-allocated object using the default constructor explicitly
    std::cout << "entity0's _x value: " << entity0.x() << std::endl;

    Entity entity1(10); // Stack-allocated object using the other constructor explicitly
    std::cout << "entity1's _x value: " << entity1.x() << std::endl;

    // You can also write Entity entity = Entity(); if you want to be more explicit

    Entity * entity2 = new Entity(99); // The new keyword returns a memory address corresponding to where the created object resides. Therefore, everything that is created with new can only be mentioned via a pointer.

    std::cout << "entity2's _x value: " << entity2->x() << std::endl; // Can also do (*entity2).x()

    Entity* e = entity2; // Assigns the memory address stored in 'entity2' to 'e'. It is just an assignment, we are not copying the object.

    delete entity2; // Deallocates the 'entity2' object

    std::cout << "e's _x value: " << (*e).x() << std::endl; // Since 'e' pointed to the same object as 'entity2', and that object was deallocated, this now prints gibberish.

    // Exploring the 'new' keyword

    int a = 2;
    int * b = new int;
    int * c = new int[40]; // When allocating an array, even on the heap, the addresses have to be contiguous!

    Entity * entity3 = new Entity(); // Allocates the memory and calls the 'Entity' constructor
    Entity * entity4 = (Entity *) malloc(sizeof(Entity)); // Only allocates the memory 
    new (entity4) Entity(88); // Use placement new to call the constructor. It allows you to explicitly initialize objects in pre-allocated memory :)

    std::cout << "entity4's _x value: " << entity4->x() << std::endl;

}