#include "stdafx.h"
#include <memory>

#include <gtest/gtest.h>
#include "Board.h"
#include "Move.h"
#include "MoveOutcome.h"

using namespace WithoutDependencyInversion;

TEST(MoveTests, GivenAPlayerOnSquare97_WhenTheyMove3_TheyShouldEndUpOnSquare98)
{
    auto board = std::make_shared<Board>(10);
    Move move(board.get());

    // TODO complete the test
}
