#pragma once
#include "IUserInterface.h"
class ConsoleUserInterface : public IUserInterface
{
public:
    virtual void AnnounceStart() override;
    virtual void AnnounceNextPlayer(const std::string& string) override;
    virtual void AnnounceRollOfTheDie(const std::string& name, int roll) override;
    virtual void AnnounceOvershoot(const std::string& name) override;
    virtual void AnnounceNewPosition(const std::string& name, int newPosition) override;
    virtual void AnnounceLandedOnSnake(const std::string& name) override;
    virtual void AnnounceWonGame(const std::string& name) override;
    void PrintMoving(int count);
};

