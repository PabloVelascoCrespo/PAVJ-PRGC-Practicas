#include <iostream>
#include "TList.h"

/*
PRÁCTICA 11
Constructores:
	a) Realizar un constructor de copia para la lista enlazada de la práctica 9.
	b) Realizar una función a la que se le pasa una lista y retorna otra lista con los
	GetReversedList(TList lstSrc);
	c) Observar las llamadas al constructor de copia y rediseñar la función
	(cambiando el prototipo de la misma para maximizar el rendimiento de la
	misma.

RESPUESTA APARTADO C:
    Al utilizar la función GetReversedList(TList lstSrc), hay que pasar la lista  por valor, 
    por lo que se va a llamar al constructor de copia para que se duplique la lista de entrada,
    por lo que puede empeorar el rendimiento. Para solucionarlo hay que modificar el método para
    que reciba la lista por referencia y así evitamos la copia.
*/

int main()
{
    TList lLista;

    lLista.Push("Hola");
    lLista.Push("Mundo");
    lLista.Push("Lista");
    lLista.Push("Enlazada");

    printf("Primer elemento: %s\n", lLista.First());

    const char* sNextElem;
    while ((sNextElem = lLista.Next()) != nullptr)
    {
        printf("Siguiente elemento:  %s\n", sNextElem);
    }
   
    printf("\nCreamos una copia de la lista y le añadimos un elemento\n");
    TList lLista2(lLista);
    lLista2.Push("Nuevo elemento");

    printf("Primer elemento: %s\n", lLista2.First());

    while ((sNextElem = lLista2.Next()) != nullptr)
    {
        printf("Siguiente elemento:  %s\n", sNextElem);
    }

    printf("\nVolvermos a comprobar la primera para asegurarnos que no se haya modificado\n");
    printf("Primer elemento: %s\n", lLista.First());

    while ((sNextElem = lLista.Next()) != nullptr)
    {
        printf("Siguiente elemento:  %s\n", sNextElem);
    }

    printf("\nLe damos la vuelta a la segunda lista:\n");

    lLista2= lLista2.GetReversedList();

    printf("Primer elemento de la lista invertida: %s\n", lLista2.First());

    while ((sNextElem = lLista2.Next()) != nullptr)
    {
        printf("Siguiente elemento:  %s\n", sNextElem);
    }
}