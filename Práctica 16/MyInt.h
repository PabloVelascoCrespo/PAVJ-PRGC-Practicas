#pragma once

#include "IStorable.h"
#include <iostream>
#include <string>

class MyInt : public IStorable {
private:
    int m_iValue;

public:
    MyInt(const int _iValue) 
        : m_iValue(_iValue) 
    {
    }

    // Implementación del método Clone
    MyInt* Clone() const override {
        return new MyInt(*this);
    }

    // Método para obtener el valor
    int GetValue() const {
        return m_iValue;
    }

    // Método para imprimir el valor
    void Print() const {
        std::cout << m_iValue << std::endl;
    }
};