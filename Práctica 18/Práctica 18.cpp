#include <iostream>

/*
PRÁCTICA 18
Implementar un sistema de Macros que permita la detección de
"memory leaks".
    a) El sistema sólo se activará cuando esté definida la macro
    MEMORY_LEAKS_MONITOR. Si la macro no está definida se tiene que
    funcionar sin ningún control de "memory leaks".
    b) Se definirán las macros NEW y NEW_ARRAY. Cuando se pida memoria se
    utilizarán dichas macros en lugar de los operaodres new y new[].
    c) Se definirán las macros DELETE y DELETE_ARRAY. Cuando se libere la memoria se
    utilizarán dichas macros en lugar de los operadores delete y delete [].
    d) Se definirá una macro para mostrar por la ventana de "output" del Visual
    Studio (usando la función OutputDebugString): las direcciones de memoria y el 
    tamaño pendientes de liberar. El formato de salida será similar al de los
    mensajes de aviso que saca VS para posibilitar que haciendo clic sobre el 
    mensaje nos lleve al sitio donde se encuentra la fuga de memoria.
*/

int main()
{

}