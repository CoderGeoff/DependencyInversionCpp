#pragma once
class IDie
{
public:
    virtual ~IDie() = 0 {};
    virtual int Throw() const = 0;
};

