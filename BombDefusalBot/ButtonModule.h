#include "Bomb.h"

class ButtonModule {
private:
    static const std::string pressAndHold;// = "press and hold";
    static const std::string pressAndRelease;// = "press and immediately release";

    bool checkLitIndicators(const std::string indicator);

public:
    std::string solveButtonModule(const std::string buttonColor, const std::string buttonText);
    int solveButtonModuleColorStrip(const std::string buttonColor);
};
