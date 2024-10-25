#include <iostream>
#include "CString.h"

/*
Operadores:
    a) Dada la clase "CString" declarada en el fichero "String.h" implimentar en un 
    fichero .cpp toda la funcionalidad de dicha clase.
    b) Mejora: Implementar funcionalidad para que se puedan realizar operaciones de tipo:
        i) CString str("hola");
        ii) CString str2 = "Hola " + str + " caracola";
*/

int main()
{
    CString sString1("12345");
    CString sString2 = sString1.RSet(10,'x');
    printf("%s\n", sString2.ToCString());
}