#include <iostream>
#include "FileUtils.h"

/*
PRÁCTICA 6

Prestando especial atención a cómo se organiza el código en
ficheros.
    a) Realizar una función que retorne el número de apariciones de una cadena en
    un fichero
    b) Función que retorna la suma de los números enteros separados por coma
    presentes en un fichero
*/

int main()
{
    char* sCadena = _strdup("hola");
    unsigned int uContador = VecesQueApareceCadenaEnFichero(sCadena, OpenFile("prueba.txt", "r"));
    printf("%d\n", uContador);

    int iSuma = SumaNumerosFichero(OpenFile("prueba.txt", "r"));
    printf("%d\n", iSuma);
}