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
    CString sString1("Hola muy buenas tardes a todos, un saludito  ");
    CString sRTrim = sString1.RTrim();
    CString sLTrim = sString1.LTrim();
    CString sTrim = sString1.Trim();

    printf("%s\n", sString1.ToCString());
    printf("%s\n", sLTrim.ToCString());
    printf("%s\n", sRTrim.ToCString());
    printf("%s\n", sTrim.ToCString());
}