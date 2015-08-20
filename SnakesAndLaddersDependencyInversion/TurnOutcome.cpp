#include "stdafx.h"
#include "TurnOutcome.h"


TurnOutcome::TurnOutcome(int numberOfSquaresMoved, int squareAtEndOfTurn)
    : m_NumberOfSquaresMoved(numberOfSquaresMoved),
    m_SquareAtEndOfTurn(squareAtEndOfTurn)
{
}

TurnOutcome::TurnOutcome(int numberOfSquaresMoved, std::pair<int, int> snake)
    : m_NumberOfSquaresMoved(numberOfSquaresMoved),
    m_SquareAtEndOfTurn(snake.second)
{
    m_Snake = std::make_unique<std::pair<int, int>>(snake.first, snake.second);
}

int TurnOutcome::NumberOfSquaresMoved() const
{
    return m_NumberOfSquaresMoved;
}

bool TurnOutcome::SnakeHit(std::pair<int, int>& snake) const
{
    snake = *m_Snake;
    return m_Snake != nullptr;
}

int TurnOutcome::SquareAtEndOfTurn() const
{
    return m_SquareAtEndOfTurn;
}