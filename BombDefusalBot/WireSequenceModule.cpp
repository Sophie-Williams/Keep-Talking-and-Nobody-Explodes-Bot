#include "WireSequenceModule.h"

namespace Bomb
{
    unsigned short A = 0x4, B = 0x2, C = 0x1;
    unsigned short WireSequenceModule::redCount = 0, WireSequenceModule::blueCount = 0, WireSequenceModule::blackCount = 0;
    unsigned short WireSequenceModule::redCuts[9]{ C, B, A, (unsigned short)(A | C), B, (unsigned short)(A | C), (unsigned short)(A | B | C), (unsigned short)(A | B), B };
    unsigned short WireSequenceModule::blueCuts[9]{ B, (unsigned short)(A | C), B, A, B, (unsigned short)(B | C), C, (unsigned short)(A | C), A };
    unsigned short WireSequenceModule::blackCuts[9]{ (unsigned short)(A | B | C), (unsigned short)(A | C), B, (unsigned short)(A | C), B, (unsigned short)(B | C), (unsigned short)(A | B), C, C };

    std::vector<bool> WireSequenceModule::solveWireSequenceModule(const std::vector<std::string> wireColors, const std::vector<std::string> unparsedWireEndpoints) {
        _ASSERT(wireColors.size() == unparsedWireEndpoints.size());

        std::vector<unsigned short> parsedWireEndpoints = parseWireSequenceConnections(unparsedWireEndpoints);
        std::vector<bool> wiresToCut;
        for (size_t i = 0; i < wireColors.size(); ++i) {
            if (wireColors[i] == "red") {
                if (redCuts[redCount] & parsedWireEndpoints[i]) {
                    wiresToCut.push_back(true);
                }
                else {
                    wiresToCut.push_back(false);
                }

                ++redCount;
            }
            else if (wireColors[i] == "blue") {
                if (blueCuts[blueCount] & parsedWireEndpoints[i]) {
                    wiresToCut.push_back(true);
                }
                else {
                    wiresToCut.push_back(false);
                }

                ++blueCount;
            }
            else if (wireColors[i] == "black") {
                if (blackCuts[blackCount] & parsedWireEndpoints[i]) {
                    wiresToCut.push_back(true);
                }
                else {
                    wiresToCut.push_back(false);
                }

                ++blackCount;
            }
        }

        return wiresToCut;
    }

    std::vector<unsigned short> WireSequenceModule::parseWireSequenceConnections(const std::vector<std::string> unparsedWireEndpoints) {
        std::vector<unsigned short> parsedWireEndpoints;
        for (std::string connection : unparsedWireEndpoints) {
            if (connection == "a") {
                parsedWireEndpoints.push_back(A);
            }
            else if (connection == "b") {
                parsedWireEndpoints.push_back(B);
            }
            else if (connection == "c") {
                parsedWireEndpoints.push_back(C);
            }
            else if (connection == "ab") {
                parsedWireEndpoints.push_back(A | B);
            }
            else if (connection == "ac") {
                parsedWireEndpoints.push_back(A | C);
            }
            else if (connection == "bc") {
                parsedWireEndpoints.push_back(B | C);
            }
            else if (connection == "abc") {
                parsedWireEndpoints.push_back(A | B | C);
            }
            else {
                // This should be unreachable code indicating a parsing error
                _ASSERT(false);
            }
        }

        _ASSERT(parsedWireEndpoints.size() == unparsedWireEndpoints.size());

        return parsedWireEndpoints;
    }

    void WireSequenceModule::reset() {
        redCount = 0;
        blueCount = 0;
        blackCount = 0;
    }
}