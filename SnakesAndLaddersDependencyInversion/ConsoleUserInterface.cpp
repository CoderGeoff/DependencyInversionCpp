#include "ConsoleUserInterface.h"
#include <iostream>
#include <map>
#include <thread>

void ConsoleUserInterface::AnnounceStart()
{
    std::cout << "Let's start" << std::endl;
}

void ConsoleUserInterface::AnnounceNextPlayer(const std::string& string)
{
    std::cout << std::endl << "Ok, " << string << " to go next. Press any key to continue." << std::endl;
    getc(stdin);
}

void ConsoleUserInterface::AnnounceRollOfTheDie(const std::string& name, int roll)
{
    std::cout << name << " has thrown a " << roll << std::endl;
    PrintMoving(roll);
}

void ConsoleUserInterface::AnnounceOvershoot(const std::string& name)
{
    std::cout << "Bad luck - you over shot the end!" << std::endl;
}

void ConsoleUserInterface::AnnounceNewPosition(const std::string& name, int newPosition)
{
    std::cout << "You're now on " << newPosition << std::endl;
}

void ConsoleUserInterface::AnnounceLandedOnSnake(const std::string& name)
{
    std::cout << "Oh no, you've landed on a snake. Down you go!" << std::endl;
}

void ConsoleUserInterface::AnnounceWonGame(const std::string& name)
{
    std::cout << "You've won! << " << std::endl;
}

void ConsoleUserInterface::PrintMoving(int count)
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
