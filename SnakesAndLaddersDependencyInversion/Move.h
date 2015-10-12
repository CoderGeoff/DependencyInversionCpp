#pragma once
#include <memory>
#include "Board.h"

namespace DependencyInversion {
class MoveOutcome;

class Move
{
    std::shared_ptr<IBoard> m_Board;
public:
    Move(const std::shared_ptr<IBoard>& board);
    MoveOutcome Execute(int startSquare, int squaresToMove);
};
}
