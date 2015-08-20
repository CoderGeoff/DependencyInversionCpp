#include "SnakesAndLadders.h"
#include <algorithm>
#include <thread>
#include "Die.h"
#include "Board.h"
#include <iostream>

SnakesAndLadders::SnakesAndLadders(std::vector<std::string> players)
    : m_Board(10),
    m_CurrentPlayerIndex(0)
{
    std::transform(players.begin(), players.end(), back_inserter(m_Players), [](const std::string& name){ return Player(name);});
}

void SnakesAndLadders::Play()
{
    time_t randomSeed;
    srand(static_cast<unsigned>(time(&randomSeed)));

    std::cout << "Let's start" << std::endl;
    while (TakeNextTurn())
    {
        m_CurrentPlayerIndex = ++m_CurrentPlayerIndex % m_Players.size();
    } 
}

bool SnakesAndLadders::TakeNextTurn()
{
    Player& player = m_Players[m_CurrentPlayerIndex];
    std::cout << std::endl << "Ok, " << player.Name() << " to go next. Press any key to continue." << std::endl;
    getc(stdin);

    // throw the die
    int thrown = Die::Throw();
    std::cout << player.Name() << " has thrown a " << thrown << std::endl;
    PrintMoving(thrown);

    // move the number of square shown on the die
    int newPosition = player.Square() + thrown;
    if (newPosition > m_Board.LastSquare())
    {
        // if we've overshot the last square, we have to go back
        int numberOfSpacesToGoBack = m_Board.LastSquare() - newPosition;
        newPosition = m_Board.LastSquare() - numberOfSpacesToGoBack;
        std::cout << "Bad luck - you over shot the end!" << std::endl;
    }
    std::cout << "You're now on " << newPosition << std::endl;

    // check to see if we're at the head of a snake
    std::pair<int, int> snake;
    if (m_Board.TryGetSnakeWithHeadAt(newPosition, &snake))
    {
        std::cout << "Oh no, you've landed on a snake. Down you go!" << std::endl;
        newPosition = snake.second;
        std::cout << "You're now on " << newPosition << std::endl;
    }
    player.Square(newPosition);

    // see if the player has won
    if (newPosition == m_Board.LastSquare())
    {
        std::cout << "You've won! << " << std::endl;
        return false;
    }

    return true;
}

void SnakesAndLadders::PrintMoving(int count)
{
    static std::map<int, std::string> Numbers =
    {
        { 1, "one" },
        { 2, "two" },
        { 3, "three" },
        { 4, "four" },
        { 5, "five" },
        { 6, "six" },
    };

    std::cout << "Moving... ";
    for (int i = 1; i <= count; ++i)
    {
        std::cout << Numbers[i] << "... ";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    std::cout << std::endl;
}
