#include <ostream>
#include <cmath>
#include "Point2D.h"

double Point2D::distance(const Point2D &a, Point2D &b) {
	const double dx = a.x - b.x;
	const double dy = a.y - b.y;
	return std::sqrt(dx * dx + dy * dy);
}

bool Point2D::operator==(const Point2D &other) {
	return x == other.x && y == other.y;
}

bool Point2D::operator!=(const Point2D &other) {
	return !(*this == other);
}

std::ostream& operator<<(std::ostream &out, const Point2D &p) {
	return out << "(" << p.x << ", " << p.y << ")";
}
