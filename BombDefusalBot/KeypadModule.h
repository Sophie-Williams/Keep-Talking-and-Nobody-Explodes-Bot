#include "Bomb.h"

namespace Bomb
{
    class KeypadModule {
    private:
        static const std::string symbolsTable[6][7];

    public:
        std::vector<std::string> solveSymbolsModule(const std::vector<std::string> symbols);
    };
}