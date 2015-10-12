#pragma once
namespace DependencyInversion {
class ISnakesAndLadders
{
public:
    virtual void Play() = 0;
    virtual ~ISnakesAndLadders() = 0 {}
};
}
