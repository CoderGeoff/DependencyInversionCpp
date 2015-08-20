#pragma once
#include "Exports.h"
#include <string>
#include <vector>
#include <memory>
class ISnakesAndLadders;

class DEPENDENCYINVERSION_API SnakesAndLaddersFactory
{
public:
    SnakesAndLaddersFactory() = delete;
    static std::unique_ptr<ISnakesAndLadders> Create(std::vector<std::string> players);
};

