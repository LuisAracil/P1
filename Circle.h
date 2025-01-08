#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include "Shape.h"
#include "Point2D.h"

class Circle : public Shape {
private:
    Point2D center;  // Centro del círculo
    double radius;   // Radio del círculo

public:
    // Constructor por defecto
    Circle();

    // Constructor con parámetros
    Circle(std::string color, Point2D center, double radius);

    // Implementación del método abstracto area()
    double area() const override;

    // Implementación del método abstracto perimeter()
    double perimeter() const override;

    // Implementación del método abstracto translate()
    void translate(double incX, double incY) override;

    // Implementación del método abstracto print()
    void print() override;

    // Métodos de acceso y modificación
    Point2D get_center() const;
    void set_center(Point2D p);
    double get_radius() const;
    void set_radius(double r);

    // Sobrecarga del operador << para imprimir el círculo
    friend std::ostream& operator<<(std::ostream &out, Circle &c);
};

#endif // CIRCLE_H

