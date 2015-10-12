#include "stdafx.h"
#include "Die.h"
#include <random>

using namespace DependencyInversion;

int Die::Throw() const
{
    return (rand() % 6) + 1;
}
