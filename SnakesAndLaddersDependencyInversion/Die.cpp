#include "stdafx.h"
#include "Die.h"
#include <random>

int Die::Throw()
{
    return (rand() % 6) + 1;
}