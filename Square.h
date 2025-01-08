#ifndef SQUARE_H
#define SQUARE_H

#include <stdexcept>
#include <iostream>
#include "Rectangle.h"

class Square : public Rectangle {
public:
    // Constructor por defecto
    Square();

    // Constructor con parámetros
    Square(std::string color, Point2D* vertices);

    // Modificar los vértices del cuadrado
    virtual void set_vertices(Point2D* vertices) override;

    // Sobrecarga del operador << para imprimir el cuadrado
    friend std::ostream& operator<<(std::ostream& out, const Square& square);

private:
    // Verificar si los vértices conforman un cuadrado válido
    static bool check(Point2D* vertices);
};

#endif

