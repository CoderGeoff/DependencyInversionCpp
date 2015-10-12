#include "stdafx.h"
#include "Board.h"
#include <ctime>

using namespace WithoutDependencyInversion;

Board::Board(int sizeOfOneSide)
: m_LastSquare((sizeOfOneSide * sizeOfOneSide) - 1),
m_Snakes(MakeSnakes(sizeOfOneSide))
{
}

bool Board::TryGetSnakeWithHeadAt(int square, std::pair<int, int>* snake) const
{
    auto iter = m_Snakes.find(square);
    if (iter == m_Snakes.end())
    {
        return false;
    }
    *snake = *iter;
    return true;
}

int Board::LastSquare() const
{
    return m_LastSquare;
}

std::pair<int, int> Board::CreateSnake(int lowestSquareForSnakeHead, int highestSquareForSnakeHead)
{
    int range = highestSquareForSnakeHead - lowestSquareForSnakeHead;
    int head = rand() % range + lowestSquareForSnakeHead + 1;
    int tail = rand() % (head - 1) + 1;
    return std::make_pair(head, tail);
}

std::map<int, int> Board::MakeSnakes(int sizeOfOneSide)
{
    time_t randomSeed;
    srand(static_cast<unsigned>(time(&randomSeed)));

    std::map<int, int> snakes;
    int numberOfSnakes = sizeOfOneSide;
    int lowestSquareForSnakeHead = sizeOfOneSide;
    int highestSquareForSnakeHead = sizeOfOneSide * sizeOfOneSide - 1;
    for (int i = 0; i < numberOfSnakes; ++i)
    {
        auto snake = CreateSnake(lowestSquareForSnakeHead, highestSquareForSnakeHead);
        snakes.insert(snake);
    }
    return snakes;
}

