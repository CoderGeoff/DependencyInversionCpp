#include "stdafx.h"
#include "Die.h"
#include <random>

int Die::Throw() const
{
    return (rand() % 6) + 1;
}
