#ifndef POINT2D_H
#define POINT2D_H

#include <ostream>
#include <cmath>

class Point2D {
	public:
		// Atributos
		double x; // Coordenada x
		double y; // Coordenada y

		// Constructor
		Point2D(double x = 0, double y = 0) : x{x}, y{y} {
		}
		
		// Calculo de distancia euclidiana
		static double distance(const Point2D &a, const Point2D &b);
		
		// Sobrecarga del operador ==
		friend bool operator==(const Point2D &a, const Point2D &b);

		// Sobrecarga del operador !=
		friend bool operator!=(const Point2D &a, const Point2D &b); 

		// Sobrecarga del operador <<
		friend std::ostream& operator<<(std::ostream &out, const Point2D &p);
};

#endif // POINT2D_H
