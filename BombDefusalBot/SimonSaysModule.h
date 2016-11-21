#include "Bomb.h"

namespace Bomb
{
    class SimonSaysModule {
    private:
        std::string getSimonSaysColor(char color);

    public:
        std::vector<std::string> solveSimonSaysModule(std::string color);
        void clear();
    };
}
