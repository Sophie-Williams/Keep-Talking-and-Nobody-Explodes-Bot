#include "Bomb.h"

class SimonSaysModule {
private:
    std::vector<std::string> colorSequence;

    std::vector<std::string> SimonSaysModule::solveSimonSaysModuleIncrement(std::string responseColor);
    std::string getSimonSaysColor(char color);

public:
    std::string solveSimonSaysModule(std::string color, bool increment);
};
