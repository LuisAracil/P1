// Square.cpp

#include "Square.h"
#include <cmath>
#include <iostream>

// Constructor por defecto
Square::Square() : Rectangle("red", new Point2D[4]{
    Point2D(-1, 1), Point2D(1, 1), Point2D(1, -1), Point2D(-1, -1)}) {}


// Constructor con parámetros
Square::Square(std::string color, Point2D* vertices) : Rectangle(color, vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Los vértices no forman un cuadrado válido.");
    }
}

// Sobreescritura del método set_vertices
void Square::set_vertices(Point2D* vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Los vértices no forman un cuadrado válido.");
    }
    Rectangle::set_vertices(vertices);
}

// Sobrecarga global del operador <<
std::ostream& operator<<(std::ostream& out, const Square& square) {
    // Crear una copia temporal del objeto para evitar el problema de const
    Square temp_square = square;  // Hacemos una copia temporal no constante del cuadrado
    temp_square.print();          // Ahora podemos llamar a print() sin problemas
    return out;
}

// Método privado para verificar si los vértices forman un cuadrado
bool Square::check(Point2D* vertices) {
    double d01 = Point2D::distance(vertices[0], vertices[1]);
    double d12 = Point2D::distance(vertices[1], vertices[2]);
    double d23 = Point2D::distance(vertices[2], vertices[3]);
    double d30 = Point2D::distance(vertices[3], vertices[0]);
    
    // Si todas las distancias son iguales, es un cuadrado
    return (d01 == d12 && d12 == d23 && d23 == d30);
}

