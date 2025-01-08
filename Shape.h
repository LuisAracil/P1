#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <stdexcept>
#include "Point2D.h"

class Shape {
	protected:
		// Atributo
		std::string color; // Color de la figura

		// Método de validación del color
		void validate_color(const std::string& c) {
				if (c != "red" && c != "green" && c != "blue") {
						throw std::invalid_argument("Invalid color");
				}
		}

	public:
		// Constructores
		Shape() : color{"red"} { } // Constructor por defecto
		Shape(const std::string& color) {
				validate_color(color);
				this->color = color;
		}

		// Métodos
		std::string get_color() const;
		void set_color(const std::string& c);
		
		// Métodos virtuales puros
		virtual double area() const = 0;
		virtual double perimeter() const = 0;
		virtual void translate(double incX, double incY) = 0;
		virtual void print() = 0;
};

#endif // SHAPE_H

