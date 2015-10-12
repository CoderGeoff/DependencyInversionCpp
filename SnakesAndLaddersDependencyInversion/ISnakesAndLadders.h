#pragma once
namespace DependencyInversion {
class ISnakesAndLadders
{
public:
    virtual ~ISnakesAndLadders() = 0 {}
    virtual void Play() = 0;
    virtual bool IsFinished() const = 0;
};
}
