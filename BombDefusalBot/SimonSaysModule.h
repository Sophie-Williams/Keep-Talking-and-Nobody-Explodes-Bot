#include "Bomb.h"

class SimonSaysModule {
private:
    std::vector<std::string> colorSequence;
    std::string getSimonSaysColor(char color);

public:
    std::vector<std::string> solveSimonSaysModule(std::string color);
};
