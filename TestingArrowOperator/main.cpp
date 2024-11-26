#include <iostream>

class Entity {

    public:
        void print() { }
        float x, y, z;

};

class ScopedEntity {

    public:
        ScopedEntity(Entity * entity) : _entity(entity) {  }
        ~ScopedEntity() { delete _entity;  }

        Entity * operator->() {
            return _entity;
        }

    private:
        Entity * _entity;

};

int main() {

    ScopedEntity entity(new Entity);
    entity->print();

    // Trick to get the offset of a variable in a class
    size_t offset = (size_t) &((Entity *) nullptr)->y;

    std::cout << offset << std::endl;

}