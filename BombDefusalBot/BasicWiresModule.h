#include "Bomb.h"

namespace Bomb
{
    class BasicWiresModule {
    private:
        int countWiresOfColor(const std::vector<std::string> wires, const std::string color);

    public:
        std::string solveBasicWiresModule(const std::vector<std::string> wires);
    };
}