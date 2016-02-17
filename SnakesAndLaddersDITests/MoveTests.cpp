#include "stdafx.h"
#include <Move.h>
#include <MoveOutcome.h>
#include <IBoard.h>

#include <gtest/gtest.h>

using namespace DependencyInversion;

class BoardWith100SquaresAndNoSnakes : public IBoard
{
    int m_LastSquare;
public:
    bool TryGetSnakeWithHeadAt(int square, std::pair<int, int>* snake) const override
    {
        return false;
    }
    virtual int LastSquare() const override { return 99; }
};

TEST(MoveTests, GivenAPlayerOnSquare97_WhenTheyMove3_TheyShouldEndUpOnSquare98)
{
    // Given
    auto board = std::make_shared<BoardWith100SquaresAndNoSnakes>();
    auto iboard = std::static_pointer_cast<IBoard>(board);

    // TODO complete the test
}