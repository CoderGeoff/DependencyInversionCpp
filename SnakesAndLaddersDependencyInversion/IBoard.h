#pragma once
#include <utility>

class IBoard
{
public:
    virtual ~IBoard() = 0 {};
    virtual int TryGetSnakeWithHeadAt(int square, std::pair<int, int>* snake) const = 0;
    virtual int LastSquare() const = 0;
};

