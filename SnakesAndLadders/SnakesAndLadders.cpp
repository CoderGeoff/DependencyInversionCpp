#include "SnakesAndLadders.h"
#include <algorithm>
#include <thread>
#include <iostream>
#include "Die.h"
#include "MoveOutcome.h"
#include "Board.h"

using namespace WithoutDependencyInversion;

static const int NotStarted = -1;

SnakesAndLadders::SnakesAndLadders(std::vector<std::string>& players)
    : m_Board(10),
    m_Move(&m_Board),
    m_CurrentPlayerIndex(NotStarted)
{
    std::transform(players.begin(), players.end(), back_inserter(m_Players), [](const std::string& name){ return Player(name);});
}

void SnakesAndLadders::Play()
{
    if (IsFirstMove())
    {
        std::cout << "Let's start" << std::endl;
        m_CurrentPlayerIndex = 0;
    }

    Player& player = m_Players[m_CurrentPlayerIndex];
    std::cout << std::endl << "Ok, " << player.Name() << " to go next. Press any key to continue." << std::endl;
    getc(stdin);

    int thrown = Die::Throw();
    std::cout << player.Name() << " has thrown a " << thrown << std::endl;
    PrintMoving(thrown);

    MoveOutcome outcome = m_Move.Execute(player.Square(), thrown);
    PrintMove(outcome, 1);
    player.Square(outcome.SquareAtEndOfMove());

    m_CurrentPlayerIndex = ++m_CurrentPlayerIndex % m_Players.size();
}

bool SnakesAndLadders::IsFinished() const
{
    return std::any_of(m_Players.begin(), m_Players.end(), [this](const Player& player){ return player.Square() == m_Board.LastSquare(); });
}

bool SnakesAndLadders::IsFirstMove() const
{
    return m_CurrentPlayerIndex == NotStarted;
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

void SnakesAndLadders::PrintMove(const MoveOutcome& outcome, int a)
{
    if (outcome.Overshot())
    {
        std::cout << "Bad luck - you over shot the end!" << std::endl;
    }
    std::cout << "You're now on " << outcome.SquareAtEndOfDiceCount() << std::endl;

    if (outcome.HitSnake())
    {
        std::cout << "Oh no, you've landed on a snake. Down you go!" << std::endl;
        std::cout << "You're now on " << outcome.SquareAtEndOfMove() << std::endl;
    }
}
