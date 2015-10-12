#pragma once
#include "IDie.h"

namespace DependencyInversion {
class Die : public IDie
{
public:
    int Throw() const override;
};
}
