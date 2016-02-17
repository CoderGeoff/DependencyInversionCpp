# DependencyInversionPrincipleCpp
An exercise to underline the Dependency Inversion Principle, using C++ and Visual Studio.
Based on Visual Studio 2013.

This exercise is based on the popular board game of snakes and ladders, which you can read up about here <https://en.wikipedia.org/wiki/Snakes_and_Ladders>, although, to keep things more simple, this version has only 
snakes and no ladders. You should make sure you're familiar with the rules. Here's a clear, succinct version: <http://www.ehow.com/facts_5163203_snakes-amp-ladders-rules.html>.

## Getting started

1. Clone the repository, check the master branch (this happens by default) 
2. Open Visual Studio
3. Open the solution file, DependencyInversionPrinciple.sln, in the root directory of the repository
4. Build the project in Debug
5. Run the tests, Debug/SnakesAndLaddersTests.exe 
6. Have a look at the code in SnakesAndLadders and SnakesAndLaddersTests, as indicated below:

# Code that doesn't adhere to the Dependency Inversion Principle

In ConsoleBasedGame, there's an version of the game you and run on a console and play. It has a simple implementation of `main()` in ConsoleBasedGame.cpp.

In SnakesAndLadders, there's an implementation of the game that doesn't adhere to the DependencyInversionPrinciple. It has the following classes:

| Class | Description |
|-------|-------------|
| Board | A board, with 100 squares and snakes added randomly |
| Die | A  die that gives random numbers from 1 to 6 |
| Player | Represents a player on the board |
| SnakesAndLadders | The game itself. It has one method, play, that interacts with the console as you play the game |
| Move | Has the responsibility for moving a player a given number of players forward on the board. It takes care of landing on snakes and overshooting the end of the board |
| MoveOutcome | A class the describes what happened to the player during the move |
| MoveOutcomeBuilder | A utility class used during to player's move to build MoveOutcome objects |
| SnakesAndLadders | The game itself. It has two methods, Play and IsFinished |

There are no tests for SnakesAndLadders, but there is a project,  SnakesAndLaddersTests, which is already set up for writing acceptance tests on the game. 
Currently, the only way to test the implementation is to run Debug\ConsoleBasedGame.exe manually.

## Task 1
Your task is to write a test to prove that, given a move that overshoots the end of the board by one, the player ends up on the square before the last one. SnakesAndLaddersTests\MoveTests.cpp, you'll find a test case declaration that just needs filling in.

```
TEST(MoveTests, GivenAPlayerOnSquare97_WhenTheyMove3_TheyShouldEndUpOnSquare98)
{
}
```

## Task 2
Now write a test to prove that, given a move that lands a player on snake, that they end up at the bottom of the snake.

```
TEST(MoveTests, GivenASnakeFromSquare2To1_WhenAPlayerMovesOnToSquare2_TheyShouldEndUpOnSquare1)
{
}
```

# Task 3

The next task is to write a test to prove that the game ends when a player reaches the last square on the board. Note that you are now testing SnakesAndLadders, and so you need a new test suite. The test case should look something like this;

```
TEST(SnakesAndLaddersTests, WhenAPlayerLandsOnTheLastSquare_TheGameShouldEnd)
{
}
```

# Task 4
 
Your last task is to prove that when a player throws the die, they move the number of squares shown. 
You test could be something like this. 

```
TEST(SnakesAndLaddersTests, GivenAPlayersThrowMissesAnySnakesAndDoesntReachTheEndOfTheBoard_WhenAPlayerMoves_TheyShouldMoveForwardTheNumberOfSquaresThrown)
{
}
```

# Code that adheres a bit more to the Dependency Inversion Principle

Now check the branch 'DependencyInversion', where is a version of the game that adheres more to the Dependency Inversion principle.

| Class | Description |
|-------|-------------|
| IBoard | An abstract interface to the board |
| Board | An actual board, with 100 squares and snakes added randomly |
| IDie | An abstract represntation of the die |
| Die | A concrete die that gives random numbers from 1 to 6 |
| Player | Represents a player on the board |
| SnakesAndLadders | The game itself. It has one method, play, that interacts with the console as you play the game |
| Move | Has the responsibility for moving a player a given number of players forward on the board. It takes care of landing on snakes and overshooting the end of the board |
| MoveOutcome | A class the describes what happened to the player during the move |
| MoveOutcomeBuilder | A utility class used during to player's move to build MoveOutcome objects |
| SnakesAndLadders | The game itself. It has one method, play, that interacts with the console as you play the game |

Try tasks 1 - 4 again, starting with this code.
