#pragma once

#include "IStorable.h"
#include <iostream>
#include <string>

class MyString : public IStorable 
{
private:
    std::string m_sValue;

public:
    MyString(const std::string& _sValue) 
        : m_sValue(_sValue)
    {
    }

    MyString* Clone() const override 
    {
        return new MyString(*this);
    }

    std::string GetValue() const 
    {
        return m_sValue;
    }

    void Print() const 
    {
        std::cout << m_sValue << std::endl;
    }
};