#include <iostream>
#include <memory>

class Entity {

    public:
        Entity() { std::cout << "Created Entity!" << std::endl; };
        ~Entity() { std::cout << "Destroyed Entity!" << std::endl; }
        void print() { }
        

};

void foo(const Entity * entity) { }

int main() {

    {

        std::unique_ptr<Entity> entity(new Entity());
        std::unique_ptr<Entity> ent = std::make_unique<Entity>(); // Exception-safe constructor --> Avoids dangling pointers
        foo(entity.get()); // or foo(*entity) --> in case the function needs the reference to make changes to the object. Of course, in that case the function declaration would be 'void foo(const Entity & entity);'

        // Unique pointers are not useful if you want to pass them into a function or to another pointer :)

        std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>(); // Preferred way due to its efficienty, you can use something similar to line 20, but it would need to perform two allocations since the shared pointer allocates a 'control block' to keep track of the references. When doing make_shared, the allocation is done together.
        
        std::shared_ptr<Entity> sharedEnt = sharedEntity; // You can copy :)

        std::weak_ptr<Entity> weakEntity = sharedEntity; // You can copy and the reference count does not increase!

    }

    std::cin.get();

}