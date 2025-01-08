#include <stdexcept>
#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

private:
    Node<T>* first; // Puntero al primer nodo de la secuencia enlazada
    int n;          // Número de elementos en la lista

public:
    // Constructor por defecto
    ListLinked() {
        first = nullptr;
        n = 0; 
    }


    // Destructor para liberar memoria
    ~ListLinked() {
        while (first != nullptr) {
            Node<T>* aux = first->next;
            delete first;
            first = aux;
        }
    }


    // Sobrecarga del operador []
    T operator[](int pos) {
        return get(pos);
    }


    // Sobrecarga global del operador <<
    friend std::ostream& operator<<(std::ostream& out, const ListLinked<T>& list) {
        Node<T>* current = list.first;
        while (current != nullptr) {
            out << current->data << " -> ";
            current = current->next;
        }
        out << "nullptr";
        return out;
    }


    // Inserta el elemento e en la posición pos
    void insert(int pos, T e) override {
        if (pos < 0 || pos > n) {
            throw std::out_of_range("Posición fuera de rango");
        }

        Node<T>* newNode = new Node<T>(e);

        if (pos == 0) {
            // Insertar al inicio
            newNode->next = first;
            first = newNode;
        } else {
            // Buscar el nodo anterior a la posición
            Node<T>* current = first;
            for (int i = 0; i < pos - 1; ++i) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }

        ++n;
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
    T remove(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición fuera de rango");
        }

        Node<T>* toDelete = nullptr;
        T removedData;

        if (pos == 0) {
            // Eliminar el primer nodo
            toDelete = first;
            removedData = toDelete->data;
            first = first->next;
        } else {
            // Buscar el nodo anterior al que queremos eliminar
            Node<T>* current = first;
            for (int i = 0; i < pos - 1; ++i) {
                current = current->next;
            }
            toDelete = current->next;
            removedData = toDelete->data;
            current->next = toDelete->next;
        }

        delete toDelete;
        --n;

        return removedData;
    }


    // Devuelve el elemento situado en la posición pos
    T get(int pos) const override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición fuera de rango");
        }

        Node<T>* current = first;
        for (int i = 0; i < pos; ++i) {
            current = current->next;
        }

        return current->data;
    }


    // Busca el elemento e en la lista y devuelve su posición, o -1 si no se encuentra
    int search(T e) const override {
        Node<T>* current = first;
        int pos = 0;

        while (current != nullptr) {
            if (current->data == e) {
                return pos; // Elemento encontrado
            }
            current = current->next;
            ++pos;
        }

        return -1; // Elemento no encontrado
    }


    // Devuelve el número de elementos en la lista
    int size() const override {
        return n;
    }


    // Comprueba si la lista está vacía
    bool empty() const override {
        return n == 0;
    }
};

