#pragma once
#include <map>

namespace WithoutDependencyInversion {
class Board
{
public:
    explicit Board(int sizeOfOneSide);
    bool TryGetSnakeWithHeadAt(int square, std::pair<int, int>* snake) const;
    int LastSquare() const;
private:
    static std::pair<int, int> CreateSnake(int lowestSquareForSnakeHead, int highestSquareForSnakeHead);
    static std::map<int, int> MakeSnakes(int sizeOfOneSide);
    int m_LastSquare;
    std::map <int, int> m_Snakes;
};
}
