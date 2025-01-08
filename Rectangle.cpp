#include "Rectangle.h"
#include <cmath>
#include <iostream>

// Constructor por defecto
Rectangle::Rectangle() : vs(new Point2D[N_VERTICES]{
    Point2D(-1, 0.5), Point2D(1, 0.5), Point2D(1, -0.5), Point2D(-1, -0.5)}) {}

// Constructor con parámetros
Rectangle::Rectangle(std::string color, Point2D* vertices) : Shape(color), vs(new Point2D[N_VERTICES]) {
    if (!check(vertices)) {
        delete[] vs;  // Limpiar memoria si los vértices no forman un rectángulo válido
        throw std::invalid_argument("Los vértices no forman un rectángulo válido.");
    }
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i] = vertices[i];
    }
}

// Constructor de copia
Rectangle::Rectangle(const Rectangle& r) : Shape(r.color), vs(new Point2D[N_VERTICES]) {
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i] = r.vs[i];
    }
}

// Destructor
Rectangle::~Rectangle() {
    delete[] vs;  // Liberar la memoria dinámica
}

// Implementación del método `area()`
double Rectangle::area() const {
    double width = Point2D::distance(vs[0], vs[1]);
    double height = Point2D::distance(vs[1], vs[2]);
    return width * height;
}

// Implementación del método `perimeter()`
double Rectangle::perimeter() const {
    double width = Point2D::distance(vs[0], vs[1]);
    double height = Point2D::distance(vs[1], vs[2]);
    return 2 * (width + height);
}

// Implementación del método `translate()`
void Rectangle::translate(double incX, double incY) {
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i].x += incX;  // Asumimos que Point2D tiene miembros x e y accesibles
        vs[i].y += incY;
    }
}


// Implementación del método `print()`
void Rectangle::print() {
    std::cout << "Rectángulo - Color: " << color << ", Vértices: ";
    for (int i = 0; i < N_VERTICES; ++i) {
        std::cout << vs[i] << " ";
    }
    std::cout << std::endl;
}

// Obtener el vértice en el índice especificado
Point2D Rectangle::get_vertex(int ind) const {
    if (ind < 0 || ind >= N_VERTICES) {
        throw std::out_of_range("Índice fuera de rango.");
    }
    return vs[ind];
}

// Sobrecarga del operador [] para acceder a los vértices
Point2D Rectangle::operator[](int ind) const {
    return get_vertex(ind);
}

// Modificar los vértices del rectángulo
void Rectangle::set_vertices(Point2D* vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Los vértices no forman un rectángulo válido.");
    }
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i] = vertices[i];
    }
}

// Sobrecarga del operador = para asignación de rectángulos
Rectangle& Rectangle::operator=(const Rectangle& r) {
    if (this != &r) {
        delete[] vs;
        vs = new Point2D[N_VERTICES];
        for (int i = 0; i < N_VERTICES; ++i) {
            vs[i] = r.vs[i];
        }
        color = r.color;
    }
    return *this;
}

// Sobrecarga del operador << para imprimir el rectángulo
std::ostream& operator<<(std::ostream& out, const Rectangle& r) {
    Rectangle temp = r;  // Crear una copia no constante del objeto `r`
    temp.print();  // Llamar a print() sobre el objeto temporal
    return out;
}


// Verificar si los vértices conforman un rectángulo válido
bool Rectangle::check(Point2D* vertices) {
    double d01 = Point2D::distance(vertices[0], vertices[1]);
    double d23 = Point2D::distance(vertices[2], vertices[3]);
    double d12 = Point2D::distance(vertices[1], vertices[2]);
    double d30 = Point2D::distance(vertices[3], vertices[0]);

    return (d01 == d23) && (d12 == d30);
}

