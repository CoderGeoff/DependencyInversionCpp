#pragma once
#include <string>
#include <vector>
#include "Player.h"
#include "Board.h"
#include "ISnakesAndLadders.h"
#include "Move.h"

namespace WithoutDependencyInversion {
class SnakesAndLadders : public ISnakesAndLadders
{
    Board m_Board;
    Move m_Move;
    std::vector<Player> m_Players;
    int m_CurrentPlayerIndex;
public:
    explicit SnakesAndLadders(std::vector<std::string>& players);
    void Play() override;
    bool IsFinished() const override;
private:
    bool IsFirstMove() const;
    void PrintMove(const MoveOutcome& moveOutcome, int a);
    void PrintMoving(int count);
};
}
