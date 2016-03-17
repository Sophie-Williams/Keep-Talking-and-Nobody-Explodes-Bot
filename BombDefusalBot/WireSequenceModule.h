#include "Bomb.h"

class WireSequenceModule {
private:
    static unsigned short int redCount, blueCount, blackCount;
    static unsigned short redCuts[9];
    static unsigned short blueCuts[9];
    static unsigned short blackCuts[9];

    std::vector<unsigned short> parseWireSequenceConnections(const std::vector<std::string> unparsedConnections);

public:
    std::vector<bool> solveWireSequenceModule(const std::vector<std::string> wires, const std::vector<std::string> unparsedConnections);
};
