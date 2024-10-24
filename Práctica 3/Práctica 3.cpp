#include <iostream>
#include <cstring>

/*
PRÁCTICA 3

Dada una tabla de cadenas.
    - Hacer una función que, dado un índice a la tabla de cadenas, retorne la cadena
    de índice dado si existe.
    - Hacer una función que, dado un índice a la tabla de cadenas, retorne la
    cadena de índice dado, si exsiste, invertida.

*/

const char* sTablaDeCadenas[]
{
    "Primera cadena",
    "Segunda",
    "Tercera",
    "Y ultima!"
};

const unsigned int uTablaDeCadenasSize = sizeof(sTablaDeCadenas) / sizeof(sTablaDeCadenas[0]);

const char* GetCadena(unsigned int _uIndex)
{
    if (_uIndex < uTablaDeCadenasSize)
    {
        return sTablaDeCadenas[_uIndex];
    }
    else
    {
        return nullptr;
    }
}

const char* GetCadenaInvertida(unsigned int _uIndex)
{
    const char* sCadenaOriginal = GetCadena(_uIndex);
    if (sCadenaOriginal == nullptr)
    {
        return nullptr;
    }

    size_t uCadenaAInvertirLength = std::strlen(sCadenaOriginal);
    char* sCadenaInvertida_ = new char[uCadenaAInvertirLength+1];

    for (unsigned int uIndex = 0; uIndex < uCadenaAInvertirLength; uIndex++)
    {
        sCadenaInvertida_[uIndex] = sCadenaOriginal[uCadenaAInvertirLength - uIndex - 1];
    }
    sCadenaInvertida_[uCadenaAInvertirLength] = '\0';
    return sCadenaInvertida_;
}

int main()
{
    unsigned int uIndex = 2;
    const char* CadenaConIndice = GetCadena(uIndex);
    printf("%s\n", CadenaConIndice);
    
    const char* CadenaConIndiceInvertida = GetCadenaInvertida(uIndex);
    printf("%s\n", CadenaConIndiceInvertida);
    delete CadenaConIndiceInvertida;
}