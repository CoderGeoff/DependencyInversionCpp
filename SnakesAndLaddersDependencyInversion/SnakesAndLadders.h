#pragma once
#include "ISnakesAndLadders.h"

#include <memory>
#include <string>
#include <vector>
#include "Move.h"
#include "Player.h"

namespace DependencyInversion {
class IDie;
class IBoard;
class MoveOutcome;

class SnakesAndLadders : public ISnakesAndLadders
{
    std::shared_ptr<IBoard> m_Board;
    std::shared_ptr<IDie> m_Die;
    Move m_Move;
    std::vector<Player> m_Players;
public:
    explicit SnakesAndLadders(std::shared_ptr<IBoard> board, std::shared_ptr<IDie> die, std::vector<std::string>& players);
    void Play() override;
private:
    void PrintMove(const MoveOutcome& moveOutcom);
    void PrintMoving(int count);
};
}
