#pragma once
#include <ostream>
#include "Board.h"

class MoveOutcome;

class Move
{
    Board m_Board;
public:
    Move(const Board& board);
    MoveOutcome Execute(int startSquare, int squaresToMove);
};

