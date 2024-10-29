#pragma once

class IStorable
{
public:
    virtual ~IStorable() = default;

    virtual IStorable* Clone() const = 0;

};