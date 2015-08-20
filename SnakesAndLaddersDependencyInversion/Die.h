#pragma once
#include "IDie.h"

class Die : public IDie
{
public:
    int Throw() const;
};

