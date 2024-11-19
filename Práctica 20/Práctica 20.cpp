#include <stdio.h>
#include "consola.h"
#include <cstdlib>
#include <list>

/*
PRÁCTICA 20:

Templates: cambiar la práctica 4 para que:
    a) Si en un momento dado el número de entidades es menor que 5 se genera
    aleatoriamente una entidad nueva
    b) Cambiar la entidad para que tenga una propiedad adicional que refleje la vida 
    de la entidad. La vida inicial de cada entidad será aleatoria
    c) Cada vez que dos entidades estén en la misma casilla cada una de ellas
    perderá una vida
    d) Si la vida de una entidad llega a cero, esta será destruida
    e) Utilizxar una std::list para almacenar las entidades vivas en el sistema, así como
    para recorrer las entidades a la hora de pintarlas y moverlas
*/

const unsigned int MAX_SCREEN_SIZE = 30;
const unsigned int MIN_SCREEN_SIZE = 0;
const unsigned int MIN_ENTITIES = 5;

// ***************************************************************************************
// ENTIDAD
// ***************************************************************************************
struct TEntity;
typedef void (*funcEntity)(TEntity*);

struct TEntity
{
    short m_ix;
    short m_iy;
    int m_life; // Vida de la entidad
    funcEntity m_funcs[2]; // Funciones de la entidad (dibujar y mover)

    TEntity(funcEntity drawFunc, funcEntity moveFunc, short x, short y, int life)
        : m_ix(x), m_iy(y), m_life(life)
    {
        m_funcs[0] = drawFunc; // Asignación de la función de dibujo
        m_funcs[1] = moveFunc; // Asignación de la función de movimiento
    }
};

void DrawA(TEntity* _pEntity) { gotoxy(_pEntity->m_ix, _pEntity->m_iy); printf("A"); }
void DrawB(TEntity* _pEntity) { gotoxy(_pEntity->m_ix, _pEntity->m_iy); printf("B"); }
void DrawC(TEntity* _pEntity) { gotoxy(_pEntity->m_ix, _pEntity->m_iy); printf("C"); }
void DrawD(TEntity* _pEntity) { gotoxy(_pEntity->m_ix, _pEntity->m_iy); printf("D"); }
void DrawE(TEntity* _pEntity) { gotoxy(_pEntity->m_ix, _pEntity->m_iy); printf("E"); }

void MoveDown(TEntity* _pEntity)
{
    _pEntity->m_iy = (_pEntity->m_iy + 1) % (MAX_SCREEN_SIZE + 1);
}

void MoveDownLeft(TEntity* _pEntity)
{
    _pEntity->m_iy = (_pEntity->m_iy + 1) % (MAX_SCREEN_SIZE + 1);
    _pEntity->m_ix = (_pEntity->m_ix == MIN_SCREEN_SIZE) ? MAX_SCREEN_SIZE : _pEntity->m_ix - 1;
}

void MoveUpRight(TEntity* _pEntity)
{
    _pEntity->m_iy = (_pEntity->m_iy == MIN_SCREEN_SIZE) ? MAX_SCREEN_SIZE : _pEntity->m_iy - 1;
    _pEntity->m_ix = (_pEntity->m_ix + 1) % (MAX_SCREEN_SIZE + 1);
}

void MoveRandom(TEntity* _pEntity)
{
    _pEntity->m_ix = std::rand() % (MAX_SCREEN_SIZE + 1);
    _pEntity->m_iy = std::rand() % (MAX_SCREEN_SIZE + 1);
}

void MoveLeft(TEntity* _pEntity)
{
    _pEntity->m_ix = (_pEntity->m_ix == MIN_SCREEN_SIZE) ? MAX_SCREEN_SIZE : _pEntity->m_ix - 1;
}

// ***************************************************************************************
// FUNCIONES AUXILIARES
// ***************************************************************************************
void CheckCollisions(std::list<TEntity*>& entities)
{
    for (auto it1 = entities.begin(); it1 != entities.end();)
    {
        auto it2 = it1;
        bool removed = false;
        ++it2;
        while (it2 != entities.end())
        {
            if ((*it1)->m_ix == (*it2)->m_ix && (*it1)->m_iy == (*it2)->m_iy)
            {
                (*it1)->m_life--;
                (*it2)->m_life--;
                if ((*it2)->m_life <= 0)
                {
                    delete* it2;
                    it2 = entities.erase(it2);
                }
                else
                {
                    ++it2;
                }
                removed = true;
            }
            else
            {
                ++it2;
            }
        }
        if (removed && (*it1)->m_life <= 0)
        {
            delete* it1;
            it1 = entities.erase(it1);
        }
        else
        {
            ++it1;
        }
    }
}

void GenerateRandomEntity(std::list<TEntity*>& entities)
{
    funcEntity functions[5][2] = {
        {&DrawA, &MoveDown},
        {&DrawB, &MoveUpRight},
        {&DrawC, &MoveDownLeft},
        {&DrawD, &MoveRandom},
        {&DrawE, &MoveLeft} };
    int randomIndex = std::rand() % 5;
    short randomX = std::rand() % (MAX_SCREEN_SIZE + 1);
    short randomY = std::rand() % (MAX_SCREEN_SIZE + 1);
    int randomLife = 1 + std::rand() % 10; // Vida entre 1 y 10
    entities.push_back(new TEntity(functions[randomIndex][0], functions[randomIndex][1], randomX, randomY, randomLife));
}

// ***************************************************************************************
// MAIN
// ***************************************************************************************
int main()
{
    bool bStop = false;
    std::list<TEntity*> entities;

    // Generar entidades iniciales
    for (unsigned int i = 0; i < MIN_ENTITIES; ++i)
    {
        GenerateRandomEntity(entities);
    }

    while (!bStop)
    {
        clear();

        // Dibujar y mover las entidades
        for (auto& entity : entities)
        {
            entity->m_funcs[0](entity); // Llamada a la función de dibujo
            entity->m_funcs[1](entity); // Llamada a la función de movimiento
        }

        // Comprobar colisiones y eliminar entidades sin vida
        CheckCollisions(entities);

        // Asegurarse de que hay al menos 5 entidades
        while (entities.size() < MIN_ENTITIES)
        {
            GenerateRandomEntity(entities);
        }

        hidecursor();
        bStop = (GetAsyncKeyState(VK_SPACE) & 0x01);
        Sleep(50);
    }

    // Limpiar memoria
    for (auto entity : entities)
    {
        delete entity;
    }

    return 0;
}
