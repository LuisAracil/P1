#ifndef DRAWING_H
#define DRAWING_H

#include "ListArray.h" // Lista concreta de figuras
#include "Shape.h"     // Base para figuras
#include <iostream>

class Drawing {
private:
    List<Shape*>* shapes; // Lista de figuras

public:
    // Constructor
    Drawing();

    // Destructor
    ~Drawing();

    // Añadir figura al frente del dibujo
    void add_front(Shape* shape);

    // Añadir figura al fondo del dibujo
    void add_back(Shape* shape);

    // Mostrar información de todas las figuras
    void print_all();

    // Calcular el área total de todos los círculos
    double get_area_all_circles();

    // Mover todos los cuadrados
    void move_squares(double incX, double incY);
};

#endif

