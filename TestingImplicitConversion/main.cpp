#include <iostream>

class Entity {

    public:
        Entity(const std::string & name) : _name(name), _age(-1), _velocity(0) { }
        Entity(int age) : _name("Unknown"), _age(age), _velocity(0) { }
        explicit Entity(float velocity) : _name("Known"), _age(-1), _velocity(velocity) { }

        std::string name() const { return _name; }

    private:
        std::string _name;
        int _age;
        float _velocity;

};

void printEntity(const Entity & entity) { std::cout << entity.name() << std::endl; }

int main() {

    Entity a = 22; // Implicit conversion! Since there is a constructor in entity that takes in one std::string parameter. The compiler implicitly converts the const char[] to a std::string and calls the constructor. C++ only allows one implicit conversion per operation, in order to maintain code clarity.
    Entity b = std::string("Miguel"); // Sometimes the compiler complains if I write [Entity B = "Miguel";] due to constructor ambiguity (yes, he thinks the const char[] can be represented as an int I guess). So I thinks it's safer to wrap it at the very least.

    printEntity(22); // Implicit conversion from int to an Entity via the constructor that takes an int
    printEntity(std::string("Miguel"));
    
    printEntity('M'); // Although it might seem like two conversions are happening (char → int → Entity), C++ treats this as a single implicit conversion because the intermediate conversion (char → int) is handled implicitly by the int constructor.

    // Explicit constructor can only be called like this:
    Entity c = (Entity) 2.0f;
    Entity d = Entity(2.0f);
    Entity e(2.0f);
    printEntity(c);

}