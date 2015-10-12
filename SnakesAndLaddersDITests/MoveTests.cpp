#include "stdafx.h"
#include <Move.h>
#include <MoveOutcome.h>
#include <IBoard.h>

#include <gtest/gtest.h>

using namespace DependencyInversion;

class BoardWithNoSnakes : public IBoard
{
    int m_LastSquare;
public:
    BoardWithNoSnakes(int numberOfSquares) : m_LastSquare(numberOfSquares - 1) {}

    bool TryGetSnakeWithHeadAt(int square, std::pair<int, int>* snake) const override
    {
        return false;
    }
    virtual int LastSquare() const override { return m_LastSquare; }
};

TEST(MoveTests, GivenAPlayerOnSquare97_WhenTheyMove3_TheyShouldEndUpOnSquare98)
{
    // Given
    auto board = std::make_shared<BoardWithNoSnakes>(100);
    auto iboard = std::static_pointer_cast<IBoard>(board);
    Move move(iboard);

    // When
    MoveOutcome outcome = move.Execute(97, 3);

    // Then
    ASSERT_EQ(98, outcome.SquareAtEndOfMove());
}