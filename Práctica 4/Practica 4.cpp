/*
PRÁCTICA 4

Objetivo: Crear un mundo en el ordenador donde
evolucionan entidades de diferentes tipos

Las entidades se caracterizan por:
	- Evolucionar en el tiempo (ejecutarse), pudiendo,
	como mínimo moverse (cambiar de posición).
	- Pintarse en la pantalla.

Habrá diferentes tipos de entidades. Cada entidad
puede evolucionar o pintarse de manera diferente a
las otras.
	- Como mínimo habrá 4 tipos distintos de
	entidades.
	- Algunas de las entidades se pintarán igual pero
	no evolucionarán igual.

En el mundo se crearán vairas entidades de cada
tipo.

Para la creación de entidades se debe de utilizar la
estructura “TEntity“ suministrada usando el
operador “new”.

Para contener las entidades del mundo se puede
utilizar una tabla.

Para provocar una pausa en la ejecución se puede
utilizar la función “Sleep(int num milisec);”
(declarada en “windows.h”)

Para pintar en la pantalla se puede utilizar “printf”

Para situar el cursor de pintado en una posición de
la pantalla, limpiarla pantalla o esconder el cursos
se pueden utilizar las funciones declaradas y
definidas en los ficheros “console.h” y “console.cpp”
respectivamente.

*/

#include <stdio.h>
#include "consola.h"
#include <cstdlib>

const unsigned int MAX_SCREEN_SIZE = 30;
const unsigned int MIN_SCREEN_SIZE = 0;

struct TEntity;
typedef void (*funcEntity)(TEntity *);


// ***************************************************************************************
// ENTIDAD
// ***************************************************************************************
struct TEntity
{
	short m_ix;
	short m_iy;
	funcEntity *m_funcs;
	TEntity(funcEntity *funcs, short x, short y)
	{
		m_ix = x;
		m_iy = y;
		m_funcs = funcs;
	}
};


void DrawA(TEntity* _pEntity)
{
	gotoxy(_pEntity->m_ix, _pEntity->m_iy);
	printf("A");
}

void DrawB(TEntity* _pEntity)
{
	gotoxy(_pEntity->m_ix, _pEntity->m_iy);
	printf("B");
}

void DrawC(TEntity* _pEntity)
{
	gotoxy(_pEntity->m_ix, _pEntity->m_iy);
	printf("C");
}

void DrawD(TEntity* _pEntity)
{
	gotoxy(_pEntity->m_ix, _pEntity->m_iy);
	printf("D");
}

void DrawE(TEntity* _pEntity)
{
	gotoxy(_pEntity->m_ix, _pEntity->m_iy);
	printf("E");
}

void MoveDown(TEntity* _pEntity)
{
	if (_pEntity->m_iy > MAX_SCREEN_SIZE)
	{
		_pEntity->m_iy = 0;
	}
	else 
	{
		_pEntity->m_iy++;

	}
}

void MoveDownLeft(TEntity* _pEntity)
{
	_pEntity->m_iy++;
	_pEntity->m_ix--;
	if (_pEntity->m_ix == MIN_SCREEN_SIZE)
	{
		_pEntity->m_ix = MAX_SCREEN_SIZE;
	}
	if (_pEntity->m_iy > MAX_SCREEN_SIZE)
	{
		_pEntity->m_iy = MIN_SCREEN_SIZE;
	}
}

void MoveUpRight(TEntity* _pEntity)
{
	_pEntity->m_ix++;
	_pEntity->m_iy--;
	if (_pEntity->m_iy == MIN_SCREEN_SIZE)
	{
		_pEntity->m_iy = MAX_SCREEN_SIZE;
	}
	if (_pEntity->m_ix > MAX_SCREEN_SIZE)
	{
		_pEntity->m_ix = MIN_SCREEN_SIZE;
	}
}

void MoveRandom(TEntity* _pEntity)
{
	_pEntity->m_ix = std::rand() % MAX_SCREEN_SIZE;
	_pEntity->m_iy = std::rand() % MAX_SCREEN_SIZE;
}

void MoveLeft(TEntity* _pEntity)
{
	if (_pEntity->m_ix == MIN_SCREEN_SIZE)
	{
		_pEntity->m_ix = MAX_SCREEN_SIZE;
	}
	else
	{
		_pEntity->m_ix--;

	}
}
// ***************************************************************************************
// MAIN
// ***************************************************************************************
int main()
{
	bool bStop = false;
	const unsigned int uMisEntidadesSize = 5;
	TEntity* aMisEntidades[uMisEntidadesSize];

	funcEntity tMisFunciones1[2];
	tMisFunciones1[0] = &DrawA;
	tMisFunciones1[1] = &MoveDown;
	aMisEntidades[0] = new TEntity(tMisFunciones1, 1, 1);

	funcEntity tMisFunciones2[2];
	tMisFunciones2[0] = &DrawB;
	tMisFunciones2[1] = &MoveUpRight;
	aMisEntidades[1] = new TEntity(tMisFunciones2, 1, 1);

	funcEntity tMisFunciones3[2];
	tMisFunciones3[0] = &DrawC;
	tMisFunciones3[1] = &MoveDownLeft;
	aMisEntidades[2] = new TEntity(tMisFunciones3, 1, 1);

	funcEntity tMisFunciones4[2];
	tMisFunciones4[0] = &DrawD;
	tMisFunciones4[1] = &MoveRandom;
	aMisEntidades[3] = new TEntity(tMisFunciones4, 1, 1);

	funcEntity tMisFunciones5[2];
	tMisFunciones5[0] = &DrawE;
	tMisFunciones5[1] = &MoveLeft;
	aMisEntidades[4] = new TEntity(tMisFunciones5, 1, 1);

	while (!bStop)
	{
		clear();

		for (unsigned int uIndex = 0; uIndex < uMisEntidadesSize; uIndex++)
		{
			((*aMisEntidades[uIndex]->m_funcs[0]))((aMisEntidades[uIndex]));
			((*aMisEntidades[uIndex]->m_funcs[1]))((aMisEntidades[uIndex]));
		}

		hidecursor();
		bStop = (GetAsyncKeyState(VK_SPACE) & 0x01);
		Sleep(50);
	}
	for (unsigned int uIndex = 0; uIndex < uMisEntidadesSize; uIndex++)
	{
		delete aMisEntidades[uIndex];
	}
}

