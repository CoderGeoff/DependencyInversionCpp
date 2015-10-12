#include "stdafx.h"
#include "SnakesAndLaddersFactory.h"
#include "SnakesAndLadders.h"

using namespace WithoutDependencyInversion;

std::unique_ptr<ISnakesAndLadders> SnakesAndLaddersFactory::Create(std::vector<std::string> players)
{
    return std::make_unique<SnakesAndLadders>(players);
}