#include "WireSequenceModule.h"

unsigned short int A = 0x4, B = 0x2, C = 0x1;
unsigned short WireSequenceModule::redCount = 0, WireSequenceModule::blueCount = 0, WireSequenceModule::blackCount = 0;
unsigned short WireSequenceModule::redCuts[9] { C, B, A, A | C, B, A | C, A | B | C, A | B, B };
unsigned short WireSequenceModule::blueCuts[9] { B, A | C, B, A, B, B | C, C, A | C, A };
unsigned short WireSequenceModule::blackCuts[9]{ A | B | C, A | C, B, A | C, B, B | C, A | B, C, C };

std::vector<bool> WireSequenceModule::solveWireSequenceModule(const std::vector<std::string> wires, const std::vector<std::string> unparsedConnections) {
    _ASSERT(wires.size() == unparsedConnections.size());

    std::vector<unsigned short> parsedConnections = parseWireSequenceConnections(unparsedConnections);
    std::vector<bool> wiresToCut;
    for (size_t i = 0; i < wires.size(); ++i) {
        if (wires[i] == "red") {
            if (redCuts[redCount] & parsedConnections[i]) {
                wiresToCut.push_back(true);
            }
            else {
                wiresToCut.push_back(false);
            }

            ++redCount;
        }
        else if (wires[i] == "blue") {
            if (blueCuts[blueCount] & parsedConnections[i]) {
                wiresToCut.push_back(true);
            }
            else {
                wiresToCut.push_back(false);
            }

            ++blueCount;
        }
        else if (wires[i] == "black") {
            if (blackCuts[blackCount] & parsedConnections[i]) {
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

std::vector<unsigned short> WireSequenceModule::parseWireSequenceConnections(const std::vector<std::string> unparsedConnections) {
    std::vector<unsigned short> parsedConnections;
    for (std::string connection : unparsedConnections) {
        if (connection == "a") {
            parsedConnections.push_back(A);
        }
        else if (connection == "b") {
            parsedConnections.push_back(B);
        }
        else if (connection == "c") {
            parsedConnections.push_back(C);
        }
        else if (connection == "ab") {
            parsedConnections.push_back(A | B);
        }
        else if (connection == "ac") {
            parsedConnections.push_back(A | C);
        }
        else if (connection == "bc") {
            parsedConnections.push_back(B | C);
        }
        else if (connection == "abc") {
            parsedConnections.push_back(A | B | C);
        }
        else {
            // This should be unreachable code indicating a parsing error
            _ASSERT(false);
        }
    }

    _ASSERT(parsedConnections.size() == unparsedConnections.size());

    return parsedConnections;
}
