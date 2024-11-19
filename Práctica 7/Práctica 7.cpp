#include <iostream>
#include "FileUtils.h"

/*
PRÁCTICA 7

Namespaces.
    a) Organizar el código de la práctica 5 usando un namespace.
    b) Organizar el código de la práctica 6 usando un namespace.
*/

int main()
{
    // Probamos los métodos de la práctica 5 pero usando el namespace
	// Abrir
	void* pFile = Practica5::OpenFile("prueba.txt", "r");

	//Leer
	unsigned int const uBufferSize = 128;
	char sBuffer[uBufferSize];
	size_t uReadChars = Practica5::ReadFile(sBuffer, uBufferSize, pFile);
	sBuffer[uReadChars] = '\0';
	printf("El contenido del fichero es: %s\n", sBuffer);
	printf("Se han leido %zu caracteres\n", uReadChars);

	//Cerrar
	bool bClosed = Practica5::CloseFile(pFile);
	if (bClosed == true)
	{
		printf("Se ha cerrado\n");
	}
	else
	{
		printf("No se ha cerrado\n");
	}

	//Escribir
	pFile = Practica5::OpenFile("prueba.txt", "a");
	sBuffer[0] = 'x';
	sBuffer[1] = '\0';

	size_t uWritenChars = Practica5::WriteFile(sBuffer, strlen(sBuffer), pFile);
	printf("Se va a concatenar %s\n", sBuffer);
	printf("Se han escrito %zu caracteres\n", uWritenChars);

	Practica5::CloseFile(pFile);
	pFile = Practica5::OpenFile("prueba.txt", "r");
	uReadChars = Practica5::ReadFile(sBuffer, uBufferSize, pFile);
	sBuffer[uReadChars] = '\0';
	printf("El fichero ahora contiene %s\n", sBuffer);
	printf("Se han leido %zu caracteres\n", uReadChars);
	Practica5::CloseFile(pFile);

    // Probamos los métodos de la práctica 6 pero usando el namespace
	char* sCadena = _strdup("hola");
	unsigned int uContador = Practica6::VecesQueApareceCadenaEnFichero(sCadena, Practica5::OpenFile("prueba.txt", "r"));
	printf("%d\n", uContador);

	int iSuma = Practica6::SumaNumerosFichero(Practica5::OpenFile("prueba.txt", "r"));
	printf("%d\n", iSuma);
}