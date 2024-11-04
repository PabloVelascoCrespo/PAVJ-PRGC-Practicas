#include "TList.h"
#include <iostream>

/*
PRÁCTICA 19

Templates:
	- Implementar una lista con la misma funcionalidad que la TList pero que pueda
	almacenar cualquier tipo de elementos mediante el uso de templates
*/

int main()
{

    TList<int> listaInt;
    listaInt.Push(10);
    listaInt.Push(20);
    listaInt.Push(30);

    printf("Lista de enteros:\n");
    const int* num = listaInt.First();
    while (num) 
    {
        std::cout << *num << std::endl;
        num = listaInt.Next();
    }

    // Lista de cadenas
    TList<std::string> listaString;
    listaString.Push("Hola");
    listaString.Push("Mundo");

    printf("\nLista de cadenas:\n");
    const std::string* str = listaString.First();
    while (str)
    {
        std::cout << *str << std::endl;
        str = listaString.Next();
    }

    TList<int> listaIntInvertida = listaInt.GetReversedList();
    printf("\nLista de enteros invertida:\n");
    num = listaIntInvertida.First();
    while (num)
    {
        std::cout << *num << std::endl;
        num = listaIntInvertida.Next();
    }

    return 0;
}