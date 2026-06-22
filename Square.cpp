#include "Square.h"
#include <stdexcept>

bool Square::check(Point2D* vertices) {
    double d01 = Point2D::distance(vertices[0], vertices[1]);
    double d12 = Point2D::distance(vertices[1], vertices[2]);
    double d23 = Point2D::distance(vertices[2], vertices[3]);
    double d30 = Point2D::distance(vertices[3], vertices[0]);
    return d01 == d12 && d12 == d23 && d23 == d30;
}

Square::Square() : Rectangle() {
    vs[0] = Point2D(-1.0, 1.0);
    vs[1] = Point2D(1.0, 1.0);
    vs[2] = Point2D(1.0, -1.0);
    vs[3] = Point2D(-1.0, -1.0);
}

Square::Square(std::string color, Point2D* vertices) : Rectangle(color, vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Los vertices no forman un cuadrado valido");
    }
}

void Square::set_vertices(Point2D* vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Los vertices no forman un cuadrado valido");
    }
    Rectangle::set_vertices(vertices);
}

std::ostream& operator<<(std::ostream &out, const Square &s) {
    out << static_cast<const Rectangle&>(s);
    return out;
}

void Square::print() {
    std::cout << *this << std::endl;
}
