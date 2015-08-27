# DependencyInversionPrincipleCpp
An exercise to underline the Dependency Inversion Principle, using C++ and Visual Studio.
Based on Visual Studio 2013.

This exercise is based on the popular board game of snakes and ladders, which you can read up about here <https://en.wikipedia.org/wiki/Snakes_and_Ladders>, although, to keep things more simple, this version has only 
snakes and no ladders. You should make sure you're familiar with the rules. Here's a clear, succinct version: <http://www.ehow.com/facts_5163203_snakes-amp-ladders-rules.html>.

## Getting started

1. Clone the repository 
2. Open Visual Studio
3. Open the solution file, DependencyInversionPrinciple.sln, in the root directory of the repository
4. Build the project in Debug
5. Run the tests, Debug/SnakesAndLaddersTests.exe and Debug/SnakesAndLaddersDITests.exe
6. Have a look at the code in SnakesAndLadders and SnakesAndLaddersTests, as indicated below:

# Code that doesn't adhere to the Dependency Inversion Principle

In ConsoleBasedGame, there's an version of the game you and run on a console and play. It has a simple implementation of `main()` in ConsoleBasedGame.cpp.

In SnakesAndLadders, there's an implementation of the game that doesn't adhere to the DependencyInversionPrinciple. It has the following classes:

| Class | Description |
|-------|-------------|
| Board | Represents the board of 100 squares, with snakes added randomly |
| Die | The single die; can be thrown to get a random number from 1 to 6 |
| Player | Represents a player on the board |
| ISnakesAndLadders | An interface to the game. It is used by ConsoleBasedGame |
| SnakesAndLaddersFactory | A class that creates a new game of Snakes and Ladders. Again, it's used by ConsoleBasedGame |
| SnakesAndLadders | The game itself. It has one method, play, that interacts with the console as you play the game |

There are no tests for SnakesAndLadders, but there is a project,  SnakesAndLaddersTests, which is already set up for writing acceptance tests on the game. 
Currently, the only way to test the implementation is to run Debug\ConsoleBasedGame.exe manually.

## Task 1
Your task is to write a test to prove that, given a player on the first square on the board (numbered 1), when they take a move, they move forward the number of squares on the dice. 
If you look in  SnakesAndLaddersTests\AcceptanceTests.cpp, you'll find test case declaration that just needs filling in.

```
TEST(AcceptanceTests, GivenAPlayerOnSquare1_WhenTheyTakeATurn_TheyShouldMoveForwardTheNumberShownOnTheDie)
{
}
```

This is not straightforward task, but it is possible! You will have to change the Snakes And Ladders code to achieve it. If you want, you can  run the game to see whether it's still working; just run ConsoleBasedGame.exe.

You have 15 minutes.

# Task 2
If you succeeded at the first task your next is to write a test case to prove that the games ends when a player reaches the last square on the board.

Your task is to write a test to prove the game ends when a player reaches the last square on the board. The test case should look something like this;

```
TEST(AcceptanceTests, GivenABoad_WhenAPlayerLandsOnTheLastSquare_TheGameShouldEndWithNoMoreDiceThrows)
{
}
```
 
 or something to this effect. 
 
You have 15 minutes.

# Code that adheres a bit more to the Dependency Inversion Principle

Now look in 

In SnakesAndLaddersDependencyInversion:

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

The tests for SnakesAndLaddersDependencyInversion are in SnakesAndLaddersDITests, but as with the SnakesAndLadders, there are no tests as yet.

| Class | Description |
|-------|-------------|
| AcceptanceTest | Used for testing the overall game |
| MoveTests | Used for testing individual moves |
| BoardWith10SquaresAndNoSnakes | This is a board with just 10 squares and no snkaes that can be used in test scenarios |

## Task 3

Your task is to write a test to prove that, given a player on the second square on the board (numbered 2), when they  move 1, they end up on square 3. 
If you look in  SnakesAndLaddersDITests\MoveTests.cpp, you'll find test case declaration that just needs filling in.

```
TEST(MoveTests, GivenIAmOnSquare2_WhenIMove1Square_IShouldBeOnSquare3)
{
}
```

You will find it useful to use BoardWith10SquaresAndNoSnakes.

15 minutes.

## Task 4

Your second task is to write a test to  prove that when a player moves to the last square on the board, the game ends with out any further dice throws. 
If you look in  SnakesAndLaddersDITests\AcceptanceTests.cpp, you'll find test case declaration that just needs filling in.

```
TEST(AcceptanceTests, GivenBoardWith10Squares_WhenIThrowA10_TheGameShouldEndWithASingleThrow)
{
}
```

To complete this, you will need to write a test die, like the test board you used in the Task 3.

15 minutes.

