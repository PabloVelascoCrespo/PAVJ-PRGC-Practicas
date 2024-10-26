#ifndef TLIST_H
#define TLIST_H

#include "IStorable.h"
#include <iostream>

template <typename T>
class TList {
    static_assert(std::is_base_of<IStorable, T>::value, "T debe derivar de IStorable");

private:
    // Nodo de la lista enlazada
    struct Node {
        T* data;
        Node* next;

        // Constructor del nodo
        Node(const T& element) : data(element.Clone()), next(nullptr) {}

        // Destructor del nodo
        ~Node() { delete data; }
    };

    Node* head;
    Node* current;
    int size;

public:
    TList() : head(nullptr), current(nullptr), size(0) {}

    // Constructor de copia
    TList(const TList& other) : head(nullptr), current(nullptr), size(0) {
        Node* temp = other.head;
        while (temp) {
            this->Push(*(temp->data));
            temp = temp->next;
        }
    }

    // Destructor
    ~TList() {
        Reset();
    }

    // Añadir un elemento a la lista
    void Push(const T& element) {
        Node* newNode = new Node(element);

        if (!head) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }

    // Obtener el tamaño de la lista
    int Size() const {
        return size;
    }

    // Obtener el primer elemento
    const T* First() {
        current = head;
        if (current) {
            return current->data;
        }
        return nullptr;
    }

    // Obtener el siguiente elemento
    const T* Next() {
        if (current && current->next) {
            current = current->next;
            return current->data;
        }
        return nullptr;
    }

    // Eliminar y retornar el primer elemento
    T* Pop() {
        if (!head) {
            return nullptr;
        }

        Node* temp = head;
        T* dataCopy = temp->data->Clone();

        head = head->next;
        delete temp;
        size--;

        return dataCopy;
    }

    // Eliminar todos los elementos de la lista
    void Reset() {
        while (head) {
            Pop();
        }
        current = nullptr;
    }

    // Obtener una lista invertida
    TList GetReversedList() const {
        TList reversedList;
        Node* temp = head;
        while (temp) {
            Node* newNode = new Node(*(temp->data));
            newNode->next = reversedList.head;
            reversedList.head = newNode;
            reversedList.size++;
            temp = temp->next;
        }
        return reversedList;
    }
};

#endif // TLIST_H
