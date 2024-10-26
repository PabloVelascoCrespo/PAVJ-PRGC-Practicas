#include <iostream>

/*
PRÁCTICA 15
Diseño polimórfico.
	a) Diseñar e implementar (simuladamente) el esqueleto de un sistema jerárquico
	con funciones virtuales que gestione la apertura, cierre, lectura y escritura de
	streams
	b) Los streams que deberá contemplar son:
		i) Ficheros
		ii) Puerto serie
		ii) Conexión TC
	c) Habrá una clase base CStream y las clases derivadas CFile, CCom, CTcp

*/

class CStream
{
public:
	virtual void open() = 0;
	virtual void close() = 0;
	virtual void read() = 0;
	virtual void write(const char* data) = 0;
};

class CFile : public CStream
{
public:
	void open() override
	{
		printf("Abriendo archivo\n");
	}
	void close() override
	{
		printf("Cerrando archivo\n");
	}
	void read() override
	{
		printf("Leyendo archivo\n");
	}
	void write(const char* data) override
	{
		printf("Escribiendo: %s en un archivo\n", data);
	}
};

class CCom : public CStream
{
public:
	void open() override
	{
		printf("Abriendo puerto serie\n");
	}
	void close() override
	{
		printf("Cerrando puerto serie\n");
	}
	void read() override
	{
		printf("Leyendo puerto serie\n");
	}
	void write(const char* data) override
	{
		printf("Escribiendo: %s en un puerto serie\n", data);
	}
};

class CTcp : public CStream
{
public:
	void open() override
	{
		printf("Abriendo conexion TCP\n");
	}
	void close() override
	{
		printf("Cerrando conexion TCP\n");
	}
	void read() override
	{
		printf("Leyendo conexion TCP\n");
	}
	void write(const char* data) override
	{
		printf("Escribiendo: %s en un conexion TCP\n", data);
	}
};

void TestStream(CStream * _CStream)
{
	_CStream->open();
	_CStream->close();
	_CStream->read();
	_CStream->write("Prueba de datos");
}

int main()
{
	CFile fileStream;
	CCom comStream;
	CTcp tcpStream;

	printf("Probando CFile:\n");
	TestStream(&fileStream);

	printf("\nProbando CCom:\n");
	TestStream(&comStream);

	printf("\nProbando CTcp:\n");
	TestStream(&tcpStream);
}
