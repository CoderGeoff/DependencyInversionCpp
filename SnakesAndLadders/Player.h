#pragma once
#include <string>

namespace WithoutDependencyInversion {
class Player
{
    std::string m_Name;
    int m_CurrentSquare;
public:
    explicit Player(const std::string& name);
    const std::string& Name();
    void Square(int newPosition);
    int Square() const;
};
}
