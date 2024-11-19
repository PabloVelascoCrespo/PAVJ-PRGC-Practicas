#include <iostream>
#include <cstddef>  // para usar offsetof

/*
PR�CTICA 14

Responder a las siguientes preguntas y proporcionar c�digo
documentado cuya ejecuci�n demuestre lo que se est� respondiendo:

	a) �Cu�nto espacio ocupa toda la tabla de funciones virtuales?
        R: Depende del n�mero de funciones virtuales en la clase y del tama�o de un puntero en el sistema, por ejemplo, si tenemos 5 funciones virtuales en un sistema de 64 bits, la vtable ocupar� 5x8 = 40 bytes
	b) �D�nde est� situada la tabla de funciones virtuales?
        R: El puntero a la tabla de funciones virtuales est� en el principio de cada objeto que contiene funciones virtuales.
	c) �Cu�nto espacio ocupa adicionalmente un objeto por tener una tabla de funciones virtuales?
        R: Un objeto con m�todos virtuales ocupa adicionalmente el tama�o de un puntero en memoria, ya que necesita almacenar un puntero a la VTable, es decir 8 bytes en un sistema de 64 bits o 4 en un sistema de 32 bits.
	d) �Qu� pasa si llamo a un m�todo virtual desde el constructor?
        R: Solo se llama a la implementaci�n en la clase base, ignorando cualquier sobrecarga en las clases derivadas. Esto sucede porque, durante la construcci�n del objeto, la VTable a�n no est� completamente configurada para la clase derivada.
	e) Comparar la llamada a una funci�n virtual con la llamada a una funci�n no virtual. �Cu�ntos pasos adicionales tienen qu erealizarse para llamar a una funci�n cuando esta es virtual?
        R: La llamada a una funci�n virtual tiene un paso adicional: acceder a la VTable para obtener la direcci�n de la funci�n a ejecutar.
*/

class BaseNonVirtual
{
public:
    void nonVirtualMethod()
    {
        printf("Base nonVirtualMethod\n");
    }
    void anotherNonVirtualMethod()
    {
        printf("Base nonVirtualMethod\n");
    }
};

class Base
{
public:
    virtual void virtualMethod()
    {
        printf("Base virtualMethod\n");
    }
    void nonVirtualMethod()
    {
        printf("Base nonVirtualMethod\n");
    }
};

class Derived : public Base
{
public:
    void virtualMethod() override
    {
        printf("Derived virtualMethod\n");
    }
};

int main()
{
    // a) �Cu�nto espacio ocupa toda la tabla de funciones virtuales?
    Derived d;
    Base* basePtr = &d;

    printf("a)\nTama�o de un puntero (aproximaci�n de la VTable): %zu bytes\n\n", sizeof(void*));

    // b) �D�nde est� situada la tabla de funciones virtuales?
    printf("b)\nDirecci�n del objeto d: %p\n", basePtr);
    printf("Direcci�n del puntero a la VTable (primer miembro): %p\n\n", *(void***)(basePtr));

    // c) �Cu�nto espacio ocupa adicionalmente un objeto por tener una tabla de funciones virtuales?
    printf("c)\nTama�o de la clase Base con VTable: %zu y tama�o de la clase BaseNonVirtual sin VTable: %zu\n\n", sizeof(Base), sizeof(BaseNonVirtual));

    // d) �Qu� pasa si llamo a un m�todo virtual desde el constructor?
    class TestVirtualInConstructor : public Base
    {
    public:
        TestVirtualInConstructor() {
            virtualMethod();  // Llamada dentro del constructor
        }
        void virtualMethod() override {
            printf("d)\nTestVirtualInConstructor::virtualMethod\n\n");
        }
    };

    TestVirtualInConstructor t;

    // e) Comparar la llamada a una funci�n virtual con la llamada a una funci�n no virtual.
    printf("e)\nLlamada a funci�n no virtual:\n");
    basePtr->nonVirtualMethod();

    printf("\nLlamada a funci�n virtual:\n");
    basePtr->virtualMethod();
}
