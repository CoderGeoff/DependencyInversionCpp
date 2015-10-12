#pragma once
namespace WithoutDependencyInversion {
class ISnakesAndLadders
{
public:
    virtual ~ISnakesAndLadders() {};
    virtual void Play() = 0;
    virtual bool IsFinished() const = 0;
};
}
