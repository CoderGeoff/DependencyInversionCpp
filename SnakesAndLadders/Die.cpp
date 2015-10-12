#include "stdafx.h"
#include "Die.h"
#include <random>

using namespace WithoutDependencyInversion;

int Die::Throw()
{
    return (rand() % 6) + 1;
}
