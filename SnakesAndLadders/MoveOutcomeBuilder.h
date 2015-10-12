#pragma once
class MoveOutcome;

class MoveOutcomeBuilder
{
    int m_SquareAtEndOfDiceCount;
    int m_SquareAtEndOfMove;
    bool m_Overshot;
public:
    explicit MoveOutcomeBuilder(int square);
    void OvershotTo(int square);
    void WentDownSnakeTo(int square);
    MoveOutcome Build() const;
};

