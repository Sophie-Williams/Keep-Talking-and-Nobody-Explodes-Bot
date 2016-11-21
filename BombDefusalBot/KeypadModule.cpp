#include "KeypadModule.h"

namespace Bomb
{
    const std::string KeypadModule::symbolsTable[6][7] = {
        { "oh", "tee", "lambda", "lightning", "kitty", "hotel", "backwardsee" },
        { "euro", "oh", "backwardsee", "quebec", "star", "hotel", "question" },
        { "copyright", "butt", "quebec", "doublepsi", "are", "lambda", "star" },
        { "sigma", "paragraph", "bee", "kitty", "doublepsi", "question", "smiley" },
        { "psi", "smiley", "bee", "see", "paragraph", "caterpillar", "star" },
        { "sigma", "euro", "tracks", "diphthong", "psi", "en", "omega" }
    };

    std::vector<std::string> KeypadModule::solveSymbolsModule(const std::vector<std::string> symbols) { // TODO: change to array?
        _ASSERT(symbols.size() == 4); // TODO: if changed to array, could guarantee size?
        //short circuit w/number

        int cols = (sizeof(symbolsTable[0]) / sizeof(symbolsTable[0][0]));
        int rows = (sizeof(symbolsTable) / cols); // TODO: define externally?

        int count = 0;
        std::vector<std::string> orderedSymbols(4);
        std::string checkSymbol;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                checkSymbol = symbolsTable[i][j];

                if (symbols[0] == checkSymbol) {
                    orderedSymbols[count] = symbols[0];
                    ++count;
                }
                else if (symbols[1] == checkSymbol) {
                    orderedSymbols[count] = symbols[1];
                    ++count;
                }
                else if (symbols[2] == checkSymbol) {
                    orderedSymbols[count] = symbols[2];
                    ++count;
                }
                else if (symbols[3] == checkSymbol) {
                    orderedSymbols[count] = symbols[3];
                    ++count;
                }
            }

            if (count == 4) {
                return orderedSymbols;
            }

            count = 0;
        }

        // This should be unreachable code indicating a parsing error
        _ASSERT(count != 0);

        return orderedSymbols;
    }
}
