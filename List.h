#ifndef LIST_H
#define LIST_H


template <typename T>
class List {
public:
    // Inserta un elemento en una posición específica
    virtual void insert(int pos, T e) = 0;

    // Agrega un elemento al final
    virtual void append(T e) = 0;

    // Agrega un elemento al inicio
    virtual void prepend(T e) = 0;

    // Elimina un elemento en una posición específica y lo devuelve
    virtual T remove(int pos) = 0;

    // Obtiene un elemento en una posición específica
    virtual T get(int pos) const = 0;

    // Busca un elemento y devuelve su posición, o -1 si no lo encuentra
    virtual int search(T e) const = 0;

    // Devuelve si la lista está vacía
    virtual bool empty() const = 0;

    // Devuelve el tamaño de la lista
    virtual int size() const = 0;
};

#endif
