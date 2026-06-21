#include "Circle.h"
#include <cmath>
#include <stdexcept>

Circle::Circle() : Shape(), center(0.0, 0.0), radius(1.0) {

}

Circle::Circle(std::string color, Point2D center, double radius) : Shape(color) {
    if (radius <= 0.0) {
        throw std::invalid_argument("Radio no valido: " + std::to_string(radius));
    }
    this->center = center;
    this->radius = radius;
}

Point2D Circle::get_center() const {
    return center;
}

void Circle::set_center(Point2D p) {
    center = p;
}

double Circle::get_radius() const {
    return radius;
}

void Circle::set_radius(double r) {
    if (r <= 0.0) {
        throw std::invalid_argument("Radio no valido: " + std::to_string(r));
    }
    radius = r;
}

std::ostream& operator<<(std::ostream &out, const Circle &c) {
    out << "Circle[color=" << c.color << ", center=" << c.center << ", radius=" << c.radius << "]";
    return out;
}

double Circle::area() const {
    return 3.141592 * radius * radius;
}

double Circle::perimeter() const {
    return 2.0 * 3.141592 * radius;
}

void Circle::translate(double incX, double incY) {
    center.x += incX;
    center.y += incY;
}

void Circle::print() {
    std::cout << *this << std::endl;
}
