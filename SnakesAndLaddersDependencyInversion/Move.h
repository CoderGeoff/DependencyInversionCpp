#pragma once
#include <ostream>
#include "Board.h"

class Move
{
    Board m_Board;
    std::ostream* m_Out;
public:
    Move(const Board& board, std::ostream& out);
    int Execute(int startSquare, int squaresToMove);
};

