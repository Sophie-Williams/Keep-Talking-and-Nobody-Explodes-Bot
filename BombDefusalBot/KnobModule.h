#include "Bomb.h"

namespace Bomb
{
    class KnobModule {
    private:
        const std::unordered_map<std::string, std::string> ledConfigurationsToKnobPositions = {
            { "001011111101", "up" }, { "101010011011", "up" }, { "011001111101", "down" },{ "101010010001", "down" },
            { "000010100111", "left" }, { "000010000110", "left" }, { "101111111010", "right" }, { "101100111010", "right" }
        };

    public:
        std::string KnobModule::solveKnobModule(const std::string ledConfiguration);
    };
}
