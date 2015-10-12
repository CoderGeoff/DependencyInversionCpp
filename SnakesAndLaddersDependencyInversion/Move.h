#pragma once
#include <memory>
#include "IBoard.h"

namespace DependencyInversion {
class MoveOutcome;

class Move
{
    std::shared_ptr<IBoard> m_Board;
public:
    explicit Move(const std::shared_ptr<IBoard>& board);
    MoveOutcome Execute(int startSquare, int squaresToMove);
};
}
