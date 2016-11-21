#include "ComplicatedWiresModule.h"

namespace Bomb
{
    std::vector<bool> ComplicatedWiresModule::solveComplicatedWiresModule(const std::vector<std::string> unparsedWires) {
        _ASSERT((unparsedWires.size() >= 1) && (unparsedWires.size() <= 6));

        std::vector<ComplicatedWire> wires = parseWires(unparsedWires);
        bool parallel = _existingPorts[1];
        std::vector<bool> cutIndicators;
        for (ComplicatedWire wire : wires)
        {
            if (wire.led) {
                if (wire.color == "blue") {
                    if (parallel) {
                        cutIndicators.push_back(true);
                    }
                    else {
                        cutIndicators.push_back(false);
                    }
                }
                else if (wire.color == "redblue") {
                    if (wire.star) {
                        cutIndicators.push_back(false);
                    }
                    else if (!_lastSerialDigitOdd) {
                        cutIndicators.push_back(true);
                    }
                    else {
                        cutIndicators.push_back(false);
                    }
                }
                else if (_batteries > 1) {
                    if ((wire.color == "red") || wire.star) {
                        cutIndicators.push_back(true);
                    }
                    else {
                        cutIndicators.push_back(false);
                    }
                }
                else {
                    cutIndicators.push_back(false);
                }
            }
            else if (wire.star) {
                if ((wire.color == "red") || (wire.color == "white")) {
                    cutIndicators.push_back(true);
                }
                else if (wire.color == "redblue") {
                    if (parallel) {
                        cutIndicators.push_back(true);
                    }
                    else {
                        cutIndicators.push_back(false);
                    }
                }
                else {
                    cutIndicators.push_back(false);
                }
            }
            else if (wire.color == "white") {
                cutIndicators.push_back(true);
            }
            else if (!_lastSerialDigitOdd) {
                cutIndicators.push_back(true);
            }
            else {
                cutIndicators.push_back(false);
            }
        }

        _ASSERT(cutIndicators.size() >= 0);
        return cutIndicators;
    }

    std::vector<ComplicatedWiresModule::ComplicatedWire> ComplicatedWiresModule::parseWires(const std::vector<std::string> wires) {
        _ASSERT((wires.size() >= 1) && (wires.size() <= 6));

        std::vector<ComplicatedWire> parsedWires;
        for (std::string wire : wires) {
            std::vector<std::string> wireComponents;
            split(wire, wireComponents, ',');

            ComplicatedWire result;
            result.led = (wireComponents[0] == "led");
            result.color = wireComponents[1]; // TODO: how to parse "redblue" and how to parse null options instead of all options
            result.star = (wireComponents[2] == "star");

            parsedWires.push_back(result);
        }

        _ASSERT(parsedWires.size() == wires.size());
        return parsedWires;
    }
}
