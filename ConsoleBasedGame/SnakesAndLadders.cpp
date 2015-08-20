// SnakesAndLadders.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "SnakesAndLadders.h"
#include "SnakesAndLaddersFactory.h"

int _tmain(int argc, _TCHAR* argv[])
{
    std::cout << "Welcome to Snakes and Ladders" << std::endl;
    std::cout << "Who's playing (type end to start the game)?" << std::endl;
    int index = 1;
    std::vector<std::string> players;
    do
    {
        std::string name;
        std::cout << "Player" << index++ << ": ";
        std::cin >> name;
        if (name == "end") break;
        players.push_back(name);
    } while (true);

    std::unique_ptr<ISnakesAndLadders> game = SnakesAndLaddersFactory::Create(players);
    game->Play();
}

