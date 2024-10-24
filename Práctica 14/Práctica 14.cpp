#include <iostream>

class CComponente1
{
public:
    CComponente1(int j)
        : m_j(j)
    {
        printf("Constructor CComponente1");
    }
    int m_j;
};

class CComponente2
{
public:
    CComponente2(int k)
        : m_k(k)
    {
        printf("Constructor CComponente2");
    }
    int m_k;
};

class CEntity
{
public:
    CEntity()
        : m_oComponente1(8)
        , m_oComponente2(67)
    {
        printf("Constructor CEntity");
    }
    CComponente1 m_oComponente1;
    CComponente1 m_oComponente2;
};

int main()
{
    std::cout << "Hello World!\n";
}