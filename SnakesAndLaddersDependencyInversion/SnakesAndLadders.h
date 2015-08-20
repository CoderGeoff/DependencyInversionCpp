#pragma once
#include <ostream>
#include <string>
#include <vector>
#include "Player.h"
#include "Move.h"
#include "ISnakesAndLadders.h"

class SnakesAndLadders : public ISnakesAndLadders
{
    Board m_Board;
    Move m_Move;
    std::vector<Player> m_Players;
public:
    explicit SnakesAndLadders(std::vector<std::string>& players);
    void Play() override;
private:
    int MovePlayer(int startSquare, int squaresToMove, std::ostream& out);
    void PrintMoving(int count);
};

