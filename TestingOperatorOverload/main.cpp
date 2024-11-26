#include <iostream>

class Vec2 {

    public:
        float x, y;
        Vec2(float X, float Y) : x(X), y(Y) { }

        Vec2 add(const Vec2 & other) const {
            return Vec2(x + other.x, y + other.y);
        }

        Vec2 operator+(const Vec2 & other) const {
            return add(other);
        }

        Vec2 multiply(const Vec2 & other) const {
            return Vec2(x * other.x, y * other.y);
        }

        Vec2 operator*(const Vec2 & other) const {
            return multiply(other);
        }

        bool operator==(const Vec2 & other) const {
            return x == other.x && y == other.y;
        }

        bool operator!=(const Vec2 & other) const {
            return !(*this == other);
        }

};

// C++ has a rule that applies to binary operators like +, <<, etc.: If an operator is written in the form a << b, the expression is equivalent to calling operator<<(a, b).
std::ostream & operator<<(std::ostream & stream, const Vec2 & other) {

    stream << other.x << ", " << other.y;
    return stream;

} 

int main() {

    // Just interpret operator overloading as a function ---> It is all that it is really, play with it.

    Vec2 position(4.0f, 4.0f);
    Vec2 speed(0.5f, 1.5f);
    Vec2 powerUp(1.1f, 1.1f);

    // Instead of having a chain of explicit function calls
    Vec2 result1 = position.add(speed.multiply(powerUp));
    Vec2 result2 = position + speed * powerUp;

    std::cout << result1 << std::endl;

    if (result1 == result2)
        std::cout << "Overloaded Operator" << std::endl;

}