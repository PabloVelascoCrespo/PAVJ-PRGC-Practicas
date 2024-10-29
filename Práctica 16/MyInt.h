#pragma once

#include "IStorable.h"
#include <iostream>
#include <string>

class MyInt : public IStorable
{
private:
    int m_iValue;

public:
    MyInt(const int _iValue) 
        : m_iValue(_iValue) 
    {
    }

    MyInt* Clone() const override
    {
        return new MyInt(*this);
    }

    int GetValue() const
    {
        return m_iValue;
    }

    void Print() const 
    {
        std::cout << m_iValue << std::endl;
    }
};