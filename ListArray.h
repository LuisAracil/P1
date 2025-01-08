#ifndef LISTARRAY_H
#define LISTARRAY_H

#include <stdexcept>
#include <ostream>
#include "List.h"

template <typename T>

class ListArray : public List<T> {
private:
        T* arr;                  // Puntero al inicio del array
        int max;                 // Tamaño actual del array
        int n;                   // Número actual de elementos
        static const int MINSIZE = 2; // Tamaño mínimo del array

        // Redimensiona el array a newCapacity elementos
        void resize(int newCapacity) {
                T* newArr = new T[newCapacity];
                for (int i = 0; i < n; ++i) {
                        newArr[i] = arr[i];
                }
                delete[] arr;
                arr = newArr;
                max = newCapacity;
        }

public:

        // Metodo constructor 
        ListArray() {
                arr = new T[MINSIZE];
                max = MINSIZE;
                n = 0;
        }

        // Metodo destuctor 
        ~ListArray() {
                delete[] arr;
        }

        // Sobrecarga del operador []. Devuelve el elemento situado en la posición pos
        // Lanza una excepción std::out_of_range si la posición no es válida (fuera del intervalo [0, size()-1]).
        T operator[](int pos) const {
                if (pos < 0 || pos >= n) {
                        throw std::out_of_range("Posición fuera de rango");
                }
                return arr[pos];
        }

        // Sobrecarga global del operador << para imprimir una instancia de ListArray<T> por pantalla
        friend std::ostream& operator<<(std::ostream& out, const ListArray<T>& list) {
                out << "[";
                for (int i = 0; i < list.n; ++i) {
                        out << list.arr[i];
                        if (i < list.n - 1) {
                                out << ", ";
                        }
                }
                out << "]";
                return out;
        }

        // Inserta el elemento e en la posición pos
        // Lanza una excepción std::out_of_range si la posición pos no es válida (fuera del intervalo [0, size()]).
        void insert(int pos, T e) override {
                if (pos < 0 || pos > n) {
                        throw std::out_of_range("Posición fuera de rango");
                }
                if (n == max) {
                        resize(max * 2);
                }
                // Desplazar los elementos hacia la derecha para hacer espacio
                for (int i = n; i > pos; --i) {
                        arr[i] = arr[i - 1];
                }
                arr[pos] = e; // Insertar el elemento en la posición
                ++n;          // Incrementar el tamaño
        }

        // Agregar un elemento al final de la lista
        void append(T e) override {
                insert(n, e);
        }

	// Agregar un elemento al inicio de la lista
        void prepend(T e) override {
                insert(0, e);
        }

        // Eliminar un elemento en la posición pos
        // Lanza una excepción std::out_of_range si la posición no es válida (fuera del intervalo [0, size()-1]).
        T remove(int pos) override {
                if (pos < 0 || pos >= n) {
                        throw std::out_of_range("Posición fuera de rango");
                }
                T removedElement = arr[pos]; // Guardar el elemento a eliminar
                // Desplazar los elementos hacia la izquierda para llenar el hueco
                for (int i = pos; i < n - 1; ++i) {
                        arr[i] = arr[i + 1];
                }
                --n; // Reducir el tamaño

                // Si el número de elementos actuales (n) es menor o igual al 25% de la capacidad actual (max), 
		// y el tamaño resultante tras reducir a la mitad sería al menos igual al tamaño mínimo permitido (MINSIZE), redimensionamos
                if (n > 0 && n <= max / 4 && max / 2 >= MINSIZE) {
                        resize(max / 2);
                }

                return removedElement;
        }

        // Devuelve el elemento situado en la posición pos
        // Lanza una excepción std::out_of_range si la posición no es válida (fuera del intervalo [0, size()-1]).
        T get(int pos) const override {
                if (pos < 0 || pos >= n) {
                        throw std::out_of_range("Posición fuera de rango");
                }
                return arr[pos];
        }

        // Busca el índice del primer elemento que coincide con e
        // Devuelve -1 si no se encuentra el elemento
        int search(T e) const override {
                for (int i = 0; i < n; ++i) {
                        if (arr[i] == e) {
                                return i;
                        }
                }
                return -1;
        }

        // Devuelve true si la lista está vacía, false en caso contrario
        bool empty() const override {
                return n == 0;
        }

        // Devuelve el número de elementos en la lista
        int size() const override {
                return n;
        }
};

#endif

