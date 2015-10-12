#include "MoveOutcomeBuilder.h"
#include "MoveOutcome.h"

using namespace DependencyInversion;

MoveOutcomeBuilder::MoveOutcomeBuilder(int square)
    : m_SquareAtEndOfDiceCount(square),
    m_SquareAtEndOfMove(square),
    m_Overshot(false)
{
}

void MoveOutcomeBuilder::OvershotTo(int square)
{
    m_SquareAtEndOfDiceCount = square;
    m_SquareAtEndOfMove = square;
    m_Overshot = true;
}

void MoveOutcomeBuilder::WentDownSnakeTo(int square)
{
    m_SquareAtEndOfMove = square;
}

MoveOutcome MoveOutcomeBuilder::Build() const
{
    return MoveOutcome(m_SquareAtEndOfDiceCount, m_SquareAtEndOfMove, m_Overshot);
}
