#pragma once
#include "Exports.h"
#include <string>
#include <vector>
#include <memory>

namespace WithoutDependencyInversion {
class ISnakesAndLadders;

class SNAKESANDLADDERS_API SnakesAndLaddersFactory
{
public:
    SnakesAndLaddersFactory() = delete;
    static std::unique_ptr<ISnakesAndLadders> Create(std::vector<std::string> players);
};
}
