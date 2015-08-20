#pragma once
#include <memory>
#include <string>
#include <vector>
#include "Board.h"
#include "Move.h"
#include "Player.h"
#include "ISnakesAndLadders.h"

class MoveOutcome;

class SnakesAndLadders : public ISnakesAndLadders
{
    std::shared_ptr<Board> m_Board;
    Move m_Move;
    std::vector<Player> m_Players;
public:
    explicit SnakesAndLadders(std::vector<std::string>& players);
    void Play() override;
private:
    void PrintMove(const MoveOutcome& moveOutcom);
    void PrintMoving(int count);
};

