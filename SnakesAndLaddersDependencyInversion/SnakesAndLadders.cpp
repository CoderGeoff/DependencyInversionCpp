#include "SnakesAndLadders.h"
#include <algorithm>
#include <thread>
#include <iostream>
#include "IDie.h"
#include "IBoard.h"
#include "Move.h"
#include "MoveOutcome.h"
#include <map>

using namespace DependencyInversion;

SnakesAndLadders::SnakesAndLadders(std::shared_ptr<IBoard> board, std::shared_ptr<IDie> die, std::vector<std::string>& players)
    : m_Board(board), 
    m_Die(die),
    m_Move(board)
{
    std::transform(players.begin(), players.end(), back_inserter(m_Players), [](const std::string& name){ return Player(name);});
}

void SnakesAndLadders::Play()
{
    std::cout << "Let's start" << std::endl;

    for (int playerIndex = 0;
        m_Players[playerIndex].Square() != m_Board->LastSquare();
        playerIndex = ++playerIndex % m_Players.size())
    {
        Player& player = m_Players[playerIndex];
        std::cout << std::endl << "Ok, " << player.Name() << " to go next. Press any key to continue." << std::endl;
        getc(stdin);

        int thrown = m_Die->Throw();
        std::cout << player.Name() << " has thrown a " << thrown << std::endl;
        PrintMoving(thrown);

        MoveOutcome outcome= m_Move.Execute(player.Square(), thrown);
        PrintMove(outcome);
        player.Square(outcome.SquareAtEndOfMove());
    } 

    std::cout << "You've won! << " << std::endl;
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

void SnakesAndLadders::PrintMove(const MoveOutcome& outcome)
{
    if (outcome.Overshot())
    {
        std::cout << "Bad luck - you over shot the end!" << std::endl;
    }
    std::cout << "You're now on " << outcome.SquareAtEndOfDiceCount() << std::endl;

    if (outcome.HitSnake())
    {
        std:: cout << "Oh no, you've landed on a snake. Down you go!" << std::endl;
        std::cout << "You're now on " << outcome.SquareAtEndOfMove() << std::endl;
    }
}