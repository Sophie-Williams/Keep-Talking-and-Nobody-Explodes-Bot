#include "KnobModule.h"

namespace Bomb
{
    std::string KnobModule::solveKnobModule(std::string ledConfiguration) {
        _ASSERT((ledConfiguration.size() == 6) || (ledConfiguration.size() == 12));

        if (ledConfiguration.length() == 6) {
            std::string topTest = ledConfiguration.substr(0, 3);
            std::string bottomTest = ledConfiguration.substr(3, 3);

            std::string key;
            for (auto kv : ledConfigurationsToKnobPositions) {
                key = kv.first;

                if ((key.substr(3, 3) == topTest) && (key.substr(9, 3) == bottomTest)) {
                    return kv.second;
                }
            }
        }

        else if (ledConfiguration.length() == 12) {
            if (ledConfigurationsToKnobPositions.find(ledConfiguration) != ledConfigurationsToKnobPositions.end()) {
                return ledConfigurationsToKnobPositions.at(ledConfiguration);
            }
        }

        // This should be unreachable code indicating a parsing error
        _ASSERT(false);

        return "error";
    }
}
