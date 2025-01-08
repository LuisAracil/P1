#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <stdexcept>
#include <iostream>
#include "Shape.h"
#include "Point2D.h"

class Rectangle : public Shape {
protected:
    Point2D* vs;  // Puntero a un array de 4 puntos representando los vértices

public:
    static int const N_VERTICES = 4;  // Constante que define el número de vértices del rectángulo

    // Constructor por defecto
    Rectangle();

    // Constructor con parámetros
    Rectangle(std::string color, Point2D* vertices);

    // Constructor de copia
    Rectangle(const Rectangle& r);

    // Destructor
    ~Rectangle();

    // Métodos heredados de Shape
    virtual double area() const override;  // Implementación del método de área
    virtual double perimeter() const override;  // Implementación del método de perímetro
    virtual void translate(double incX, double incY) override;  // Implementación de método de traslación
    virtual void print() override;  // Implementación de método de impresión

    // Método para obtener un vértice por índice
    Point2D get_vertex(int ind) const;

    // Sobrecarga del operador [] para acceder a los vértices
    Point2D operator[](int ind) const;

    // Método para modificar los vértices
    virtual void set_vertices(Point2D* vertices);

    // Sobrecarga del operador = para asignación de rectángulos
    Rectangle& operator=(const Rectangle& r);

    // Sobrecarga del operador << para imprimir el rectángulo
    friend std::ostream& operator<<(std::ostream& out, const Rectangle& r);

private:
    // Método estático que verifica si un conjunto de 4 puntos forma un rectángulo válido
    static bool check(Point2D* vertices);
};

#endif // RECTANGLE_H

