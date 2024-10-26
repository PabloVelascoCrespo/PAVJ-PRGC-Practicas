#ifndef ISTORABLE_H
#define ISTORABLE_H

class IStorable
{
public:
    virtual ~IStorable() = default;

    virtual IStorable* Clone() const = 0;
};

#endif // ISTORABLE_H
