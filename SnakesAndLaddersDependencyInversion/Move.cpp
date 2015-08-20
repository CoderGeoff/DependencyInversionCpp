#include "Move.h"

Move::Move(const Board& board, std::ostream& out)
    : m_Board(board),
    m_Out(&out)
{}

int Move::Execute(int startSquare, int squaresToMove)
{
    // move the number of square shown on the die
    int newPosition = startSquare + squaresToMove;
    if (newPosition > m_Board.LastSquare())
    {
        // if we've overshot the last square, we have to go back
        int numberOfSpacesToGoBack = m_Board.LastSquare() - newPosition;
        newPosition = m_Board.LastSquare() - numberOfSpacesToGoBack;
        *m_Out << "Bad luck - you over shot the end!" << std::endl;
    }
    *m_Out << "You're now on " << newPosition << std::endl;

    // check to see if we're at the head of a snake
    std::pair<int, int> snake;
    if (m_Board.TryGetSnakeWithHeadAt(newPosition, &snake))
    {
        *m_Out << "Oh no, you've landed on a snake. Down you go!" << std::endl;
        newPosition = snake.second;
        *m_Out << "You're now on " << newPosition << std::endl;
    }

    return newPosition;
}