#pragma once
#include <string>

class IUserInterface
{
public:
    virtual ~IUserInterface() = 0 {}

    virtual void AnnounceStart() = 0;
    virtual void AnnounceNextPlayer(const std::string& string) = 0;
    virtual void AnnounceRollOfTheDie(const std::string& name, int roll) = 0;
    virtual void AnnounceOvershoot(const std::string& name) = 0;
    virtual void AnnounceNewPosition(const std::string& name, int newPosition) = 0;
    virtual void AnnounceLandedOnSnake(const std::string& name) = 0;
    virtual void AnnounceWonGame(const std::string& name) = 0;
};

