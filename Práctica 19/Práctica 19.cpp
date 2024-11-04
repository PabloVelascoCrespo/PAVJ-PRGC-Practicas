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

    std::cout << "Lista de enteros:" << std::endl;
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

    std::cout << "\nLista de cadenas:" << std::endl;
    const std::string* str = listaString.First();
    while (str)
    {
        std::cout << *str << std::endl;
        str = listaString.Next();
    }

    TList<int> listaIntInvertida = listaInt.GetReversedList();
    std::cout << "\nLista de enteros invertida:" << std::endl;
    num = listaIntInvertida.First();
    while (num)
    {
        std::cout << *num << std::endl;
        num = listaIntInvertida.Next();
    }

    return 0;
}