#include <iostream>

enum EColor
{
	Rojo,
	Verde,
	Azul
};

int main()
{
#define CASE_VALUE(_COLOR) \
	case _COLOR: \
		printf(#_COLOR);\
		break;

	EColor eColor = Rojo;

	switch (eColor)
	{
	CASE_VALUE(Rojo)
	CASE_VALUE(Verde)
	CASE_VALUE(Azul)
	default:
		break;
	}
}