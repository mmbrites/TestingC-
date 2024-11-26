#include <iostream>

class Entity {

    public:
        void printClassName() {
            std::cout << "Entity" << std::endl;
        }

};

class Player : public Entity {

    public:
        void printClassName() {
            std::cout << "Player" << std::endl;
        }

};

void printClassName(Entity * entity) {
    entity->printClassName();
}

int main() {

    Entity * entity = new Entity;
    entity->printClassName();

    Player * player = new Player;
    player->printClassName();

    printClassName(player);

    // Since the program is for testing purposes and the program terminates anyway, I am not deleting the heap-allocated objects.

}