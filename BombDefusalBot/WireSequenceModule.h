#include "Bomb.h"

namespace Bomb
{
    class WireSequenceModule {
    private:
        static unsigned short redCount, blueCount, blackCount;
        static unsigned short redCuts[9];
        static unsigned short blueCuts[9];
        static unsigned short blackCuts[9];

        std::vector<unsigned short> parseWireSequenceConnections(const std::vector<std::string> unparsedWireEndpoints);

    public:
        std::vector<bool> solveWireSequenceModule(const std::vector<std::string> wireColors, const std::vector<std::string> unparsedWireEndpoints);
        void reset();
    };
}