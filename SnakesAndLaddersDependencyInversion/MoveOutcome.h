#pragma once
#include <utility>
#include <memory>

class MoveOutcome
{
private:
    int m_SquareAtEndOfDiceCount;
    int m_SquareAtEndOfMove;
    bool m_Overshot;
public:
    explicit MoveOutcome(int squareAtEndOfDiceCount, int squareAtEndOfMove, bool overshot);
    bool HitSnake() const;
    bool Overshot() const;
    int SquareAtEndOfDiceCount() const;
    int SquareAtEndOfMove() const;
};

