#include "TList.h"
#include "MyString.h"
#include "MyInt.h"
#include <iostream>

/*
PRÁCTICA 16

Interfaces:
    a) Implementar una lista con la misma funcionalidad que la TList pero que pueda
    almacenar cualquier tipo de elementos que implmenten un interfaz
*/

int main() 
{
    TList lista;

    lista.Push(MyString("Elemento de texto"));
    lista.Push(MyInt(42));
    lista.Push(MyString("Otro elemento de texto"));

    printf("Elementos en la lista original:\n");
    const IStorable* elem = lista.First();
    while (elem) 
    {
        if (const MyString* myElem = dynamic_cast<const MyString*>(elem)) 
        {
            myElem->Print();
        }
        else if (const MyInt* anotherElem = dynamic_cast<const MyInt*>(elem)) 
        {
            anotherElem->Print();
        }
        elem = lista.Next();
    }

    TList listaInvertida = lista.GetReversedList();

    std::cout << "\nElementos en la lista invertida:" << std::endl;
    elem = listaInvertida.First();
    while (elem) 
    {
        if (const MyString* myElem = dynamic_cast<const MyString*>(elem)) 
        {
            myElem->Print();
        }
        else if (const MyInt* anotherElem = dynamic_cast<const MyInt*>(elem)) 
        {
            anotherElem->Print();
        }
        elem = listaInvertida.Next();
    }
}