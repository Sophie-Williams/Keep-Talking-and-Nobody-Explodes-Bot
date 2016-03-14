#include "ButtonModule.h"

const std::string ButtonModule::pressAndHold = "press and hold";
const std::string ButtonModule::pressAndRelease = "press and immediately release";

bool ButtonModule::checkLitIndicators(const std::string indicator) {
    for (size_t i = 0; i < _litIndicators.size(); ++i) {
        if (indicator == _litIndicators[i]) {
            return true;
        }
    }

    return false;
}

std::string ButtonModule::solveButtonModule(const std::string buttonColor, const std::string buttonText) {
    if ((buttonColor == "blue") && (buttonText == "abort")) {
        return pressAndHold;
    }

    if ((_batteries > 1) && (buttonText == "detonate")) {
        return pressAndRelease;
    }

    if ((buttonColor == "white") && checkLitIndicators("CAR")) {
        return pressAndHold;
    }

    if (buttonColor == "yellow") {
        return pressAndHold;
    }

    if ((buttonColor == "red") && (buttonText == "hold")) {
        return pressAndRelease;
    }

    return pressAndHold;
}

int ButtonModule::solveButtonModuleColorStrip(const std::string buttonColor) {
    if (buttonColor == "blue") {
        return 4;
    }
    
    if (buttonColor == "yellow") {
        return 5;
    }

    return 1;
}
