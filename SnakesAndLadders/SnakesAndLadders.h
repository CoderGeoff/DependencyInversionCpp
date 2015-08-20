#pragma once
#include <string>
#include <vector>
#include "Player.h"
#include "Board.h"
#include "ISnakesAndLadders.h"

class SnakesAndLadders : public ISnakesAndLadders
{
    Board m_Board;
    std::vector<Player> m_Players;
    int m_CurrentPlayerIndex;
public:
    explicit SnakesAndLadders(std::vector<std::string>& players);
    void Play() override;
private:
    bool TakeNextTurn();
    void PrintMoving(int count);
};

