#include "stdafx.h"
#include "SnakesAndLaddersFactory.h"
#include "SnakesAndLadders.h"
#include "Board.h"
#include "Die.h"

std::unique_ptr<ISnakesAndLadders> SnakesAndLaddersFactory::Create(std::vector<std::string> players)
{
    auto board = std::make_shared<Board>(10);
    auto die = std::make_shared<Die>();
    return std::make_unique<SnakesAndLadders>(board, die, players);
}