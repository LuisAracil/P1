#include "Drawing.h"
#include "Circle.h"
#include "Square.h"

// Constructor
Drawing::Drawing() {
    shapes = new ListArray<Shape*>(); // Instancia concreta de ListArray
}

// Destructor
Drawing::~Drawing() {
    while (!shapes->empty()) {
        delete shapes->remove(0); // Eliminar y liberar memoria de cada figura
    }
    delete shapes; // Liberar memoria de la lista
}

// Añadir figura al frente
void Drawing::add_front(Shape* shape) {
    shapes->prepend(shape);
}

// Añadir figura al fondo
void Drawing::add_back(Shape* shape) {
    shapes->append(shape);
}

// Mostrar información de todas las figuras
void Drawing::print_all() {
    for (int i = 0; i < shapes->size(); ++i) {
        shapes->get(i)->print(); // Llamar al método polimórfico print
        std::cout << std::endl;
    }
}

// Calcular el área total de todos los círculos
double Drawing::get_area_all_circles() {
    double total_area = 0.0;
    for (int i = 0; i < shapes->size(); ++i) {
        Shape* shape = shapes->get(i);

        // Verificar si el área concuerda con la fórmula de un círculo
        double radius = std::sqrt(shape->area() / 3.14159); // Despejar el radio
        if (std::abs(3.14159 * radius * radius - shape->area()) < 1e-6) {
            total_area += shape->area(); // Acumular el área
        }
    }
    return total_area;
}

// Mover todos los cuadrados
void Drawing::move_squares(double incX, double incY) {
    for (int i = 0; i < shapes->size(); ++i) {
        Shape* shape = shapes->get(i);

        // Verificar si es un cuadrado comparando área y perímetro
        double area = shape->area();
        double perimeter = shape->perimeter();
        if (std::abs(perimeter * perimeter - 16 * area) < 1e-6) {
            // Es un cuadrado si Perímetro² == 16 * Área
            shape->translate(incX, incY); // Mover el cuadrado
        }
    }
}
