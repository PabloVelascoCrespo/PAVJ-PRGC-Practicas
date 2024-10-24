#include "FileUtils.h"
#include <cstdio>
#include <string>
/*
PRÁCTICA 5

Implementar funciones para abstraernos del acceso a
fichero
a) OpenFile: Abre un fichero. Recibe como parámetro el nombre del fichero y el
modo de apertura (lectura o escritura), retorna un identificador del fichero
abierto.

b) CloseFile: Cierra un fichero. Recibe como parámetro el identificador del fichero
a cerrar.

c) ReadFile: Lee los 'n' caracteres indicados del fichero del identificador indicado,
los deja en el buffer pasado y retorna el número de caracteres realmente
leídos.

d) WriteFile: Escribe los 'n' caracteres del buffer pasado en el fichero de 
identificador pasado y retorna los caracteres escritos.

Para ello se tiene que tener en cuenta:
e) Separar declaraciones de definiciones

f) En la declaración no puede aparecer ninguna referenci a la librería que se
usará para la implementación.

g) Se pueden utilizar cualqeuir API de acceso a ficheros para su implementación
(por ejemplo fopen, fclose, ...)

h) Se tiene que probar el correcto funcionamiento realizando
llamadas de prueba en un "main".
*/

int main()
{
	// Abrir
	void* pFile = OpenFile("F:\\prueba.txt", "r");

	//Leer
	unsigned int const uBufferSize = 128;
	char sBuffer[uBufferSize];
	size_t uReadChars = ReadFile(sBuffer,uBufferSize,pFile);
	sBuffer[uReadChars] = '\0';
	printf("El contenido del fichero es: %s\n", sBuffer);
	printf("Se han leido %zu caracteres\n", uReadChars);

	//Cerrar
	bool bClosed = CloseFile(pFile);
	if (bClosed == true)
	{
		printf("Se ha cerrado\n");
	}
	else
	{
		printf("No se ha cerrado\n");
	}

	//Escribir
	pFile = OpenFile("F:\\prueba.txt", "a");
	sBuffer[0] = 'x';
	sBuffer[1] = '\0';

	size_t uWritenChars = WriteFile(sBuffer, strlen(sBuffer), pFile);
	printf("Se va a concatenar %s\n", sBuffer);
	printf("Se han escrito %zu caracteres\n", uWritenChars);
	
	CloseFile(pFile);
	pFile = OpenFile("F:\\prueba.txt", "r");
	uReadChars = ReadFile(sBuffer, uBufferSize, pFile);
	sBuffer[uReadChars] = '\0';
	printf("El fichero ahora contiene %s\n", sBuffer);
	printf("Se han leido %zu caracteres\n", uReadChars);
	CloseFile(pFile);
}
