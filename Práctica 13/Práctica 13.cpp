#include <iostream>

/*
PRÁCTICA 13
Dado el ejercicio de imágenes de la sesión 8.
    a) Implementar una función para la clase "png" que simule la eliminación del
    canal "alpha".
    b) Implementar una función que dada una tabla de imáganes de cualquier tipo
    eliminar al canal alfa de todas las que sean "png".
*/

class CImage
{
};

class CPNG : CImage
{
private:
    void RemoveAlphaChannel() {
        printf("Se ha eliminado el canal Alpha con éxito\n");
    }
};

int main()
{
    CImage* tImagenes[10];
    tImagenes[0] = new CPNG();
}


