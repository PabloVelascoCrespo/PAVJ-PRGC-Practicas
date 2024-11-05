#include <iostream>
#include <cstring>
/*
PRÁCTICA 2

2. Operaciones con punteros
    - Dado un entero obtener por separado cada uno de los bytes que lo forman utilizando para ello "casting" y aritmética de punteros
    - Dada la tabla de enteros "int tabla[] = {1,3,2,5,3,0xFFFFFFFF,2}" obtener el entero mayor usando puntero y aritmética de punteros
    - Como el apartado anterior pero en lugar de obtener el entero mayor obtener el byte mayor (usar casting)
    - Dada una cadena de caracteres darle la vuelta

*/

void ObtenerBytes(int _iVar)
{
    unsigned char* pVar = reinterpret_cast<unsigned char*>(&_iVar);

    printf("Los bytes del número %d son: ", _iVar);
    for (int iIndex = 0; iIndex < sizeof(_iVar); iIndex++)
    {
        printf("%hhx ", static_cast<int>(pVar[iIndex]));
    }
    printf("\n");
}

int ObtenerMaximo(int _tTabla[])
{
    int* pTabla = _tTabla;
    int iMax_ = -99999999;
    for (int iIndex = 0; iIndex < sizeof(_tTabla); ++iIndex)
    {
        if (*(pTabla + iIndex) > iMax_)
        {
            iMax_ = *(pTabla + iIndex);
        }
    }
    return iMax_;
}

int ObtenerMayorByte(int _tTabla[]) 
{
    int* p = _tTabla;
    int iMax_ = INT_MIN;

    for (int iIndex = 0; iIndex < sizeof(_tTabla); ++iIndex)
    {
        unsigned char* pVar = reinterpret_cast<unsigned char*>(&*(p + iIndex));

        for (int iIndex2 = 0; iIndex2 < sizeof(*(p + iIndex2)); iIndex2++)
        {
            int iByte = static_cast<int>(pVar[iIndex2]);
            if (iByte > iMax_)
            {
                iMax_ = iByte;
            }
        }
    }
    return iMax_;
}

void DarVueltaCadena(char* _sCadena)
{
    char* cInicio = _sCadena;
    char* cFin = _sCadena + strlen(_sCadena) - 1;

    while (cInicio < cFin) {
        char cAux = *cInicio;
        *cInicio = *cFin;
        *cFin = cAux;

        cInicio++;
        cFin--;
    }
}

int main() {
    int iVar = 0x12345678;
    ObtenerBytes(iVar);

    int tabla[] = { 1,3,2,5,3,static_cast<int>(0xFFFFFFFF),2 };
    int iMax = ObtenerMaximo(tabla);
    printf("El mayor valor de la tabla es: %d\n", iMax);

    int iMaxByte = ObtenerMayorByte(tabla);
    printf("El mayor byte de la tabla es: %hhx\n", iMaxByte);

    char Cadena[] = "Hola buenas tardes";
    DarVueltaCadena(Cadena);
    printf("%s", Cadena);
}
