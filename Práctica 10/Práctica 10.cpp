#include <iostream>
#include "FileUtils.h"
#include "TList.h"

/*
PRÁCTICA 10
Añadir al namespace de utilidades creado en la práctica 5:
	a) Función que retorne una lista de cadenas (TList) con los números separados
	por comas presentes en un fichero. Diseñar la declaración de la función.
	b) Sacar por consola los números leídos.
*/

int main()
{
	TList* lLista = static_cast<TList*>(Practica5::GetNumList(Practica5::OpenFile("prueba.txt", "r")));
    printf("Tamano de la lista: %d\n", lLista->Size());

    printf("Primer elemento: %s\n", lLista->First());

    const char* sNextElem;
    while ((sNextElem = lLista->Next()) != nullptr)
    {
        printf("Siguiente elemento:  %s\n", sNextElem);
    }

    printf("Pop: %s\n", lLista->Pop());
    printf("Pop: %s\n", lLista->Pop());

    printf("Nuevo tamano de la lista: %d\n", lLista->Size());

    lLista->Reset();
    printf("Nuevo tamano de la lista despues del Reset: %d\n", lLista->Size());
}
