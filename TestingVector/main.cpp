#include <iostream>
#include <vector>

struct Vertex {
    
    float x, y, z;

    Vertex(float x, float y, float z) : x(x), y(y), z(z) { }
    
    // Copy Constructor
    Vertex(const Vertex & vertex) : x(vertex.x), y(vertex.y), z(vertex.z) { 
        std::cout << "Copied!" << std::endl;
    }

};

std::ostream & operator<<(std::ostream & stream, const Vertex & vertex) {

    stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
    return stream;

}

void function(const std::vector<Vertex> & vertices) { }

int main() {

    // In contrast to Java, std::vector allows primitive types in the template. In Java you would need to use class that represents the primitive type, instead of the primitive type itself, e.g., ArrayList<Integer> list;.
    // Another interesting argument to talk about is whether to store Vertex objects or Vertex pointers in our vector. If you store Vertex objects you will take full advantage of the memory when iterating through the vector since all vertices will be side-by-side (good for cache hits as well), however, when the vector needs to resize, it needs to copy every element to the new vector, which in case we are using big classes, can be a big performance hit. In constrast, if you are only storing pointers, the copy is much faster, but you are losing on the iteration performance since the elements have not allocated contiguously.
    // It is worth mentioning that the 'move constructor' can really help the 'storing the object in a vector' argument, since at least the dynamically allocated data can be moved (instead of deallocating and then allocating it again), however, most of the time, it will still copy more than the other option since we are just copying a pointer in that case.
    std::vector<Vertex> vertices; // Imo, keeping it as objects is better since we are using the stack
    vertices.reserve(3); // MANDATORY SO THAT THE VECTOR DOES NOT RESIZE UNTIL IT HAS REACHED THE SPECIFIED CAPACITY. The reserve function reserves the specified amount of memory, in this case, the amount of memory necessary to store three instances of Vertex. This is not the same as std::vector<Vertex> vertices(3); since that just builds three instances of Vertex! So, it has the same problem we are trying to fix.
    vertices.push_back({1, 2, 3}); // Just this insertion actually contains a copy because what the C++ compiler does is create an object instance of Vertex with the contents of the initializer list, and then send that object instance as argument to the push_back function call. So, the statement is basically to two statements: Vertex x = Vertex(1, 2, 3); vertices.push_back(x);, the last sending a copy of x.
    vertices.push_back({4, 5, 6});
    vertices.push_back(Vertex(7, 8, 9));
    vertices.emplace_back(10, 11, 12); // THE BEST WAY TO AVOID COPIES!!!

    for (int i = 0; i < vertices.size(); i++)
        std::cout << vertices[i] << std::endl;

    for (Vertex v : vertices) // This version of the for-each actually copies the object stored in vertices to 'v' in each iteration
        std::cout << v << std::endl;

    for (Vertex & v : vertices) // This is probably what you are looking for. A for-each that does not copy elements
        std::cout << v << std::endl;

    vertices.erase(vertices.begin() + 1); // Erases the 2nd element of 'vertices'

    for (Vertex & v : vertices)
        std::cout << v << std::endl;

    vertices.clear(); // Sets vector size to 0

    for (Vertex & v : vertices)
        std::cout << v << std::endl;

    function(vertices);



}