#include "Move.h"
#include "MoveOutcomeBuilder.h"
#include "MoveOutcome.h"

Move::Move(const std::shared_ptr<IBoard>& board)
    : m_Board(board)
{}

MoveOutcome Move::Execute(int startSquare, int squaresToMove)
{
    // move the number of square shown on the die
    int newPosition = startSquare + squaresToMove;
    MoveOutcomeBuilder outcomeBuilder(newPosition);

    if (newPosition > m_Board->LastSquare())
    {
        // if we've overshot the last square, we have to go back
        int numberOfSpacesToGoBack = m_Board->LastSquare() - newPosition;
        newPosition = m_Board->LastSquare() - numberOfSpacesToGoBack;
        outcomeBuilder.OvershotTo(newPosition);
    }

    // check to see if we're at the head of a snake
    std::pair<int, int> snake;
    if (m_Board->TryGetSnakeWithHeadAt(newPosition, &snake))
    {
        outcomeBuilder.WentDownSnakeTo(snake.second);
        newPosition = snake.second;
    }

    return outcomeBuilder.Build();
}