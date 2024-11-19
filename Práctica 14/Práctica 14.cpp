#include <iostream>
#include <cstddef>  // para usar offsetof

/*
PRÁCTICA 14

Responder a las siguientes preguntas y proporcionar código
documentado cuya ejecución demuestre lo que se está respondiendo:

	a) ¿Cuánto espacio ocupa toda la tabla de funciones virtuales?
        R: Depende del número de funciones virtuales en la clase y del tamaño de un puntero en el sistema, por ejemplo, si tenemos 5 funciones virtuales en un sistema de 64 bits, la vtable ocupará 5x8 = 40 bytes
	b) ¿Dónde está situada la tabla de funciones virtuales?
        R: El puntero a la tabla de funciones virtuales está en el principio de cada objeto que contiene funciones virtuales.
	c) ¿Cuánto espacio ocupa adicionalmente un objeto por tener una tabla de funciones virtuales?
        R: Un objeto con métodos virtuales ocupa adicionalmente el tamaño de un puntero en memoria, ya que necesita almacenar un puntero a la VTable, es decir 8 bytes en un sistema de 64 bits o 4 en un sistema de 32 bits.
	d) ¿Qué pasa si llamo a un método virtual desde el constructor?
        R: Solo se llama a la implementación en la clase base, ignorando cualquier sobrecarga en las clases derivadas. Esto sucede porque, durante la construcción del objeto, la VTable aún no está completamente configurada para la clase derivada.
	e) Comparar la llamada a una función virtual con la llamada a una función no virtual. ¿Cuántos pasos adicionales tienen qu erealizarse para llamar a una función cuando esta es virtual?
        R: La llamada a una función virtual tiene un paso adicional: acceder a la VTable para obtener la dirección de la función a ejecutar.
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
    // a) ¿Cuánto espacio ocupa toda la tabla de funciones virtuales?
    Derived d;
    Base* basePtr = &d;

    printf("a)\nTamaño de un puntero (aproximación de la VTable): %zu bytes\n\n", sizeof(void*));

    // b) ¿Dónde está situada la tabla de funciones virtuales?
    printf("b)\nDirección del objeto d: %p\n", basePtr);
    printf("Dirección del puntero a la VTable (primer miembro): %p\n\n", *(void***)(basePtr));

    // c) ¿Cuánto espacio ocupa adicionalmente un objeto por tener una tabla de funciones virtuales?
    printf("c)\nTamaño de la clase Base con VTable: %zu y tamaño de la clase BaseNonVirtual sin VTable: %zu\n\n", sizeof(Base), sizeof(BaseNonVirtual));

    // d) ¿Qué pasa si llamo a un método virtual desde el constructor?
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

    // e) Comparar la llamada a una función virtual con la llamada a una función no virtual.
    printf("e)\nLlamada a función no virtual:\n");
    basePtr->nonVirtualMethod();

    printf("\nLlamada a función virtual:\n");
    basePtr->virtualMethod();
}
