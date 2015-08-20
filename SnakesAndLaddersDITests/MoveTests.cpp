#include "stdafx.h"
#include <Move.h>
#include <MoveOutcome.h>
#include <IBoard.h>

#include <gtest/gtest.h>

class BoardWith10SquaresAndNoSnakes : public IBoard
{
    bool TryGetSnakeWithHeadAt(int square, std::pair<int, int>* snake) const override
    {
        return false;
    }
    virtual int LastSquare() const override { return 10; }
};

TEST(MoveTests, GivenIAmOnSquare2_WhenIMove1Square_IShouldBeOnSquare3)
{

}