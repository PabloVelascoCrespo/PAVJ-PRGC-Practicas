#include <iostream>
#include "TList.h"

/*
PRÁCTICA 9
Clase: Creación de una lista enlazada "TList" que tenga los siguientes métodos:
    a) int Size(); Retorna el número de elementos.
    b) int Push(const char *psz); Añade la cadena a la lista.
    c) const char * First(); retorna el siguiente elemento de la lista.
    d) const char * Next(); retorna el siguiente elemento de la lista
    e) const char * Pop(); Elimina y retorna el primer elemento de la lista.
    f) void Reset(); Elimina todos los elementos de una lista
    
*/

int main()
{
    TList lLista;

    lLista.Push("Hola");
    lLista.Push("Mundo");
    lLista.Push("Lista");
    lLista.Push("Enlazada");

    printf("Tamano de la lista: %d\n", lLista.Size());

    printf("Primer elemento: %s\n", lLista.First());

    const char* sNextElem;
    while ((sNextElem = lLista.Next()) != nullptr)
    {
        printf("Siguiente elemento:  %s\n", sNextElem);
    }

    printf("Pop: %s\n", lLista.Pop());
    printf("Pop: %s\n", lLista.Pop());

    printf("Nuevo tamano de la lista: %d\n", lLista.Size());

    lLista.Reset();
    printf("Nuevo tamano de la lista despues del Reset: %d\n", lLista.Size());
}