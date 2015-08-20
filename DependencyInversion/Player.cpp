#include "stdafx.h"
#include "Player.h"
#include <string>

Player::Player(const std::string& name)
    : m_Name(name),
    m_CurrentSquare(0)
{
}

const std::string& Player::Name()
{
    return m_Name;
}

void Player::Square(int newPosition)
{
    m_CurrentSquare = newPosition;
}

int Player::Square() const
{
    return m_CurrentSquare;
}
