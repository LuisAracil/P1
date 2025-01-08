#include "Point2D.h"

#include <cmath>
#include <ostream>

// Implementación de la distancia entre dos puntos
// Método estático definido en la clase Point2D
double Point2D::distance(const Point2D &a, const Point2D &b) {
        return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
}

// Sobrecarga del operador ==
bool operator==(const Point2D &a, const Point2D &b) {
        return (a.x == b.x && a.y == b.y);
}

// Sobrecarga del operador !=
bool operator!=(const Point2D &a, const Point2D &b) {
        return !(a == b);
}

// Sobrecarga del operador <<
std::ostream& operator<<(std::ostream &out, const Point2D &p) {
        out << "(" << p.x << ", " << p.y << ")";
        return out;
}

