#include "Shape.h"
#include <ostream>

// Constructor por defecto y validación implementados en el .h

// Implementación de los métodos no virtuales
std::string Shape::get_color() const {
    return color;
}

void Shape::set_color(const std::string& c) {
    validate_color(c);
    color = c;
}

