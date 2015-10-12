#pragma once
#include "Board.h"

class MoveOutcome;

class Move
{
    const Board* m_Board;
public:
    explicit Move(Board* board);
    MoveOutcome Execute(int startSquare, int squaresToMove);
};

