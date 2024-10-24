#include <iostream>

/*
PRÁCTICA 1

1. Operaciones con bits. Dado un entero de 32 bits que contiene la
siguiente información de un personaje:
	- Los 8 bits de mayor peso contienen la vida del personaje
	- Los siguientes 8 bits el número de balas
	- Los siguientes 4 bits el número de compañeros
	- El bit 0 el indicado de modo invulnerable
	- El bit 1 el indicador de balas infinitas
	- El bit 2 el indicador de escudo presente
	- El bit 3 el indicador de modo "berserker"

Realizar las siguientes funciones:
	- Función que, dado el entero anterior retorne el número de balas
	- Función que, dado el entero anterior añada un número de balas a 
	las existentes
	- Función que dado el entero anterior retorne si está activo el modo 
	de balas infinitas
	- Función que, dado el entero anterior active el modo de
	balas infinitas
*/

unsigned int GetVida(unsigned int _uValue)
{
	return _uValue >> 24;
}

unsigned int GetNumBalas(unsigned int _uValue)
{
	unsigned int uNumBalas = _uValue << 8;
	return uNumBalas >> 24;
}

unsigned int AnadirBalas(unsigned int _uValue, int _iBalasToAdd)
{
	if (_iBalasToAdd + GetNumBalas(_uValue) > UCHAR_MAX)
	{
		_uValue = _uValue | (UCHAR_MAX << 16);
	}
	else
	{
		_uValue = _uValue + (_iBalasToAdd << 16);
	}
	return _uValue;
}

bool GetBalasInfinitasActivadas(unsigned int _uValue)
{
	#define MASK_MODIFICAR_BALAS_INFINITAS 0x0000002
	return MASK_MODIFICAR_BALAS_INFINITAS & _uValue;
}

unsigned int SetBalasInfinitas(unsigned int _uValue, bool _bSetting)
{
	if (_bSetting)
	{
		return _uValue | MASK_MODIFICAR_BALAS_INFINITAS;
	}
	else
	{
		return _uValue & ~MASK_MODIFICAR_BALAS_INFINITAS;
	}
}

int main()
{	// VIDA			-> 137 -> 89
	// NUM. BALAS	->  13 -> 0D
	// COMPAÑEROS	->   7 ->  7
	// 2 ceros porque hay 8 bytes vacíos
	// BERSERKER		-> TRUE  -> 1
	// ESCUDO			-> TRUE  -> 1
	// BALAS INFINITAS	-> FALSE -> 0
	// INVULNERABLE		-> FALSE -> 0
	

	unsigned int uMiInformacion = 0x890D700C;

	unsigned int uNumBalas = GetNumBalas(uMiInformacion);
	printf("El numero de balas inicial es: %d\n", uNumBalas);

	printf("Vida: %d\n", GetVida(uMiInformacion));

	int iBalasToAdd = 1;
	printf("Anadiendo %d balas...\n", iBalasToAdd);
	uMiInformacion = AnadirBalas(uMiInformacion, iBalasToAdd);

	uNumBalas = GetNumBalas(uMiInformacion);
	printf("El numero de balas actual es: %d\n", uNumBalas);

	printf("Vida: %d\n", GetVida(uMiInformacion));

	unsigned int bBalasInfinitasActivadas = GetBalasInfinitasActivadas(uMiInformacion);
	if (bBalasInfinitasActivadas == false)
	{
		printf("El modo de balas infinitas esta: DESACTIVADO\n");
	}
	else
	{
		printf("El modo de balas infinitas esta: ACTIVADO\n");
	}

	printf("Activando el modo de balas infinitas...\n");
	uMiInformacion = SetBalasInfinitas(uMiInformacion, true);

	bBalasInfinitasActivadas = GetBalasInfinitasActivadas(uMiInformacion);
	if (bBalasInfinitasActivadas == 0)
	{
		printf("El modo de balas infinitas esta: DESACTIVADO\n");
	}
	else
	{
		printf("El modo de balas infinitas esta: ACTIVADO\n");
	}
}