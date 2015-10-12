#pragma once
#include <utility>

namespace DependencyInversion {
class IBoard
{
public:
    virtual ~IBoard() = 0 {};
    virtual bool TryGetSnakeWithHeadAt(int square, std::pair<int, int>* snake) const = 0;
    virtual int LastSquare() const = 0;
};
}
