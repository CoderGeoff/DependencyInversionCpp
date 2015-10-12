#pragma once
#include "Exports.h"
#include <string>
#include <vector>
#include <memory>

namespace DependencyInversion {

class ISnakesAndLadders;

class SNAKESANDLADDERSDEPENDENCYINVERSION_API SnakesAndLaddersFactory
{
public:
    SnakesAndLaddersFactory() = delete;
    static std::unique_ptr<ISnakesAndLadders> Create(std::vector<std::string> players);
};
}
