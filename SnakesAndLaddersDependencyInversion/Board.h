#pragma once
#include <map>
#include "IBoard.h"

namespace DependencyInversion {
class Board : public IBoard
{
public:
    explicit Board(int sizeOfOneSide);
    bool TryGetSnakeWithHeadAt(int square, std::pair<int, int>* snake) const override;
    int LastSquare() const override;
private:
    static std::pair<int, int> CreateSnake(int lowestSquareForSnakeHead, int highestSquareForSnakeHead);
    static std::map<int, int> MakeSnakes(int sizeOfOneSide);
    int m_LastSquare;
    std::map <int, int> m_Snakes;
};
}
