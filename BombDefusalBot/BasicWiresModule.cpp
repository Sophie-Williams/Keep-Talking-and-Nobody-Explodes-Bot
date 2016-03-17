#include "BasicWiresModule.h"

std::string BasicWiresModule::solveBasicWiresModule(const std::vector<std::string> wires) {
    int numberOfWires = wires.size();

    _ASSERT((numberOfWires >= 3) && (numberOfWires <= 6));

    switch (numberOfWires) {
    case 3:
        if (countWiresOfColor(wires, "red") == 0) {
            return "second";
        }

        if (wires[(numberOfWires - 1)] == "white") {
            return "last";
        }

        if (countWiresOfColor(wires, "blue") > 1) {
            return "last blue";
        }

        return "last";
    case 4:
        if ((countWiresOfColor(wires, "red") > 1) && lastSerialDigitIsOdd) {
            return "last red";
        }

        if ((wires[(numberOfWires - 1)] == "yellow") && (countWiresOfColor(wires, "red") == 0)) {
            return "first";
        }

        if (countWiresOfColor(wires, "blue") == 1) {
            return "first";
        }

        if (countWiresOfColor(wires, "yellow") > 1) {
            return "last";
        }

        return "second";
    case 5:
        if ((wires[(numberOfWires - 1)] == "black") && lastSerialDigitIsOdd) {
            return "fourth";
        }

        if ((countWiresOfColor(wires, "red") == 1) && countWiresOfColor(wires, "yellow") > 1) {
            return "first";
        }

        if (countWiresOfColor(wires, "black") == 0) {
            return "second";
        }

        return "first";
    case 6:
        if ((countWiresOfColor(wires, "yellow") == 0) && lastSerialDigitIsOdd) {
            return "third";
        }

        if ((countWiresOfColor(wires, "yellow") == 1) && (countWiresOfColor(wires, "white") > 1)) {
            return "fourth";
        }

        if (countWiresOfColor(wires, "red") == 0) {
            return "last";
        }

        return "fourth";
    }

    // This should be unreachable code indicating a parsing error
    _ASSERT(false);

    return "error";
}

int BasicWiresModule::countWiresOfColor(const std::vector<std::string> wires, const std::string color) {
    int count = 0;

    for (size_t i = 0; i < wires.size(); ++i) {
        if (wires[i] == color) {
            ++count;
        }
    }

    return count;
}
