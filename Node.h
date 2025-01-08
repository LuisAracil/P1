#include <ostream>

// Clase plantilla Node
template <typename T>
class Node {
public:
    T data;                 // Datos del nodo
    Node<T>* next;          // Puntero al siguiente nodo

    // Constructor
    Node(T data, Node<T>* next = nullptr) : data(data), next(next) {}

    // Operador de salida como función amiga
    friend std::ostream& operator<<(std::ostream& out, const Node<T>& node) {
        out << node.data;
        return out;
    }

    // Destructor virtual si se necesita herencia
    virtual ~Node() = default;
};

