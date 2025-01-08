#include "Circle.h"
#include <cmath>
#include <iostream>


// IMPLEMENTACION "PUBLIC" DE LA CLASE CIRCLE.H


// Constructor por defecto
Circle::Circle() : center(0, 0), radius(1) {}

// Constructor con parámetros
Circle::Circle(std::string color, Point2D center, double radius)
    : Shape(), center(center), radius(radius) {
    this->color = color;
}

// Implementación del método abstracto area()
double Circle::area() const {
    return 3.14159 * radius * radius;  // Área del círculo (π * r²)
}

// Implementación del método abstracto perimeter()
double Circle::perimeter() const {
    return 2 * 3.14159 * radius;  // Perímetro del círculo (2 * π * r)
}

// Implementación del método abstracto translate()
void Circle::translate(double incX, double incY) {
    center.x += incX;
    center.y += incY;
}

// Implementación del método abstracto print()
void Circle::print() {
    std::cout << "Círculo - Color: " << color
              << ", Centro: " << center
              << ", Radio: " << radius
              << ", Área: " << area()
              << ", Perímetro: " << perimeter() << std::endl;
}

// Métodos de acceso y modificación para `center` y `radius`

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
    radius = r;
}

// Sobrecarga del operador << para imprimir un círculo
std::ostream& operator<<(std::ostream &out, Circle &c) {
    c.print();
    return out;
}

