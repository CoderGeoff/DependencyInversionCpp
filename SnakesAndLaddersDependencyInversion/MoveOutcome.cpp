#include "stdafx.h"
#include "MoveOutcome.h"

using namespace DependencyInversion;

MoveOutcome::MoveOutcome(int squareAtEndOfDiceCount, int squareAtEndOfMove, bool overshot)
    : m_SquareAtEndOfDiceCount(squareAtEndOfDiceCount),
    m_SquareAtEndOfMove(squareAtEndOfMove),
    m_Overshot(overshot)
{
}

bool MoveOutcome::HitSnake() const
{
    return m_SquareAtEndOfDiceCount != m_SquareAtEndOfMove;
}

int MoveOutcome::SquareAtEndOfMove() const
{
    return m_SquareAtEndOfMove;
}

int MoveOutcome::SquareAtEndOfDiceCount() const
{
    return m_SquareAtEndOfDiceCount;
}

bool MoveOutcome::Overshot() const
{
    return m_Overshot;
}