#include "TFile.h"
#include <cstdio>
#include <string>
/*
PRÁCTICA 8

Clases.
    a) Implementar la funcionalidad de la práctica 5 definiendo un tipo nuevo "TFile".

*/

int main()
{
	TFile TFile;

	// Abrir
	void* pFile = TFile.OpenFile("prueba.txt", "r");

	//Leer
	unsigned int const uBufferSize = 128;
	char sBuffer[uBufferSize];
	size_t uReadChars = TFile.ReadFile(sBuffer, uBufferSize);
	sBuffer[uReadChars] = '\0';
	printf("El contenido del fichero es: %s\n", sBuffer);
	printf("Se han leido %zu caracteres\n", uReadChars);

	//Cerrar
	bool bClosed = TFile.CloseFile();
	if (bClosed == true)
	{
		printf("Se ha cerrado\n");
	}
	else
	{
		printf("No se ha cerrado\n");
	}

	//Escribir
	pFile = TFile.OpenFile("prueba.txt", "a");
	sBuffer[0] = 'x';
	sBuffer[1] = '\0';

	size_t uWritenChars = TFile.WriteFile(sBuffer, strlen(sBuffer));
	printf("Se va a concatenar %s\n", sBuffer);
	printf("Se han escrito %zu caracteres\n", uWritenChars);

	TFile.CloseFile();
	pFile = TFile.OpenFile("prueba.txt", "r");
	uReadChars = TFile.ReadFile(sBuffer, uBufferSize);
	sBuffer[uReadChars] = '\0';
	printf("El fichero ahora contiene %s\n", sBuffer);
	printf("Se han leido %zu caracteres\n", uReadChars);
	TFile.CloseFile();
}
